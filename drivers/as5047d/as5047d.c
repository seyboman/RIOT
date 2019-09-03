/*
 * Copyright (C) 2019 Florian Seybold
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 */

/**
 * @ingroup     drivers_as5047d
 * @{
 *
 * @file
 * @brief       Driver for the AS5047D.
 *
 * @author      Florian Seybold <florian@seybold.space>
 *
 * @}
 */

#include <string.h>

#include "as5047d_params.h"

#define ENABLE_DEBUG    (0)
#include "debug.h"

#include "periph/spi.h"

/* Initialize as5047d */
int as5047d_init(as5047d_t *dev, const as5047d_params_t *params)
{
    dev->p = *params;

    DEBUG("Initializing spi bus...\n");
    spi_init_cs(dev->p.bus, dev->p.cs);
    return 0;
}

int16_t as5047d_read(as5047d_t *dev)
{
    DEBUG("Asserting existing dev pointer...\n");
    assert(dev);

    DEBUG("Spi bus: %i\n", dev->p.bus);
    DEBUG("Acquiring spi bus...\n");
    spi_acquire(dev->p.bus, dev->p.cs, dev->p.mode, dev->p.clk);

    DEBUG("Transfering bytes over spi bus...\n");
    uint8_t b1 = spi_transfer_byte(dev->p.bus, dev->p.cs, true, (uint8_t)0xff);
    uint8_t b2 = spi_transfer_byte(dev->p.bus, dev->p.cs, false, (uint8_t)0xff);

    DEBUG("Releasing spi bus...\n");
    spi_release(dev->p.bus);

    return (((b1 << 8) | b2) & 0B0011111111111111);
}
