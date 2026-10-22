/*
 * Copyright (C) 2016 The CyanogenMod Project
 *               2017-2022 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

/*
 * Board specific nodes
 *
 * If your kernel exposes these controls in another place, you can either
 * symlink to the locations given here, or override this header in your
 * device tree.
 */
#define PANEL_BRIGHTNESS_NODE "/sys/class/backlight/panel/brightness"
// The panel exposes 0-365, but normal brightness uses 0-255.
// Leave PANEL_MAX_BRIGHTNESS_NODE undefined to exclude the extended range.
// Linear light levels mapped to the panel driver's normal 0-255 range.
// Derived from the shared A5/A7 brightness_table in s6e3fa3_panel_params.h.
static constexpr unsigned int panel_brightness_map[256] = {
    0, 0, 1, 9, 17, 21, 29, 37, 41, 47, 49, 53, 55, 57, 61, 63,
    65, 65, 69, 71, 71, 73, 75, 75, 77, 79, 81, 81, 83, 83, 85, 85,
    87, 87, 89, 89, 91, 91, 93, 93, 93, 95, 95, 97, 97, 97, 99, 99,
    99, 101, 101, 101, 103, 103, 103, 105, 105, 105, 107, 107, 107, 107, 109, 109,
    109, 109, 111, 111, 111, 111, 113, 113, 113, 113, 113, 115, 115, 115, 115, 117,
    117, 117, 117, 117, 117, 119, 119, 119, 119, 119, 121, 121, 121, 121, 121, 121,
    123, 123, 123, 123, 123, 123, 125, 125, 125, 125, 125, 125, 127, 127, 127, 127,
    127, 127, 127, 129, 129, 129, 129, 129, 129, 129, 129, 136, 136, 136, 136, 136,
    136, 136, 143, 143, 143, 143, 143, 143, 143, 143, 150, 150, 150, 150, 150, 150,
    150, 150, 150, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 166, 166, 166,
    166, 166, 166, 166, 166, 166, 166, 175, 175, 175, 175, 175, 175, 175, 175, 175,
    175, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 194, 194, 194, 194,
    194, 194, 194, 194, 194, 194, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202,
    211, 211, 211, 211, 211, 211, 211, 220, 220, 220, 220, 220, 224, 224, 224, 224,
    228, 228, 228, 228, 228, 231, 231, 231, 231, 235, 235, 235, 235, 235, 239, 239,
    239, 239, 239, 243, 243, 243, 243, 243, 247, 247, 247, 247, 247, 251, 251, 255,
};
#define PANEL_BRIGHTNESS_MAP panel_brightness_map

#define BUTTON_BRIGHTNESS_NODE "/sys/class/sec/sec_touchkey/brightness"
#define LED_BLINK_NODE "/sys/class/sec/led/led_blink"
#define LED_BLN_NODE "/sys/class/misc/backlightnotification/notification_led"

// Uncomment to enable variable button brightness
//#define VAR_BUTTON_BRIGHTNESS 1

/*
 * Brightness adjustment factors
 *
 * If one of your device's LEDs is more powerful than the others, use these
 * values to equalise them. This value is in the range 0.0-1.0.
 */
#define LED_ADJUSTMENT_R 1.0
#define LED_ADJUSTMENT_G 1.0
#define LED_ADJUSTMENT_B 1.0

/*
 * Light brightness factors
 *
 * It might make sense for all colours to be scaled down (for example, if your
 * LED is too bright). Use these values to adjust the brightness of each
 * light. This value is within the range 0-255.
 */
#define LED_BRIGHTNESS_BATTERY 255
#define LED_BRIGHTNESS_NOTIFICATION 255
#define LED_BRIGHTNESS_ATTENTION 255
