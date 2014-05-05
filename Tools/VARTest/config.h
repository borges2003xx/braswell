// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
//
//  DO NOT EDIT this file to adjust your configuration.  Create your own
//  APM_Config.h and use APM_Config.h.example as a reference.
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
///
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Default and automatic configuration details.
//
// Notes for maintainers:
//
// - Try to keep this file organised in the same order as APM_Config.h.example
//

#include "defines.h"

///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
///
#include "APM_Config.h"  // <== THIS INCLUDE, DO NOT EDIT IT. EVER.
///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
///

// Just so that it's completely clear...
#define ENABLED			1
#define DISABLED		0

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// HARDWARE CONFIGURATION AND CONNECTIONS
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// APM HARDWARE
//

# define CONFIG_IMU_TYPE   CONFIG_IMU_MPU6000
# define CONFIG_PUSHBUTTON DISABLED
# define CONFIG_RELAY      DISABLED
# define MAG_ORIENTATION   AP_COMPASS_APM2_SHIELD
# define CONFIG_SONAR_SOURCE SONAR_SOURCE_ANALOG_PIN
# define CONFIG_PITOT_SOURCE PITOT_SOURCE_ANALOG_PIN
# define MAGNETOMETER ENABLED
# define CONFIG_BARO     AP_BARO_MS5611
# define CONFIG_MS5611_SERIAL SPI

# define A_LED_PIN        27
# define B_LED_PIN        26
# define C_LED_PIN        25
# define LED_ON           LOW
# define LED_OFF          HIGH
# define SLIDE_SWITCH_PIN (-1)
# define PUSHBUTTON_PIN   (-1)
# define CLI_SLIDER_ENABLED DISABLED
# define USB_MUX_PIN 23
# define BATTERY_PIN_1	  1
# define CURRENT_PIN_1	  2

//////////////////////////////////////////////////////////////////////////////
// AIRSPEED_SENSOR
// AIRSPEED_RATIO
//
#ifndef AIRSPEED_SENSOR
# define AIRSPEED_SENSOR		DISABLED
#endif

#ifndef AIRSPEED_RATIO
# define AIRSPEED_RATIO			1.9936		// Note - this varies from the value in ArduPilot due to the difference in ADC resolution
#endif

//////////////////////////////////////////////////////////////////////////////
// IMU Selection
//
#ifndef CONFIG_IMU_TYPE
# define CONFIG_IMU_TYPE CONFIG_IMU_OILPAN
#endif

#if CONFIG_IMU_TYPE == CONFIG_IMU_MPU6000
# ifndef CONFIG_MPU6000_CHIP_SELECT_PIN
#  define CONFIG_MPU6000_CHIP_SELECT_PIN 53
# endif
#endif

//////////////////////////////////////////////////////////////////////////////
// ADC Enable - used to eliminate for systems which don't have ADC.
//
#ifndef CONFIG_ADC
# if CONFIG_IMU_TYPE == CONFIG_IMU_OILPAN
#   define CONFIG_ADC ENABLED
# else
#   define CONFIG_ADC DISABLED
# endif
#endif

//////////////////////////////////////////////////////////////////////////////
// Barometer
//

#ifndef CONFIG_BARO
# define CONFIG_BARO AP_BARO_BMP085
#endif

//////////////////////////////////////////////////////////////////////////////
// Pitot
//

#ifndef PITOT_ENABLED
# define PITOT_ENABLED         	DISABLED
#endif

#ifndef CONFIG_PITOT_SOURCE
# define CONFIG_PITOT_SOURCE PITOT_SOURCE_ADC
#endif

#if CONFIG_PITOT_SOURCE == PITOT_SOURCE_ADC
# ifndef CONFIG_PITOT_SOURCE_ADC_CHANNEL
#  define CONFIG_PITOT_SOURCE_ADC_CHANNEL 7
# endif
#elif CONFIG_PITOT_SOURCE == PITOT_SOURCE_ANALOG_PIN
# ifndef CONFIG_PITOT_SOURCE_ANALOG_PIN
#  define CONFIG_PITOT_SOURCE_ANALOG_PIN 0
# endif
#else
# warning Invalid value for CONFIG_PITOT_SOURCE, disabling airspeed
# undef PITOT_ENABLED
# define PITOT_ENABLED DISABLED
#endif

