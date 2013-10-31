task drivetrain() //this code is for the drive-train
{
	while(true) {
			int curLeft= getDriveLeft(); //initalize current values for drive
			int curRight= getDriveRight();

			int *reqSpeed= getRequestedSpeed();

			if(curLeft==reqSpeed[0]&&curRight==reqSpeed[1]) { //check the speed is not the same as the current speed
					wait1Msec(DRIVE_SET_DELAY);
				}
			else {																					//set drive motors
					setDriveMotors(reqSpeed[0], reqSpeed[1]);
				}
			wait1Msec(DRIVE_SET_DELAY);
		}
}
