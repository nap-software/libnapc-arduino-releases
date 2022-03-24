/*
* MIT License
* 
* Copyright (c) 2022 nap.software
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#if !defined(PV_NAPC_MODULE_MEM_h)
	#define PV_NAPC_MODULE_MEM_h

	#include <module/mem/mem.h>
	#include <napc-utils/napc-utils.h>
	#include <napc-core/napc-core.h>

	typedef struct {
		const char *label;
		bool available;
		napc__Buffer buffer;
	} PV_napc__MemSharedBuffer;

	void PV_napc_mem_initSharedBufferSlots(void);

	napc_size PV_napc_mem_countSharedBufferSlots(void);

	PV_napc__MemSharedBuffer *PV_napc_mem_getSharedBufferByLabel(
		const char *label
	);

	extern PV_napc__MemSharedBuffer PV_napc_mem_shared_buffer_slots[5]; // @global
#endif
