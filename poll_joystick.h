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

bool checkButtons(int numButtons) {

	}

task pollJoystick() {
	while(true) {
			getJoystickSettings(joystick); //register joystick input
			int tempJoyLeft = DRIVE_JOY_LEFT;
			int tempJoyRight = DRIVE_JOY_RIGHT;
			_slewJoy(tempJoyLeft);
			_slewJoy(tempJoyRight);
			setRequestedSpeed(tempJoyLeft, tempJoyRight); //publishing to a button struct should be done here.

			wait1Msec(JOY_POLL_DELAY);
		}
}