#ifndef SONAR_TYPE
# define SONAR_TYPE             MAX_SONAR_LV	// MAX_SONAR_XL,
#endif

#ifndef SONAR_ENABLED
#define SONAR_ENABLED DISABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// HIL_MODE                                 OPTIONAL

#ifndef HIL_MODE
#define HIL_MODE	HIL_MODE_DISABLED
#endif

#if HIL_MODE != HIL_MODE_DISABLED	// we are in HIL mode
 # undef GPS_PROTOCOL
 # define GPS_PROTOCOL GPS_PROTOCOL_NONE
#endif

//////////////////////////////////////////////////////////////////////////////
// GPS_PROTOCOL
//
// Note that this test must follow the HIL_PROTOCOL block as the HIL
// setup may override the GPS configuration.
//
#ifndef GPS_PROTOCOL
# define GPS_PROTOCOL GPS_PROTOCOL_AUTO
#endif

#ifndef MAV_SYSTEM_ID
# define MAV_SYSTEM_ID		1
#endif

//////////////////////////////////////////////////////////////////////////////
// Serial port speeds.
//
#ifndef SERIAL0_BAUD
# define SERIAL0_BAUD			115200
#endif
#ifndef SERIAL3_BAUD
# define SERIAL3_BAUD			 57600
#endif


//////////////////////////////////////////////////////////////////////////////
// Battery monitoring
//
#ifndef BATTERY_EVENT
# define BATTERY_EVENT			DISABLED
#endif
#ifndef LOW_VOLTAGE
# define LOW_VOLTAGE			9.6
#endif
#ifndef VOLT_DIV_RATIO
# define VOLT_DIV_RATIO			3.56	// This is the proper value for an on-board APM1 voltage divider with a 3.9kOhm resistor
//# define VOLT_DIV_RATIO		15.70	// This is the proper value for the AttoPilot 50V/90A sensor
//# define VOLT_DIV_RATIO		4.127	// This is the proper value for the AttoPilot 13.6V/45A sensor

#endif

#ifndef CURR_AMP_PER_VOLT
# define CURR_AMP_PER_VOLT		27.32	// This is the proper value for the AttoPilot 50V/90A sensor
//# define CURR_AMP_PER_VOLT	13.66	// This is the proper value for the AttoPilot 13.6V/45A sensor
#endif

#ifndef CURR_AMPS_OFFSET
# define CURR_AMPS_OFFSET		0.0
#endif
#ifndef HIGH_DISCHARGE
# define HIGH_DISCHARGE		1760
#endif

//////////////////////////////////////////////////////////////////////////////
// INPUT_VOLTAGE
//
#ifndef INPUT_VOLTAGE
# define INPUT_VOLTAGE			4.68	//  4.68 is the average value for a sample set.  This is the value at the processor with 5.02 applied at the servo rail
#endif

//////////////////////////////////////////////////////////////////////////////
//  MAGNETOMETER
#ifndef MAGNETOMETER
# define MAGNETOMETER			DISABLED
#endif
#ifndef MAG_ORIENTATION
# define MAG_ORIENTATION		AP_COMPASS_COMPONENTS_DOWN_PINS_FORWARD
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// RADIO CONFIGURATION
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Radio channel limits
//
// Note that these are not called out in APM_Config.h.reference.
//
#ifndef CH5_MIN
# define CH5_MIN	1000
#endif
#ifndef CH5_MAX
# define CH5_MAX	2000
#endif
#ifndef CH6_MIN
# define CH6_MIN	1000
#endif
#ifndef CH6_MAX
# define CH6_MAX	2000
#endif
#ifndef CH7_MIN
# define CH7_MIN	1000
#endif
#ifndef CH7_MAX
# define CH7_MAX	2000
#endif
#ifndef CH8_MIN
# define CH8_MIN	1000
#endif
#ifndef CH8_MAX
# define CH8_MAX	2000
#endif


