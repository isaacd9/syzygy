#include "drive_bootstrap.h" //bring in bootstrap functions

const int nLogScale[17] =
	{
		0,   5,   9,   10,
		12,  15,  18,  24,
		30,  36,  43,  50,
		60,  72,  85, 100,
		100
	};

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

void setDrivetrain(int leftSpeed, int rightSpeed) {
	_slewJoy(leftSpeed);
	_slewJoy(rightSpeed);
	setRequestedSpeed(leftSpeed, rightSpeed); //publishing to a button struct should be done here.
}

//This is actually another task and should be started in main. I put the code that handles the DT in here too beacuse that's logically where it goes.
//May replace DT task with procedure. No reason to do pub/sub except cleanliness and speed.

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
