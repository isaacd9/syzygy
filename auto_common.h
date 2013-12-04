//definitions
#define DRIVE_ENCODERS -nMotorEncoder[DRIVE_RIGHT]
#define ARM_ENCODERS abs(nMotorEncoder[ARM])

#define ENCODER_TURN_SPEED 70
#define FORTY_FIVE_DEGREES 125
#define NINETY_DEGREES 250
#define ONE_EIGHTY_DEGREES 500
#define THREE_SIXTY_DEGREES 1000

//includes
#include "drivetrain2.h"
#include "flag_raiser.h"
#include "arm.h"
#include "intake.h"

//Function prototypes
void moveDriveTicks(int speed, int numTicks);
void turnDriveTicks(int speed, int numTicks); //To turn right, speed is <0
void turnDrive45(); //Cannot set speeds for this as the speeds need to be preset for a predictable angle
void turnDrive90();
void turnDrive180();
void turnDrive360();
void stopDrive();

void moveArmTicks(int speed, int numTicks);

//Function bodies

void moveDriveTicks(int speed, int numTicks) {
	while(DRIVE_ENCODERS < numTicks) {
		_setDriveMotors(speed,speed);
		writeDebugStreamLine("%d", DRIVE_ENCODERS);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void turnDriveTicks(int speed, int numTicks) {
	while(DRIVE_ENCODERS < numTicks) {
		_setDriveMotors(speed,-speed);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void turnDrive45() {
	turnDriveTicks(ENCODER_TURN_SPEED, FORTY_FIVE_DEGREES);
}

void turnDrive90() {
	turnDriveTicks(ENCODER_TURN_SPEED, NINETY_DEGREES);
}

void turnDrive180() {
	turnDriveTicks(ENCODER_TURN_SPEED, ONE_EIGHTY_DEGREES);
}

void turnDrive360() {
	turnDriveTicks(ENCODER_TURN_SPEED, THREE_SIXTY_DEGREES);
}

void stopDrive() {
	_setDriveMotors(0,0);
}

void moveArmTicks(int speed, int numTicks) {
	while(ARM_ENCODERS < numTicks) {
		_setArmMotor(speed);
		wait1Msec(5);
	}
	_setArmMotor(0);
}

//Definitions
void runDriveTime(int speed, int time);
void turnTime(int speed, int time);
void runArmTime(int speed, int time);
void runIntakeTime(int speed, int time);

//Bodies
void runDriveTime(int speed, int time) {
	for (int i=time; i>=0; i=i-5) {
		_setDriveMotors(speed, speed);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void turnTime(int speed, int time) {
	for (int i=time; i >=0; i=i-5) {
		_setDriveMotors(speed, -speed);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void runArmTime(int speed, int time) {
	for (int i=time; i>=0; i=i-5) {
		_setArmMotor(speed);
		wait1Msec(5);
	}
	_setArmMotor(0);
}

void runIntakeTime(int speed, int time) {
	for (int i=time; i >= 0; i=i-5) {
		_setIntakeMotor(speed);
		wait1Msec(5);
	}
	_setIntakeMotor(0);
}
