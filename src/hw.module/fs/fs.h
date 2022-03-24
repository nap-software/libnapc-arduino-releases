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
#if !defined(NAPC_HW_MODULE_FS_h)
	#define NAPC_HW_MODULE_FS_h

	#include <libnapc.h>

	#include <module/buffer/buffer.h>

	/*!
	 * @name napc_fs_writeFile
	 * @brief Write data to a file.
	 * @version 1.0.0
	 * @description
	 * Writes data to a file overwriting its previous contents.
	 * @param path File path.
	 * @param buffer Buffer to write.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning This function will always overwrite the previous contents of the file.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_writeFile(
		const char *path, const void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_fs_writeFileCString
	 * @brief Write a string to a file.
	 * @version 1.0.0
	 * @description
	 * Writes a string to a file overwriting its previous contents.
	 * @param path File path.
	 * @param string String to write to file.
	 * @return Returns `true` on success, `false` otherwise.
	 * @warning This function will always overwrite the previous contents of the file.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_writeFileCString(
		const char *path, const char *string
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_fs_readFile
	 * @brief Read a file in its entirety.
	 * @version 1.0.0
	 * @description
	 * Reads the entire content of a file into a buffer.
	 * @param path File path.
	 * @param buffer Buffer to write to.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_readFile(
		const char *path, napc__Buffer *buffer
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_fs_readFileCString
	 * @brief Read a file in its entirety.
	 * @version 1.0.0
	 * @description
	 * Reads the entire content of a file into a NUL-terminated string.
	 * @param path File path.
	 * @param buffer Buffer to write to.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_fs_readFileCString(
		const char *path, char *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