#ifndef FLAP_1_PERCENT
# define FLAP_1_PERCENT 0
#endif
#ifndef FLAP_1_SPEED
# define FLAP_1_SPEED 255
#endif
#ifndef FLAP_2_PERCENT
# define FLAP_2_PERCENT 0
#endif
#ifndef FLAP_2_SPEED
# define FLAP_2_SPEED 255
#endif
//////////////////////////////////////////////////////////////////////////////
// FLIGHT_MODE
// FLIGHT_MODE_CHANNEL
//
#ifndef FLIGHT_MODE_CHANNEL
# define FLIGHT_MODE_CHANNEL	8
#endif
#if (FLIGHT_MODE_CHANNEL != 5) && (FLIGHT_MODE_CHANNEL != 6) && (FLIGHT_MODE_CHANNEL != 7) && (FLIGHT_MODE_CHANNEL != 8)
# error XXX
# error XXX You must set FLIGHT_MODE_CHANNEL to 5, 6, 7 or 8
# error XXX
#endif

#if !defined(FLIGHT_MODE_1)
# define FLIGHT_MODE_1			RTL
#endif
#if !defined(FLIGHT_MODE_2)
# define FLIGHT_MODE_2			RTL
#endif
#if !defined(FLIGHT_MODE_3)
# define FLIGHT_MODE_3			STABILIZE
#endif
#if !defined(FLIGHT_MODE_4)
# define FLIGHT_MODE_4			STABILIZE
#endif
#if !defined(FLIGHT_MODE_5)
# define FLIGHT_MODE_5			MANUAL
#endif
#if !defined(FLIGHT_MODE_6)
# define FLIGHT_MODE_6			MANUAL
#endif


//////////////////////////////////////////////////////////////////////////////
// THROTTLE_FAILSAFE
// THROTTLE_FS_VALUE
// SHORT_FAILSAFE_ACTION
// LONG_FAILSAFE_ACTION
// GCS_HEARTBEAT_FAILSAFE
//
#ifndef THROTTLE_FAILSAFE
# define THROTTLE_FAILSAFE		ENABLED
#endif
#ifndef THROTTLE_FS_VALUE
# define THROTTLE_FS_VALUE		950
#endif
#ifndef SHORT_FAILSAFE_ACTION
# define SHORT_FAILSAFE_ACTION		0
#endif
#ifndef LONG_FAILSAFE_ACTION
# define LONG_FAILSAFE_ACTION		0
#endif
#ifndef GCS_HEARTBEAT_FAILSAFE
# define GCS_HEARTBEAT_FAILSAFE		DISABLED
#endif


//////////////////////////////////////////////////////////////////////////////
// AUTO_TRIM
//
#ifndef AUTO_TRIM
# define AUTO_TRIM				DISABLED
#endif


//////////////////////////////////////////////////////////////////////////////
// THROTTLE_REVERSE
//
#ifndef THROTTLE_REVERSE
# define THROTTLE_REVERSE		DISABLED
#endif


//////////////////////////////////////////////////////////////////////////////
// ENABLE_STICK_MIXING
//
#ifndef ENABLE_STICK_MIXING
# define ENABLE_STICK_MIXING	ENABLED
#endif


//////////////////////////////////////////////////////////////////////////////
// THROTTLE_OUT
//
#ifndef THROTTE_OUT
# define THROTTLE_OUT			ENABLED
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// STARTUP BEHAVIOUR
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// GROUND_START_DELAY
//
#ifndef GROUND_START_DELAY
# define GROUND_START_DELAY		0
#endif


//////////////////////////////////////////////////////////////////////////////
// ENABLE_AIR_START
//
#ifndef ENABLE_AIR_START
# define ENABLE_AIR_START		DISABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// ENABLE REVERSE_SWITCH
//
#ifndef REVERSE_SWITCH
# define REVERSE_SWITCH		ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// ENABLE ELEVON_MIXING
//
#ifndef ELEVON_MIXING
# define ELEVON_MIXING		DISABLED
#endif
#ifndef ELEVON_REVERSE
# define ELEVON_REVERSE	    DISABLED
#endif
#ifndef ELEVON_CH1_REVERSE
# define ELEVON_CH1_REVERSE	DISABLED
#endif
#ifndef ELEVON_CH2_REVERSE
# define ELEVON_CH2_REVERSE	DISABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// MOUNT (ANTENNA OR CAMERA)
//
#ifndef MOUNT
# define MOUNT		DISABLED
#endif

