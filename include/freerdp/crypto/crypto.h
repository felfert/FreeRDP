/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Cryptographic Abstraction Layer
 *
 * Copyright 2011-2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_CRYPTO_H
#define FREERDP_CRYPTO_H

/* OpenSSL includes windows.h */
#include <winpr/windows.h>

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rc4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/bn.h>
#include <openssl/x509v3.h>
#include <openssl/rand.h>

#if defined(OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x0090800f)
#define D2I_X509_CONST const
#else
#define D2I_X509_CONST
#endif

#define EXPONENT_MAX_SIZE			4
#define MODULUS_MAX_SIZE			256

#include <freerdp/api.h>
#include <freerdp/freerdp.h>
#include <freerdp/utils/blob.h>
#include <freerdp/utils/memory.h>

struct crypto_sha1_struct
{
	SHA_CTX sha_ctx;
};

struct crypto_md5_struct
{
	MD5_CTX md5_ctx;
};

struct crypto_rc4_struct
{
	RC4_KEY rc4_key;
};

struct crypto_des3_struct
{
	EVP_CIPHER_CTX des3_ctx;
};

struct crypto_hmac_struct
{
	HMAC_CTX hmac_ctx;
};

struct crypto_cert_struct
{
	X509 * px509;
};

#define	CRYPTO_SHA1_DIGEST_LENGTH	SHA_DIGEST_LENGTH
typedef struct crypto_sha1_struct* CryptoSha1;

FREERDP_API CryptoSha1 crypto_sha1_init(void);
FREERDP_API void crypto_sha1_update(CryptoSha1 sha1, const uint8* data, uint32 length);
FREERDP_API void crypto_sha1_final(CryptoSha1 sha1, uint8* out_data);

#define	CRYPTO_MD5_DIGEST_LENGTH	MD5_DIGEST_LENGTH
typedef struct crypto_md5_struct* CryptoMd5;

FREERDP_API CryptoMd5 crypto_md5_init(void);
FREERDP_API void crypto_md5_update(CryptoMd5 md5, const uint8* data, uint32 length);
FREERDP_API void crypto_md5_final(CryptoMd5 md5, uint8* out_data);

typedef struct crypto_rc4_struct* CryptoRc4;

FREERDP_API CryptoRc4 crypto_rc4_init(const uint8* key, uint32 length);
FREERDP_API void crypto_rc4(CryptoRc4 rc4, uint32 length, const uint8* in_data, uint8* out_data);
FREERDP_API void crypto_rc4_free(CryptoRc4 rc4);

typedef struct crypto_des3_struct* CryptoDes3;

FREERDP_API CryptoDes3 crypto_des3_encrypt_init(const uint8* key, const uint8* ivec);
FREERDP_API CryptoDes3 crypto_des3_decrypt_init(const uint8* key, const uint8* ivec);
FREERDP_API void crypto_des3_encrypt(CryptoDes3 des3, uint32 length, const uint8 *in_data, uint8 *out_data);
FREERDP_API void crypto_des3_decrypt(CryptoDes3 des3, uint32 length, const uint8 *in_data, uint8* out_data);
FREERDP_API void crypto_des3_free(CryptoDes3 des3);

typedef struct crypto_hmac_struct* CryptoHmac;

FREERDP_API CryptoHmac crypto_hmac_new(void);
FREERDP_API void crypto_hmac_sha1_init(CryptoHmac hmac, const uint8 *data, uint32 length);
FREERDP_API void crypto_hmac_update(CryptoHmac hmac, const uint8 *data, uint32 length);
FREERDP_API void crypto_hmac_final(CryptoHmac hmac, uint8 *out_data, uint32 length);
FREERDP_API void crypto_hmac_free(CryptoHmac hmac);

typedef struct crypto_cert_struct* CryptoCert;

#include <freerdp/crypto/certificate.h>

FREERDP_API CryptoCert crypto_cert_read(uint8* data, uint32 length);
FREERDP_API char* crypto_cert_fingerprint(X509* xcert);
FREERDP_API char* crypto_cert_subject(X509* xcert);
FREERDP_API char* crypto_cert_subject_common_name(X509* xcert, int* length);
FREERDP_API char** crypto_cert_subject_alt_name(X509* xcert, int* count, int** lengths);
FREERDP_API char* crypto_cert_issuer(X509* xcert);
FREERDP_API void crypto_cert_print_info(X509* xcert);
FREERDP_API void crypto_cert_free(CryptoCert cert);

FREERDP_API boolean x509_verify_certificate(CryptoCert cert, char* certificate_store_path);
FREERDP_API rdpCertificateData* crypto_get_certificate_data(X509* xcert, char* hostname);
FREERDP_API boolean crypto_cert_get_public_key(CryptoCert cert, rdpBlob* public_key);

#define	TSSK_KEY_LENGTH	64
extern const uint8 tssk_modulus[];
extern const uint8 tssk_privateExponent[];
extern const uint8 tssk_exponent[];

FREERDP_API void crypto_rsa_public_encrypt(const uint8* input, int length, uint32 key_length, const uint8* modulus, const uint8* exponent, uint8* output);
FREERDP_API void crypto_rsa_public_decrypt(const uint8* input, int length, uint32 key_length, const uint8* modulus, const uint8* exponent, uint8* output);
FREERDP_API void crypto_rsa_private_encrypt(const uint8* input, int length, uint32 key_length, const uint8* modulus, const uint8* private_exponent, uint8* output);
FREERDP_API void crypto_rsa_private_decrypt(const uint8* input, int length, uint32 key_length, const uint8* modulus, const uint8* private_exponent, uint8* output);
FREERDP_API void crypto_reverse(uint8* data, int length);
FREERDP_API void crypto_nonce(uint8* nonce, int size);

FREERDP_API char* crypto_base64_encode(uint8* data, int length);
FREERDP_API void crypto_base64_decode(uint8* enc_data, int length, uint8** dec_data, int* res_length);

#endif /* FREERDP_CRYPTO_H */
/* Modeline for vim. Don't delete */
/* vim: set cindent:noet:sw=8:ts=8 */
