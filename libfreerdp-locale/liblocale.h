/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * RDP Localization
 *
 * Copyright 2009-2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
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

#ifndef __LIBLOCALE_H
#define __LIBLOCALE_H

#include "config.h"
#include <freerdp/utils/debug.h>

#ifdef WITH_DEBUG_KBD
#define DEBUG_KBD(fmt, ...) DEBUG_CLASS(KBD, fmt, ## __VA_ARGS__)
#else
#define DEBUG_KBD(fmt, ...) DEBUG_NULL(fmt, ## __VA_ARGS__)
#endif

#endif /* __LIBLOCALE_H */
/* Modeline for vim. Don't delete */
/* vim: set cindent:noet:sw=8:ts=8 */
