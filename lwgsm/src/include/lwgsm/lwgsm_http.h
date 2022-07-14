/**
 * \file            lwgsm_http.h
 * \brief           HTTP API
 */

/*
 * Copyright (c) 2022 Tilen MAJERLE
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of LwGSM - Lightweight GSM-AT library.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 * Version:         v0.1.1
 */
#ifndef LWGSM_HDR_HTTP_H
#define LWGSM_HDR_HTTP_H

#include "lwgsm/lwgsm.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \ingroup         LWGSM
 * \defgroup        LWGSM_HTTP Hyper Text Transfer Protocol
 * \brief           Hyper Text Transfer Protocol (HTTP) manager
 * \{
 *
 * Currently it is under development
 *
 */
lwgsmr_t lwgsm_http_enable_gprs(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// INITILAIZE function
lwgsmr_t lwgsm_http_init(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// Terminate function
lwgsmr_t lwgsm_http_terminate(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// Set Parameter Data
lwgsmr_t lwgsm_http_set_parameter(const char* key, const char* value, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
                                  const uint32_t blocking);

// Read Parameter Data
lwgsmr_t lwgsm_http_read_parameter(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// Set HTTP method
lwgsmr_t lwgsm_http_set_method(uint8_t method, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// Set Data
lwgsmr_t lwgsm_http_set_data(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// Read HTTP Response
lwgsmr_t lwgsm_http_read_response(uint8_t* buf, size_t start, size_t end, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
                                  const uint32_t blocking);

// Save Context
lwgsmr_t lwgsm_http_save_context(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// Read HTTP Status
lwgsmr_t lwgsm_http_status(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

// Read HTTP Header information
lwgsmr_t lwgsm_http_response_header_info(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

lwgsmr_t lwgsm_sapbr_enable_gprs(uint8_t cid, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

lwgsmr_t lwgsm_sapbr_set_param(uint8_t cid, const char* tag, const char* value, const lwgsm_api_cmd_evt_fn evt_fn,
                               void* const evt_arg, const uint32_t blocking);

lwgsmr_t lwgsm_sapbr(uint8_t cid, lwgsm_sapbr_cmd_type_t cmd_type, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
                     const uint32_t blocking);

/**
 * \}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWGSM_HDR_HTTP_H */
