/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Created by HecTech */
 
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "platform.h"


#include "build/build_config.h"
#include "build/debug.h"

#include "common/maths.h"
#include "common/axis.h"
#include "common/utils.h"

#include "drivers/system.h"
#include "drivers/light_led.h"
#include "drivers/vtx_rtc6705.h"

#include "io/serial.h"
#include "io/dashboard.h"
#include "io/openvtx.h"


#include "fc/config.h"
#include "fc/runtime_config.h"

static serialPort_t *VtxRXPORT = NULL;

void OpenVtxInit(void)
{
        VtxRXPORT = openSerialPort(SERIAL_PORT_USART1, FUNCTION_NONE, NULL,
                                         9600, MODE_RXTX,
                                         SERIAL_NOT_INVERTED);

}

void OpenVtxUpdate(timeUs_t currentTimeUs)
{

    UNUSED(currentTimeUs);
    while (serialRxBytesWaiting(VtxRXPORT)) {
    uint8_t c = serialRead(VtxRXPORT);
    rtc6705SetFreq(c);

    }

}