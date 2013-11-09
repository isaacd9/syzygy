//API Facing function prototypes

void setDrivetrain(int leftSpeed, int rightSpeed); //Main function for API call

int getDriveLeft();
int getDriveRight();

//internal function prototypes

void _setDriveLeft(int speed);
void _setDriveRight(int speed);
void _setDriveMotors(int l, int r);

void _slewDriveJoy(int &joyVal);

//declarations

const int nDriveLogScale[17] =
	{
		0,   5,   9,   10,
		12,  15,  18,  24,
		30,  36,  43,  50,
		60,  72,  85, 100,
		100
	};

//function bodies

void _setDriveMotors(int l, int r) { //set drive motor speed directly
	motor[DRIVE_RIGHT] = r;
	motor[DRIVE_LEFT] = l;
}

void _setDriveRight(int speed) { //set right speed directly
	motor[DRIVE_RIGHT] = speed;
}

void _setDriveLeft(int speed) { //set left speed directly
	motor[DRIVE_LEFT] = speed;
}

int getDriveLeft() { //getter method for left drive
	return motor[DRIVE_LEFT];
	}

int getDriveRight() { //getter method for right drive
	return motor[DRIVE_RIGHT];
}

void _slewDriveJoy(int &joyVal) { //modify direct input to log scale
	if (USE_LOG_SCALE) {
		joyVal /= 8;
		if (joyVal >= 0) //slew based on log val
			joyVal = nDriveLogScale[joyVal];
		else
			joyVal = - nDriveLogScale[- joyVal];
	}
}

void setDrivetrain(int leftSpeed, int rightSpeed) { //This function is event facing
	_slewDriveJoy(leftSpeed);
	_slewDriveJoy(rightSpeed);
	_setDriveMotors(leftSpeed, rightSpeed); //publishing to a button struct should be done here.
}
