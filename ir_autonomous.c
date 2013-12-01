#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     IRSENSOR,       sensorNone)
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
#include "drivers/hitechnic-irseeker-v2.h"

#include "common.h"
#include "events.h" //Order is important here. This must be included above poll_joystick
#include "poll_joystick.h"
#include "auto_common.h"

//definitions
#define DRIVE_SPEED 90

#define BUCK1_TICKS 1440
#define BUCK2_TICKS 2880
#define BUCK3_TICKS 4320
#define BUCK4_TICKS 5760
#define BUCK_WINDOW_TICKS 1000
#define END_OF_LINE 6760
#define IR_THRESHOLD 170
const int BUCK_TICKS[4] = {BUCK1_TICKS, BUCK2_TICKS, BUCK3_TICKS, BUCK4_TICKS};


//function prototypes

int getIRValue()
{
	int ac1, ac2, ac3, ac4, ac5;
	HTIRS2readAllACStrength(IRSENSOR, ac1, ac2, ac3, ac4, ac5);
	return ac3;
}

int searchForIR() {
	for (int ii = 0; ii < 4; ii++)
		{
			while (DRIVE_ENCODERS > BUCK_TICKS[ii] && DRIVE_ENCODERS < (BUCK_TICKS[ii] + BUCK_WINDOW_TICKS)) {
				if (getIRValue() > IR_THRESHOLD) {
					return ii;
				}
			}
		}
	return 3;
}


task main () {
	moveDriveTicks(DRIVE_SPEED, END_OF_LINE);
	int location = searchForIR();
	//score here
	moveDriveTicks(DRIVE_SPEED, END_OF_LINE);
	turnDrive90();
}
