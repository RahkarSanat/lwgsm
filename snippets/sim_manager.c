#include "sim_manager.h"
#include "lwgsm/lwgsm.h"

/**
 * \brief           SIM card pin code
 */
static const char* pin_code = "7958";

/**
 * \brief           SIM card puk code
 */
static const char* puk_code = "10663647";

/**
 * \brief           Configure and enable SIM card
 * \return          `1` on success, `0` otherwise
 */
uint8_t
configure_sim_card(void) {
    LWGSM_UNUSED(puk_code);
    if (pin_code != NULL && strlen(pin_code)) {
        if (lwgsm_sim_pin_enter(pin_code, NULL, NULL, 1) == lwgsmOK) {
            return 1;
        }
        return 0;
    }
    return 1;
}
