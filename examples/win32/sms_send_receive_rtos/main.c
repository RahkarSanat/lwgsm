/**
 * \file            main.c
 * \brief           Main file
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
 * Before you start using WIN32 implementation with USB and VCP,
 * check lwgsm_ll_win32.c implementation and choose your COM port!
 */
#include "lwgsm/lwgsm.h"
#include "sim_manager.h"
#include "network_utils.h"
#include "sms_send_receive.h"

static lwgsmr_t lwgsm_callback_func(lwgsm_evt_t* evt);

/**
 * \brief           Program entry point
 */
int
main(void) {
    printf("Starting GSM application!\r\n");

    /* Initialize GSM with default callback function */
    if (lwgsm_init(lwgsm_callback_func, 1) != lwgsmOK) {
        printf("Cannot initialize LwGSM\r\n");
    }

    /* Configure device by unlocking SIM card */
    if (configure_sim_card()) {
        printf("SIM card configured. Adding delay to stabilize SIM card.\r\n");
        lwgsm_delay(10000);
    } else {
        printf("Cannot configure SIM card! Is it inserted, pin valid and not under PUK? Closing down...\r\n");
        while (1) { lwgsm_delay(1000); }
    }

    /* Start SMS send receive example */
    sms_send_receive_start();

    /*
     * Do not stop program here.
     * New threads were created for GSM processing
     */
    while (1) {
        lwgsm_delay(1000);
    }

    return 0;
}

/**
 * \brief           Event callback function for GSM stack
 * \param[in]       evt: Event information with data
 * \return          \ref lwgsmOK on success, member of \ref lwgsmr_t otherwise
 */
static lwgsmr_t
lwgsm_callback_func(lwgsm_evt_t* evt) {
    switch (lwgsm_evt_get_type(evt)) {
        case LWGSM_EVT_INIT_FINISH: printf("Library initialized!\r\n"); break;
        /* Process and print registration change */
        case LWGSM_EVT_NETWORK_REG_CHANGED: network_utils_process_reg_change(evt); break;
        /* Process current network operator */
        case LWGSM_EVT_NETWORK_OPERATOR_CURRENT: network_utils_process_curr_operator(evt); break;
        /* Process signal strength */
        case LWGSM_EVT_SIGNAL_STRENGTH: network_utils_process_rssi(evt); break;

        /* Other user events here... */

        default: break;
    }
    return lwgsmOK;
}
