//definitions
#define RIGHT_ENCODER -nMotorEncoder[DRIVE_LEFT]
#define LEFT_ENCODER -nMotorEncoder[DRIVE_LEFT]
#define DRIVE_ENCODERS LEFT_ENCODER

//Function prototypes
void moveDriveTicks(int speed, int numTicks);
void turnDriveRightTicks(int speed, int numTicks); //To turn right, speed is <0
void turnDriveLeftTicks(int speed, int numTicks);
void zeroEncoders();
void stopDrive();

//Function bodies

void moveDriveTicks(int speed, int numTicks) {
	while(DRIVE_ENCODERS < numTicks) {
		_setDriveMotors(speed,speed);
		writeDebugStreamLine("%d", DRIVE_ENCODERS);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void moveDriveBack(int speed, int numTicks) {
	while(DRIVE_ENCODERS > numTicks) {
		_setDriveMotors(-speed,-speed);
		writeDebugStreamLine("%d", DRIVE_ENCODERS);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void turnDriveRightTicks(int speed, int numTicks) {
	while(LEFT_ENCODER < numTicks) {
		_setDriveMotors(speed,-speed);
		wait1Msec(5);
		writeDebugStreamLine("%d", DRIVE_ENCODERS);
	}
	_setDriveMotors(0,0);
}

void turnDriveLeftTicks(int speed, int numTicks) {
	while(LEFT_ENCODER > numTicks) {
		_setDriveMotors(-speed, speed);
		writeDebugStreamLine("%d", DRIVE_ENCODERS);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void zeroEncoders() {
	nMotorEncoder[DRIVE_RIGHT]=0;
	nMotorEncoder[DRIVE_LEFT]=0;

}

void stopDrive() {
	_setDriveMotors(0,0);
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
