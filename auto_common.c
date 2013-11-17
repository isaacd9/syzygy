//definitions
#define DRIVE_ENCODERS abs(nMotorEncoder[DRIVE_LEFT])+abs(nMotorEncoder[DRIVE_RIGHT])/2
#define ARM_ENCODERS abs(nMotorEncoder[ARM])

//includes
#include "drivetrain2.h"
#include "flag_raiser.h"
#include "arm.h"

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
	}
}

void turnDriveTicks(int speed, int numTicks) {
	while(DRIVE_ENCODERS < numTicks) {
		_setDriveMotors(speed,-speed);
	}
}

void turnDrive45() {
	turnDriveTicks(TURN_SPEED, FORTY_FIVE_DEGREES);
}

void turnDrive90() {
	turnDriveTicks(TURN_SPEED, NINETY_DEGREES);
}

void turnDrive180() {
	turnDriveTicks(TURN_SPEED, ONE_EIGHTY_DEGREES);
}

void turnDrive360() {
	turnDriveTicks(TURN_SPEED, THREE_SIXTY_DEGREES);
}

void stopDrive() {
	_setDriveMotors(0,0);
}

void moveArmTicks(int speed, int numTicks) {
	while(ARM_ENCODERS < numTicks) {
		_setArmMotor(speed, speed);
	}
}
