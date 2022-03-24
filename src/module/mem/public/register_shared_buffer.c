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
#include <module/mem/_private/_mem.h>

void napc_mem_registerSharedBuffer(
	const char *label, void *buffer, napc_size buffer_size
) {
	napc_size max_slots       = NAPC_ARRAY_ELEMENTS(PV_napc_mem_shared_buffer_slots);
	napc_size available_slots = max_slots - PV_napc_mem_countSharedBufferSlots();

	if (!available_slots) {
		NAPC_PANIC(
			"Cannot register another shared buffer, slots are full."
			" Maximum is %" NAPC_SIZE_PRINTF,
			max_slots
		);
	}

	// check for name duplicates
	if (PV_napc_mem_getSharedBufferByLabel(label)) {
		NAPC_PANIC(
			"There is already a shared buffer with the label '%s'.",
			label
		);
	}

	bool inserted = false;

	for (napc_size i = 0; i < max_slots; ++i) {
		PV_napc__MemSharedBuffer *e = &PV_napc_mem_shared_buffer_slots[i];

		// Initialize first uninitialized entry
		if (!e->label) {
			e->label = label;
			napc_Buffer_init(&e->buffer, buffer, buffer_size);
			e->available = true;

			inserted = true;

			break;
		}
	}

	NAPC_ASSERT(inserted);
}
