/*
 * Copyright (C) 2017 UC Berkeley
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_as5047d
 *
 * @{
 * @file
 * @brief       Default configuration for AS5047D devices
 *
 * @author      Florian Seybold <florian@seybold.space>
 */

#ifndef AS5047D_PARAMS_H
#define AS5047D_PARAMS_H

#include "board.h"
#include "as5047d.h"
#include "saul_reg.h"
//#include "boards/arduino-zero/arduino_pinmap.h"
#include "periph/spi.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef AS5047D_BUS
#define AS5047D_BUS  0
#endif

#ifndef AS5047D_CS
#define AS5047D_CS   ARDUINO_PIN_A2 //Chip select line on A2 on Mechaduino board.
#endif

#ifndef AS5047D_MODE 
#define AS5047D_MODE SPI_MODE_1
#endif

#ifndef AS5047D_CLK
#define AS5047D_CLK  SPI_CLK_10MHZ
#endif

#ifndef AS5047D_PARAMS
#define AS5047D_PARAMS       { .bus = AS5047D_BUS, \
                               .cs = AS5047D_CS, \
                               .mode = AS5047D_MODE, \
                               .clk = AS5047D_CLK \
                             }
#endif

#ifndef AS5047D_SAUL_INFO
#define AS5047D_SAUL_INFO    { .name = "as5047d" }
#endif

/**
 * @brief   AS5047D configuration
 */
static const as5047d_params_t as5047d_params[] =
{
    AS5047D_PARAMS
};

/**
 * @brief   Additional meta information to keep in the SAUL registry
 */
static const saul_reg_info_t as5047d_saul_info[] =
{
    AS5047D_SAUL_INFO
};

#ifdef __cplusplus
}
#endif

#endif /* AS5047D_PARAMS_H */
/** @} */