#if defined( __AVR_ATmega1280__ ) && CAMERA == ENABLED
// The small ATmega1280 chip does not have enough memory for camera support
// so disable CLI, this will allow camera support and other improvements to fit.
// This should almost have no side effects, because the APM planner can now do a complete board setup.
#define CLI_ENABLED DISABLED
#endif


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// FLIGHT AND NAVIGATION CONTROL
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Altitude measurement and control.
//
#ifndef ALT_EST_GAIN
# define ALT_EST_GAIN			0.01
#endif
#ifndef ALTITUDE_MIX
# define ALTITUDE_MIX			1
#endif


//////////////////////////////////////////////////////////////////////////////
// AIRSPEED_CRUISE
//
#ifndef AIRSPEED_CRUISE
# define AIRSPEED_CRUISE		12 // 12 m/s
#endif
#define AIRSPEED_CRUISE_CM AIRSPEED_CRUISE*100


//////////////////////////////////////////////////////////////////////////////
// MIN_GNDSPEED
//
#ifndef MIN_GNDSPEED
# define MIN_GNDSPEED			0 // m/s (0 disables)
#endif
#define MIN_GNDSPEED_CM MIN_GNDSPEED*100


//////////////////////////////////////////////////////////////////////////////
// FLY_BY_WIRE_B airspeed control
//
#ifndef AIRSPEED_FBW_MIN
# define AIRSPEED_FBW_MIN		6
#endif
#ifndef AIRSPEED_FBW_MAX
# define AIRSPEED_FBW_MAX		22
#endif

#ifndef ALT_HOLD_FBW
# define ALT_HOLD_FBW 0
#endif
#define ALT_HOLD_FBW_CM ALT_HOLD_FBW*100



/*  The following parmaeters have no corresponding control implementation
#ifndef THROTTLE_ALT_P
# define THROTTLE_ALT_P         0.32
#endif
#ifndef THROTTLE_ALT_I
# define THROTTLE_ALT_I         0.0
#endif
#ifndef THROTTLE_ALT_D
# define THROTTLE_ALT_D         0.0
#endif
#ifndef THROTTLE_ALT_INT_MAX
# define THROTTLE_ALT_INT_MAX   20
#endif
#define THROTTLE_ALT_INT_MAX_CM THROTTLE_ALT_INT_MAX*100
*/


//////////////////////////////////////////////////////////////////////////////
// Servo Mapping
//
#ifndef THROTTLE_MIN
# define THROTTLE_MIN			0 // percent
#endif
#ifndef THROTTLE_CRUISE
# define THROTTLE_CRUISE		45
#endif
#ifndef THROTTLE_MAX
# define THROTTLE_MAX			75
#endif

//////////////////////////////////////////////////////////////////////////////
// Autopilot control limits
//
#ifndef HEAD_MAX
# define HEAD_MAX				45
#endif
#ifndef PITCH_MAX
# define PITCH_MAX				15
#endif
#ifndef PITCH_MIN
# define PITCH_MIN				-25
#endif
#define HEAD_MAX_CENTIDEGREE HEAD_MAX * 100
#define PITCH_MAX_CENTIDEGREE PITCH_MAX * 100
#define PITCH_MIN_CENTIDEGREE PITCH_MIN * 100

