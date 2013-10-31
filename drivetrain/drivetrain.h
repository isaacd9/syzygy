//API Facing function prototypes

void setDrivetrain(int leftSpeed, int rightSpeed); //Main function for API call

int driveGetRequestedSpeed();
int getDriveLeft();
int getDriveRight();

//internal function prototypes

void _driveSetRequestedSpeed(int left, int right);
void _setDriveLeft(int speed);
void _setDriveRight(int speed);
void _setDriveMotors(int l, int r);

void _slewJoy(int &joyVal);

//declarations

const int nLogScale[17] =
	{
		0,   5,   9,   10,
		12,  15,  18,  24,
		30,  36,  43,  50,
		60,  72,  85, 100,
		100
	};

struct { //initalize structure to store requested speeds
		int leftDrive;
		int rightDrive;
} _driveSpeed;

_driveSpeed _driveRequestedSpeed;

//function bodies
void _driveSetRequestedSpeed(int left, int right) { //setter function for requested speed
		_driveRequestedSpeed.leftDrive=left;
		_driveRequestedSpeed.rightDrive=right;
	}

int driveGetRequestedSpeed(){ //getter method for requested speed
	int driveSpeed[2]= {_driveRequestedSpeed.leftDrive, _driveRequestedSpeed.rightDrive};
	return driveSpeed;
	}

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

void _slewJoy(int &joyVal) { //modify direct input to log scale
	//math gets done here
	if (USE_LOG_SCALE) {
		joyVal /= 8;
		if (joyVal >= 0) //slew based on log val
			joyVal = nLogScale[joyVal];
		else
			joyVal = - nLogScale[- joyVal];
	}
}

void setDrivetrain(int leftSpeed, int rightSpeed) { //This function is event facing
	_slewJoy(leftSpeed);
	_slewJoy(rightSpeed);
	_driveSetRequestedSpeed(leftSpeed, rightSpeed); //publishing to a button struct should be done here.
}
