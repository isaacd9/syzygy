//API Facing function prototypes

void setArm(int speed); //Main function for API call

int getArm();

//internal function prototypes

void _setArmMotors(int speed);

void _slewArmJoy(int &joyVal);

//declarations

const int nArmLogScale[17] =
	{
		0,   5,   9,   10,
		12,  15,  18,  24,
		30,  36,  43,  50,
		60,  72,  85, 100,
		100
	};

//function bodies
void _setArmMotors(int speed) { //set arm
	motor[ARM_LEFT] = speed;
	motor[ARM_RIGHT] = speed;
}

int getArm() { //getter method for left arm
	return motor[ARM_LEFT];
	}

void _slewArmJoy(int &joyVal) { //modify direct input to log scale
	if (USE_LOG_SCALE) {
		joyVal /= 8;
		if (joyVal >= 0) //slew based on log val
			joyVal = nArmLogScale[joyVal];
		else
			joyVal = - nArmLogScale[- joyVal];
	}
}

void setArm(int speed) { //This function is event facing
	_slewArmJoy(speed);
	_setArmMotors(speed);
}
