/**
 * \file            lwgsm_gnss.c
 * \brief           GNSS API
 */

#include "lwgsm/lwgsm_private.h"
#include "lwgsm/lwgsm_gnss.h"
#include "lwgsm/lwgsm_mem.h"

#define LWGSM_GNSS_POWER_ON 1
#define LWGSM_GNSS_POWER_OFF 0

#if LWGSM_CFG_GNSS || __DOXYGEN__
lwgsmr_t
lwgsm_gnss_power_on(const uint32_t baudrate, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
                    const uint32_t blocking) {
    LWGSM_MSG_VAR_DEFINE(msg);

    LWGSM_MSG_VAR_ALLOC(msg, blocking);
    LWGSM_MSG_VAR_SET_EVT(msg, evt_fn, evt_arg);
    LWGSM_MSG_VAR_REF(msg).cmd_def = LWGSM_CMD_GNSS_ENABLE;
    LWGSM_MSG_VAR_REF(msg).cmd = LWGSM_CMD_CGNSPWR;
    LWGSM_MSG_VAR_REF(msg).msg.gnss.power = LWGSM_GNSS_POWER_ON;
    LWGSM_MSG_VAR_REF(msg).msg.gnss.baudrate = baudrate;

    return lwgsmi_send_msg_to_producer_mbox(&LWGSM_MSG_VAR_REF(msg), lwgsmi_initiate_cmd, 10000);
}

lwgsmr_t
lwgsm_gnss_ipr_set(const uint32_t baudrate, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
                   const uint32_t blocking) {
    LWGSM_MSG_VAR_DEFINE(msg);

    LWGSM_MSG_VAR_ALLOC(msg, blocking);
    LWGSM_MSG_VAR_SET_EVT(msg, evt_fn, evt_arg);
    LWGSM_MSG_VAR_REF(msg).cmd_def = LWGSM_CMD_CGNSIPR_SET;
    LWGSM_MSG_VAR_REF(msg).msg.gnss.baudrate = baudrate;

    return lwgsmi_send_msg_to_producer_mbox(&LWGSM_MSG_VAR_REF(msg), lwgsmi_initiate_cmd, 10000);
}

lwgsmr_t
lwgsm_gnss_get_info(const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking) {
    LWGSM_MSG_VAR_DEFINE(msg);

    LWGSM_MSG_VAR_ALLOC(msg, blocking);
    LWGSM_MSG_VAR_SET_EVT(msg, evt_fn, evt_arg);
    LWGSM_MSG_VAR_REF(msg).cmd_def = LWGSM_CMD_CGNSINF_GET;

    return lwgsmi_send_msg_to_producer_mbox(&LWGSM_MSG_VAR_REF(msg), lwgsmi_initiate_cmd, 10000);
}

lwgsmr_t
lwgsm_gnss_set_urc(const uint8_t interval, const lwgsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
                   const uint32_t blocking) {
    LWGSM_MSG_VAR_DEFINE(msg);

    LWGSM_MSG_VAR_ALLOC(msg, blocking);
    LWGSM_MSG_VAR_SET_EVT(msg, evt_fn, evt_arg);
    LWGSM_MSG_VAR_REF(msg).cmd_def = LWGSM_CMD_GNSS_URC;
    LWGSM_MSG_VAR_REF(msg).cmd = LWGSM_CMD_CGNSURC;
    LWGSM_MSG_VAR_REF(msg).msg.gnss.urc_interval = interval;

    return lwgsmi_send_msg_to_producer_mbox(&LWGSM_MSG_VAR_REF(msg), lwgsmi_initiate_cmd, 10000);
}

#endif /* LWGSM_CFG_SMS || __DOXYGEN__ */