//////////////////////////////////////////////////////////////////////////////
// Attitude control gains
//
#ifndef SERVO_ROLL_P
# define SERVO_ROLL_P         0.4
#endif
#ifndef SERVO_ROLL_I
# define SERVO_ROLL_I         0.0
#endif
#ifndef SERVO_ROLL_D
# define SERVO_ROLL_D         0.0
#endif
#ifndef SERVO_ROLL_INT_MAX
# define SERVO_ROLL_INT_MAX   5
#endif
#define SERVO_ROLL_INT_MAX_CENTIDEGREE SERVO_ROLL_INT_MAX*100
#ifndef ROLL_SLEW_LIMIT
# define ROLL_SLEW_LIMIT      0
#endif
#ifndef SERVO_PITCH_P
# define SERVO_PITCH_P        0.6
#endif
#ifndef SERVO_PITCH_I
# define SERVO_PITCH_I        0.0
#endif
#ifndef SERVO_PITCH_D
# define SERVO_PITCH_D        0.0
#endif
#ifndef SERVO_PITCH_INT_MAX
# define SERVO_PITCH_INT_MAX  5
#endif
#define SERVO_PITCH_INT_MAX_CENTIDEGREE SERVO_PITCH_INT_MAX*100
#ifndef PITCH_COMP
# define PITCH_COMP           0.2
#endif
#ifndef SERVO_YAW_P
# define SERVO_YAW_P          0.0
#endif
#ifndef SERVO_YAW_I
# define SERVO_YAW_I          0.0
#endif
#ifndef SERVO_YAW_D
# define SERVO_YAW_D          0.0
#endif
#ifndef SERVO_YAW_INT_MAX
# define SERVO_YAW_INT_MAX    0
#endif
#ifndef RUDDER_MIX
# define RUDDER_MIX           0.5
#endif


//////////////////////////////////////////////////////////////////////////////
// Navigation control gains
//
#ifndef NAV_ROLL_P
# define NAV_ROLL_P           0.7
#endif
#ifndef NAV_ROLL_I
# define NAV_ROLL_I           0.0
#endif
#ifndef NAV_ROLL_D
# define NAV_ROLL_D           0.02
#endif
#ifndef NAV_ROLL_INT_MAX
# define NAV_ROLL_INT_MAX     5
#endif
#define NAV_ROLL_INT_MAX_CENTIDEGREE NAV_ROLL_INT_MAX*100
#ifndef NAV_PITCH_ASP_P
# define NAV_PITCH_ASP_P      0.65
#endif
#ifndef NAV_PITCH_ASP_I
# define NAV_PITCH_ASP_I      0.0
#endif
#ifndef NAV_PITCH_ASP_D
# define NAV_PITCH_ASP_D      0.0
#endif
#ifndef NAV_PITCH_ASP_INT_MAX
# define NAV_PITCH_ASP_INT_MAX 5
#endif
#define NAV_PITCH_ASP_INT_MAX_CMSEC NAV_PITCH_ASP_INT_MAX*100
#ifndef NAV_PITCH_ALT_P
# define NAV_PITCH_ALT_P      0.65
#endif
#ifndef NAV_PITCH_ALT_I
# define NAV_PITCH_ALT_I      0.0
#endif
#ifndef NAV_PITCH_ALT_D
# define NAV_PITCH_ALT_D      0.0
#endif
#ifndef NAV_PITCH_ALT_INT_MAX
# define NAV_PITCH_ALT_INT_MAX 5
#endif
#define NAV_PITCH_ALT_INT_MAX_CM NAV_PITCH_ALT_INT_MAX*100


//////////////////////////////////////////////////////////////////////////////
// Energy/Altitude control gains
//
#ifndef THROTTLE_TE_P
# define THROTTLE_TE_P        0.50
#endif
#ifndef THROTTLE_TE_I
# define THROTTLE_TE_I        0.0
#endif
#ifndef THROTTLE_TE_D
# define THROTTLE_TE_D        0.0
#endif
#ifndef THROTTLE_TE_INT_MAX
# define THROTTLE_TE_INT_MAX  20
#endif
#ifndef THROTTLE_SLEW_LIMIT
# define THROTTLE_SLEW_LIMIT  0
#endif
#ifndef P_TO_T
# define P_TO_T               0
#endif
#ifndef T_TO_P
# define T_TO_P               0
#endif
#ifndef PITCH_TARGET
# define PITCH_TARGET         0
#endif

//////////////////////////////////////////////////////////////////////////////
// Crosstrack compensation
//
#ifndef XTRACK_GAIN
# define XTRACK_GAIN          1 // deg/m
#endif
#ifndef XTRACK_ENTRY_ANGLE
# define XTRACK_ENTRY_ANGLE   30 // deg
#endif
# define XTRACK_GAIN_SCALED XTRACK_GAIN*100
# define XTRACK_ENTRY_ANGLE_CENTIDEGREE XTRACK_ENTRY_ANGLE*100

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// DEBUGGING
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Dataflash logging control
//

