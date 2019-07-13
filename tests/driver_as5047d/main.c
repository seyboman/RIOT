/*
 * Copyright (C) 2019 Florian Seybold
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     tests
 * @{
 *
 * @file
 * @brief       Test application for the AS5047D driver
 *
 * @author      Florian Seybold <florian@seybold.space>
 *
 * @}
 */

#include <stdio.h>

#include "xtimer.h"
#include "as5047d_params.h"

#define SLEEP       US_PER_SEC

int main(void)
{
    as5047d_t dev;

    printf("AS5047D driver test application\n");

    /* Initialization */
    if (as5047d_init(&dev, &as5047d_params[0])) {
        printf("[Failed]");
        return 1;
    }
    else {
        printf("[OK]\n");
    }

    while (1) {
        /* Pulse counter reading */
        int16_t count = as5047d_read(&dev);
        printf("as5047d: %d\n", count);

        xtimer_usleep(SLEEP);
    }

    return 0;
}
