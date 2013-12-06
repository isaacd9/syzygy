#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S4,     IRSENSOR,       sensorI2CCustom)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     ARM,           tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     DRIVE_LEFT,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     DRIVE_RIGHT,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     INTAKE,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,     FLAG_RAISER,   tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    HANG,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    HANG2,                tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define DRIVE_JOY	joystick.joy1
#define DRIVE_JOY_LEFT joystick.joy1_y1
#define DRIVE_JOY_RIGHT joystick.joy1_y2
#define DRIVE_JOY_BUTTONS DRIVE_JOY_Buttons
#define DRIVE_JOY_PRESSED joy1Btn

#define OP_JOY joystick.joy2
#define OP_JOY_LEFT joystick.joy2_y1
#define OP_JOY_RIGHT joystick.joy2_y2
#define OP_JOY_BUTTONS joystick.joy2_Buttons
#define OP_JOY_PRESSED joy2Btn

#define JOY_POLL_DELAY 10
#define DRIVE_SET_DELAY 10
#define DEBUGGER writeDebugStreamLine
static const bool USE_LOG_SCALE=true;

#define FLAG_SPEED -100

#define SERVO_HANG_POSITION 255

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "initialize.h"

#include "events.h" //Order is important here. This must be included above poll_joystick
#include "poll_joystick.h"
#include "auto_common.h"
#include "drivers/hitechnic-irseeker-v2.h"

//definitions
#define DRIVE_SPEED 40
#define TURN_SPEED 100
#define ARM_SPEED 100
#define INTAKE_SPEED 50

#define NINETY_DEGREES 2000

#define BUCK1_TICKS 375
#define BUCK2_TICKS 1700
#define BUCK3_TICKS 3750
#define BUCK4_TICKS 5500
#define BUCK_WINDOW_TICKS 40

#define ARM_UP_TIME 2000
#define KICK_TIME 1000

#define END_OF_LINE 5500
#define TO_BRIDGE_TICKS 1000
#define TO_BRIDGE_TURN_TICKS 1000
#define ONTO_BRIDGE_TICKS 1000

#define IR_THRESHOLD 50

int foundVal = BUCK4_TICKS;
//function prototypes
int getIRValue()
{
	//get the IR sensor's value (AC from center sensor) here
	int ac1, ac2, ac3, ac4, ac5;
	HTIRS2readAllACStrength(IRSENSOR, ac1, ac2, ac3, ac4, ac5);
	writeDebugStreamLine("IR VALUE %d", ac3);
	return ac3;
}

task main () {
	zeroEncoders();
	while(DRIVE_ENCODERS < BUCK4_TICKS) {
		_setDriveMotors(DRIVE_SPEED, DRIVE_SPEED);
			if((BUCK1_TICKS-BUCK_WINDOW_TICKS <  DRIVE_ENCODERS && DRIVE_ENCODERS < BUCK1_TICKS+BUCK_WINDOW_TICKS )|| (BUCK2_TICKS-BUCK_WINDOW_TICKS <  DRIVE_ENCODERS && DRIVE_ENCODERS < BUCK2_TICKS+BUCK_WINDOW_TICKS ) || (BUCK3_TICKS-BUCK_WINDOW_TICKS <  DRIVE_ENCODERS && DRIVE_ENCODERS < BUCK3_TICKS+BUCK_WINDOW_TICKS )) {
					if(getIRValue() > IR_THRESHOLD) {
						foundVal = DRIVE_ENCODERS;
						break;
					}
				}
				writeDebugStreamLine("%d", DRIVE_ENCODERS);
		wait1Msec(5);
	}

	_setDriveMotors(0,0);
	writeDebugStreamLine("foundVal %d", foundVal);

	turnDriveRightTicks(TURN_SPEED, NINETY_DEGREES);

	runArmTime(ARM_SPEED, ARM_UP_TIME);
	runIntakeTime(INTAKE_SPEED, KICK_TIME);

	turnDriveLeftTicks(TURN_SPEED, NINETY_DEGREES);
	moveDriveTicks(DRIVE_SPEED, END_OF_LINE-foundVal); //Assumes no interruption in positioning

	turnDriveRightTicks(TURN_SPEED, TO_BRIDGE_TURN_TICKS);
	moveDriveTicks(DRIVE_SPEED, ONTO_BRIDGE_TICKS);
}
