//function prototypes

void hangRobot();

//function bodies

void hangRobot() { //hangs robot
	servoTarget[HANG] = SERVO_HANG_POSITION;
	servoTarget[HANG2] = SERVO_HANG_POSITION;
}
