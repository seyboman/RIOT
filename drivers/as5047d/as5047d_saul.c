/*
 * Copyright (C) 2017 UC Berkeley
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_as5047d
 * @{
 *
 * @file
 * @brief       AS5047D adaption to the RIOT actuator/sensor interface
 *
 * @author      Florian Seybold <florian@seybold.space>
 *
 * @}
 */

#include <string.h>

#include "saul.h"
#include "as5047d.h"

static int read_as5047d(const void *dev, phydat_t *res)
{
    /* Using non-const dev !! */
    as5047d_t *mydev = (as5047d_t *)dev;
    res->val[0] = as5047d_read(mydev);
    res->unit  = UNIT_NONE;
    res->scale = 0;
    return 1;
}

static int write_as5047d(const void *dev, phydat_t *data)
{
    (void) data;
    return 1;
}

const saul_driver_t as5047d_saul_driver = {
    .read  = read_as5047d,
    .write = write_as5047d,
    .type  = SAUL_SENSE_COUNT,
};
