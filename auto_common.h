//definitions
#define RIGHT_ENCODER -nMotorEncoder[DRIVE_RIGHT]
#define LEFT_ENCODER -nMotorEncoder[DRIVE_lEFT]
#define DRIVE_ENCODERS (RIGHT_ENCODER+LEFT_ENCODER)/2

#define ENCODER_TURN_SPEED 70
#define FORTY_FIVE_DEGREES 125
#define NINETY_DEGREES 250
#define ONE_EIGHTY_DEGREES 500
#define THREE_SIXTY_DEGREES 1000

//Function prototypes
void moveDriveTicks(int speed, int numTicks);
void turnDriveTicks(int speed, int numTicks); //To turn right, speed is <0
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

void turnDriveRightTicks(int speed, int numTicks) {
	while(LEFT_ENCODER < numTicks) {
		_setDriveMotors(speed,-speed);
		wait1Msec(5);
	}
	_setDriveMotors(0,0);
}

void turnDriveLeftTicks(int speed, int numTicks) {
	while(RIGHT_ENCODER < numTicks) {
		_setDriveMotors(-speed, speed);
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
