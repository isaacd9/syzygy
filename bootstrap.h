struct { //initalize structure to store requested speeds
		int leftDrive;
		int rightDrive;
} _driveSpeed;

_driveSpeed requestedSpeed;

void setRequestedSpeed(int left, int right) { //setter function for requested speed
		requestedSpeed.leftDrive=left;
		requestedSpeed.rightDrive=right;
	}

int getRequestedSpeed(){ //getter method for requested speed
	int driveSpeed[2]= {requestedSpeed.leftDrive, requestedSpeed.rightDrive};
	return driveSpeed;
	}

void setDriveMotors(int speed) { //set drive motor speed directly
	motor[DRIVE_RIGHT] = speed;
	motor[DRIVE_LEFT] = speed;
}

void setDriveRight(int speed) { //set right speed directly
	motor[DRIVE_RIGHT] = speed;
}

void setDriveLeft(int speed) { //set left speed directly
	motor[DRIVE_LEFT] = speed;
}
