/**
 * FreeRDP: A Remote Desktop Protocol Client
 * GDI Unit Tests
 *
 * Copyright 2010 Marc-Andre Moreau <marcandre.moreau@gmail.com>
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

#include "test_freerdp.h"

int init_gdi_suite(void);
int clean_gdi_suite(void);
int add_gdi_suite(void);

void test_gdi_GetDC(void);
void test_gdi_CreateCompatibleDC(void);
void test_gdi_CreateBitmap(void);
void test_gdi_CreateCompatibleBitmap(void);
void test_gdi_CreatePen(void);
void test_gdi_CreateSolidBrush(void);
void test_gdi_CreatePatternBrush(void);
void test_gdi_CreateRectRgn(void);
void test_gdi_CreateRect(void);
void test_gdi_GetPixel(void);
void test_gdi_SetPixel(void);
void test_gdi_SetROP2(void);
void test_gdi_MoveToEx(void);
void test_gdi_LineTo(void);
void test_gdi_Ellipse(void);
void test_gdi_PtInRect(void);
void test_gdi_FillRect(void);
void test_gdi_BitBlt_32bpp(void);
void test_gdi_BitBlt_16bpp(void);
void test_gdi_BitBlt_8bpp(void);
void test_gdi_ClipCoords(void);
void test_gdi_InvalidateRegion(void);
/* Modeline for vim. Don't delete */
/* vim: set cindent:noet:sw=8:ts=8 */
