/*
 * Copyright (C) 2019 Florian Seybold
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    drivers_as5047d
 * @ingroup     drivers_sensors
 * @ingroup     drivers_saul
 *
 * @brief       Rotary encoder as5047d driver
 *
 * This driver provides @ref drivers_saul capabilities.
 * @{
 *
 * @file
 * @brief       Driver for the as5047d
 *
 * @author      Florian Seybold <florian@seybold.space>
 */

#ifndef AS5047D_H
#define AS5047D_H

#include <stdint.h>
#include "periph/spi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Parameters needed for device initialization
 */
typedef struct {
    spi_t 	   bus;
    spi_cs_t 	cs;
    spi_mode_t mode;
    spi_clk_t 	clk;
} as5047d_params_t;

/**
  * @brief   Device descriptor for a as5047d device
  */
typedef struct {
    as5047d_params_t p;
} as5047d_t;

/**
 * @brief   Initialize a as5047d device
 *
 * @param[out] dev          device descriptor
 * @param[in] params        configuration parameters
 *
 * @return                   0 on success
 * @return                  -1 on error
 */
int as5047d_init(as5047d_t *dev, const as5047d_params_t *params);

/**
 * @brief   Read and reset as5047d value
 *
 * @param[out] dev          device descriptor of sensor
 *
 * @return                  Accumulated pulse counts
 */
int16_t as5047d_read(as5047d_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* AS5047D_H */
/** @} */
