/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define USB_SUSPEND_WAKEUP_DELAY 2000

#define EE_HANDS

#undef SPLIT_USB_DETECT
#define USB_VBUS_PIN 19U

#define FORCE_NKRO

#define FORCED_SYNC_THROTTLE_MS 100
#define SPLIT_MAX_CONNECTION_ERRORS 10
#define SPLIT_WATCHDOG_ENABLE

#undef NO_DEBUG
#define NO_DEBUG
#undef NO_PRINT
#define NO_PRINT
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
