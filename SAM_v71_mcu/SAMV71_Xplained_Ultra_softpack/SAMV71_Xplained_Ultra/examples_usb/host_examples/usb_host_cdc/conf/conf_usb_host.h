/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2015, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */
/**
 * \file
 *
 * \brief USB host configuration file
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _CONF_USB_HOST_H_
#define _CONF_USB_HOST_H_

#include "board.h"

/**
 * USB Host Configuration
 * @{
 */

/*! Array of UHI APIs Define the list of UHI supported by USB host. */
#define USB_HOST_UHI        UHI_CDC

/*! Maximum current allowed on Vbus (mA) */
#define USB_HOST_POWER_MAX  500

/*! Authorize the USB HUB support */
//#define USB_HOST_HUB_SUPPORT

/*! Authorize the USB host to run in High Speed */

# define USB_HOST_HS_SUPPORT

/**
 * USB Host callbacks
 * @{
 */

/*! To notify that the USB mode are switched automatically.
    This is possible only when ID pin is available. */
#define UHC_MODE_CHANGE(b_host_mode)        ui_usb_mode_change(b_host_mode)

/*! To notify that the Vbus level has changed.
    Available only in USB hardware with Vbus monitoring. */
#define UHC_VBUS_CHANGE(b_present)          ui_usb_vbus_change(b_present)

/*! To notify that a Vbus error has occurred.
    Available only in USB hardware with Vbus monitoring. */
#define UHC_VBUS_ERROR()                    ui_usb_vbus_error()

/*! To notify that a device has been connected or disconnected. */
#define UHC_CONNECTION_EVENT(dev, b_present) ui_usb_connection_event(dev, \
		b_present)

/*! Called when a USB device or the host have wake up the USB line. */
#define UHC_WAKEUP_EVENT()                  ui_usb_wakeup_event()

/*! Called for each received SOF each 1 ms.
    Note: Available in High and Full speed mode */
#define UHC_SOF_EVENT()                     ui_usb_sof_event()

/*! Called when a USB device configuration must be chosen.
    Thus, the application can choose either a configuration number for this
    device or a configuration number 0 to reject it.
    If callback not defined the configuration 1 is chosen. */
//#define UHC_DEVICE_CONF(dev)                uint8_t usb_device_conf(dev)

/*! Called when a USB device enumeration is completed. */
#define UHC_ENUM_EVENT(dev,b_status)        ui_usb_enum_event(dev,b_status)


/*@} */



/**
 * USB Interface Configuration
 * @{
 */

/**
 * Configuration of CDC interface
 * @{
 */
#define UHI_CDC_CHANGE(dev, b_plug)
#define UHI_CDC_RX_NOTIFY()                 uart_rx_notify()
//@}
//@}

//@}
#define PINS_USART          PIN_USART2_TXD, PIN_USART2_RXD
#define USART_ENABLE()
#define USART_DISABLE()
#define USART_BASE       USART2
#define USART_ID         ID_USART2
#define USART_HANDLER    USART2_Handler
#define USART_INT_IRQn   USART2_IRQn
#define USART_INT_LEVEL  3

#include "uhi_cdc.h"
#include "usart_cdc.h"
#include "ui.h"

#endif // _CONF_USB_HOST_H_
