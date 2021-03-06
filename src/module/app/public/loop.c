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
#include <module/app/_private/_app.h>

static bool _previous_link_status = false; // @static

bool napc_app_loop(napc_time uptime) NAPC_FN_WEAK();
bool napc_loop(napc_time uptime) NAPC_FN_WEAK();

bool napc_app_loop(napc_time uptime) {
	NAPC_IGNORE_VALUE(uptime);

	napc_printf("warning: napc_app_loop() is not defined.\n");

	return false;
}

bool napc_loop(napc_time uptime) {
	bool link_status = napc_eth_getLinkStatus();

	napc_random_collectBytes();

	if (link_status && !_previous_link_status) {
		PV_NAPC_APP_INFO("Ethernet is up.");
	}

	bool cont = napc_app_loop(uptime);

	/**
	 * Give application the chance to close all network sockets.
	 */
	if (!link_status && _previous_link_status) {
		PV_NAPC_APP_INFO("Ethernet is down.");

		napc_size open_sockets = napc_UDP_getNumOpenSockets();

		if (open_sockets) {
			NAPC_PANIC(
				"Ethernet is down but some UDP sockets (count=%" NAPC_SIZE_PRINTF ") are still open.",
				open_sockets
			);
		}
	}

	_previous_link_status = link_status;

	return cont;
}
