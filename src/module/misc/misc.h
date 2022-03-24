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
#if !defined(NAPC_MODULE_MISC_h)
	#define NAPC_MODULE_MISC_h

	#include <libnapc.h>

	#include <string.h> // memcmp(), memcpy() etc.

	/*!
	 * @name napc_misc_shiftArrayRight
	 * @brief Shift elements in an array.
	 * @version 1.0.0
	 * @description
	 * Shift elements in `array` one element to the right discarding the last
	 * element in the array.
	 * @param array The array to be shifted.
	 * @param n_elements The number of elements in `array`.
	 * @param element_size The size (in bytes) of one element in `array`.
	 * @notes
	 * The contents of the first element in `array` will be undefined after this operation.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * int data[5] = {1, 2, 3, 4, 5};
	 * 
	 * napc_misc_shiftArrayRight(data, 5, sizeof(int));
	 * 
	 * // data[0] is now undefined
	 * // data[1] is now 1
	 * // data[2] is now 2
	 * // data[3] is now 3
	 * // data[4] is now 4
	 */
	void napc_misc_shiftArrayRight(
		void *array, napc_size n_elements, napc_size element_size
	);

	/**************************
	 * Memory fences
	 * To detect buffer over and underflows.
	 */
	void napc_misc_setMemoryFenceBytes(
		unsigned char *buffer, napc_size buffer_size,
		napc_size memory_fence_size, napc_u8 fence_value
	);

	bool napc_misc_verifyMemoryFenceBytes(
		unsigned char *buffer, napc_size buffer_size,
		napc_size memory_fence_size, napc_u8 fence_value
	);

	/**************************
	 * Chunks
	 */
	typedef napc_ssize (*napc_misc_ChunkedOperationCallback)(
		const void *data, napc_size data_size, void *context
	);

	/*!
	 * @name napc_misc_chunkedOperation
	 * @brief Perform an operation in chunks.
	 * @version 1.0.0
	 * @description
	 * Performs an operation in chunks.
	 * @param data Data to process.
	 * @param data_size Size of data to process.
	 * @param chunk_size Size of one chunk.
	 * @param fn Callback for processing one chunk.
	 * @param fn_context Optional context for `fn` callback.
	 * @return Returns `true` on success, `false` otherwise.
	 * @notes
	 * `fn` is a function with the following prototype:
	 * 
	 * `napc_ssize (const void *data, napc_size data_size, void *context)`
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_misc_chunkedOperation(
		const void *data, napc_size data_size, napc_size chunk_size,
		napc_misc_ChunkedOperationCallback fn, void *fn_context
	) NAPC_FN_WARNUNUSED_RET();
#endif
