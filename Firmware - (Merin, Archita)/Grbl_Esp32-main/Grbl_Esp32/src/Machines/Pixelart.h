#pragma once
// clang-format off


/*
    NeoPI_W_v1.h
    Part of Grbl_ESP32

    Pin assignments for the NeoPI Wireless CNC Controller(3-axis), v1.0 and later.
    https://github.com/saheenpalayi/NeoPI_Wireless

    2018    - Bart Dring
    2020    - Mitch Bradley
    2022    - Saheen Palayi
    2026    - Archita BK

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME "PIXELART_COREXY_TEST"
#define CUSTOM_CODE_FILENAME "../Custom/CoreXY.cpp"

//#define MACHINE_NAME            "NeoPI_W_v1"

#define X_STEP_PIN              GPIO_NUM_12
#define X_DIRECTION_PIN         GPIO_NUM_26
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_25


#define X_LIMIT_PIN             GPIO_NUM_21 
#define Y_LIMIT_PIN             GPIO_NUM_4
//#define Z_SERVO_PIN             GPIO_NUM_27

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_13



#define DEFAULT_HOMING_ENABLE 1
#define DEFAULT_HOMING_CYCLE_1 bit(X_AXIS)
#define DEFAULT_HOMING_CYCLE_2 bit(Y_AXIS)
#define DEFAULT_HOMING_DIR_MASK (bit(X_AXIS)|bit(Y_AXIS))  // homes negative

// Z-Axis controlled via PWM spindle (M03/M05 commands)
#define SPINDLE_TYPE SpindleType::PWM
#define SPINDLE_OUTPUT_PIN GPIO_NUM_22  // Z-axis servo control pin
//#define DEFAULT_Z_MAX_TRAVEL 100.0 // This is percent in servo mode

//og code
// #define SPINDLE_TYPE            SpindleType::PWM
// #define SPINDLE_OUTPUT_PIN      GPIO_NUM_17   // labeled SpinPWM
// #define SPINDLE_ENABLE_PIN      GPIO_NUM_22  // labeled SpinEnbl

// #define COOLANT_MIST_PIN        GPIO_NUM_21  // labeled Mist
// #define COOLANT_FLOOD_PIN       GPIO_NUM_25  // labeled Flood
// #define PROBE_PIN               GPIO_NUM_32  // labeled Probe


#define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 1  // false


#define DEFAULT_X_STEPS_PER_MM 100.0
#define DEFAULT_Y_STEPS_PER_MM 100.0

#define DEFAULT_X_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.

/*
#define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_35  // labeled Door,  needs external pullup
#define CONTROL_RESET_PIN       GPIO_NUM_34  // labeled Reset, needs external pullup
#define CONTROL_FEED_HOLD_PIN   GPIO_NUM_36  // labeled Hold,  needs external pullup
#define CONTROL_CYCLE_START_PIN GPIO_NUM_39  // labeled Start, needs external pullup
*/