#ifndef LOGGING_ENABLED
# define LOGGING_ENABLED		ENABLED
#endif


#ifndef LOG_ATTITUDE_FAST
# define LOG_ATTITUDE_FAST		DISABLED
#endif
#ifndef LOG_ATTITUDE_MED
# define LOG_ATTITUDE_MED 		ENABLED
#endif
#ifndef LOG_GPS
# define LOG_GPS 				ENABLED
#endif
#ifndef LOG_PM
# define LOG_PM 				ENABLED
#endif
#ifndef LOG_CTUN
# define LOG_CTUN				DISABLED
#endif
#ifndef LOG_NTUN
# define LOG_NTUN				DISABLED
#endif
#ifndef LOG_MODE
# define LOG_MODE				ENABLED
#endif
#ifndef LOG_RAW
# define LOG_RAW				DISABLED
#endif
#ifndef LOG_CMD
# define LOG_CMD				ENABLED
#endif
#ifndef LOG_CUR
# define LOG_CUR			DISABLED
#endif

// calculate the default log_bitmask
#define LOGBIT(_s)	(LOG_##_s ? MASK_LOG_##_s : 0)

#define DEFAULT_LOG_BITMASK \
		LOGBIT(ATTITUDE_FAST)	| \
		LOGBIT(ATTITUDE_MED)	| \
		LOGBIT(GPS)				| \
		LOGBIT(PM)				| \
		LOGBIT(CTUN)			| \
		LOGBIT(NTUN)			| \
		LOGBIT(MODE)			| \
		LOGBIT(RAW)				| \
		LOGBIT(CMD)				| \
		LOGBIT(CUR)


//////////////////////////////////////////////////////////////////////////////
// Navigation defaults
//
#ifndef WP_RADIUS_DEFAULT
# define WP_RADIUS_DEFAULT		30
#endif

#ifndef LOITER_RADIUS_DEFAULT
# define LOITER_RADIUS_DEFAULT 60
#endif

#ifndef ALT_HOLD_HOME
# define ALT_HOLD_HOME 100
#endif
#define ALT_HOLD_HOME_CM ALT_HOLD_HOME*100

#ifndef USE_CURRENT_ALT
# define USE_CURRENT_ALT FALSE
#endif

#ifndef INVERTED_FLIGHT_PWM
# define INVERTED_FLIGHT_PWM 1750
#endif

//////////////////////////////////////////////////////////////////////////////
// Developer Items
//

#ifndef STANDARD_SPEED
# define STANDARD_SPEED		15.0
#define STANDARD_SPEED_SQUARED (STANDARD_SPEED * STANDARD_SPEED)
#endif
#define STANDARD_THROTTLE_SQUARED (THROTTLE_CRUISE * THROTTLE_CRUISE)

// use this to enable servos in HIL mode
#ifndef HIL_SERVOS
# define HIL_SERVOS DISABLED
#endif

// use this to completely disable the CLI
#ifndef CLI_ENABLED
# define CLI_ENABLED ENABLED
#endif

// use this to disable the CLI slider switch
#ifndef CLI_SLIDER_ENABLED
# define CLI_SLIDER_ENABLED ENABLED
#endif

// delay to prevent Xbee bricking, in milliseconds
#ifndef MAVLINK_TELEMETRY_PORT_DELAY
# define MAVLINK_TELEMETRY_PORT_DELAY 2000
#endif

// use this to disable gen-fencing
#ifndef GEOFENCE_ENABLED
# define GEOFENCE_ENABLED ENABLED
#endif

// pwm value on FENCE_CHANNEL to use to enable fenced mode
#ifndef FENCE_ENABLE_PWM
# define FENCE_ENABLE_PWM 1750
#endif

// a digital pin to set high when the geo-fence triggers. Defaults
// to -1, which means don't activate a pin
#ifndef FENCE_TRIGGERED_PIN
# define FENCE_TRIGGERED_PIN -1
#endif

// if RESET_SWITCH_CH is not zero, then this is the PWM value on
// that channel where we reset the control mode to the current switch
// position (to for example return to switched mode after failsafe or
// fence breach)
#ifndef RESET_SWITCH_CHAN_PWM
# define RESET_SWITCH_CHAN_PWM 1750
#endif
