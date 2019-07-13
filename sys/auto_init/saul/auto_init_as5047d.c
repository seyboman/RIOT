/*
 * Copyright (C) 2019 Florian Seybold
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 */

/*
 * @ingroup     sys_auto_init_saul
 * @{
 *
 * @file
 * @brief       Auto initialization for AS5047D devices
 *
 * @author      Florian Seybold <florian@seybold.space>
 *
 * @}
 */

#ifdef MODULE_AS5047D

#include "assert.h"
#include "log.h"
#include "saul_reg.h"
#include "as5047d_params.h"

/**
 * @brief   Define the number of configured sensors
 */
#define AS5047D_NUM    (sizeof(as5047d_params) / sizeof(as5047d_params[0]))

/**
 * @brief   Allocate memory for the device descriptors
 */
static as5047d_t as5047d_devs[AS5047D_NUM];

/**
 * @brief   Memory for the SAUL registry entries
 */
static saul_reg_t saul_entries[AS5047D_NUM];

/**
 * @brief   Define the number of configured sensors
 */
#define AS5047D_INFO_NUM    (sizeof(as5047d_saul_info) / sizeof(as5047d_saul_info[0]))

/**
 * @brief   Reference the driver struct
 */
extern saul_driver_t as5047d_saul_driver;

void auto_init_as5047d(void)
{
    assert(AS5047D_NUM == AS5047D_INFO_NUM);
    for (unsigned i = 0; i < AS5047D_NUM; i++) {
        LOG_DEBUG("[auto_init_saul] initializing as5047d #%u\n", i);

        int res = as5047d_init(&as5047d_devs[i], &as5047d_params[i]);
        if (res != 0) {
            LOG_ERROR("[auto_init_saul] error initializing as5047d #%u\n", i);
        }
        else {
            saul_entries[i].dev = &(as5047d_devs[i]);
            saul_entries[i].name = as5047d_saul_info[i].name;
            saul_entries[i].driver = &as5047d_saul_driver;
            saul_reg_add(&(saul_entries[i]));
        }
    }
}

#else
typedef int dont_be_pedantic;
#endif /* MODULE_AS5047D */
