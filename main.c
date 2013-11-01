#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  motorA,          DRIVE_LEFT,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          DRIVE_RIGHT,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
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
#define DEBUGGER writeDebugStreamLine;
static const bool USE_LOG_SCALE=true;

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "initialize.h"
#include "events.h" //Order is important here. This must be included above poll_joystick
#include "poll_joystick.h"

//May replace DT task with procedure. No reason to do pub/sub except cleanliness and (speed?).
task drivetrain() //this code is for the drive-train
{
	while(true) {
			int curLeft= getDriveLeft(); //initalize current values for drive
			int curRight= getDriveRight();

			int *reqSpeed= driveGetRequestedSpeed();

			if(curLeft!=reqSpeed[0]||curRight!=reqSpeed[1])	{		  //check the speed is not the same as the current speed
					_setDriveMotors(reqSpeed[0], reqSpeed[1]);
				}
			wait1Msec(DRIVE_SET_DELAY);
		}
}

task main() {
  initializeRobot();
	StartTask(pollJoystick); //Begin to poll joystick for input
	StartTask(drivetrain);

  while (true) {
		wait1Msec(100);
  }
}
