//API Facing function prototypes

void setIntake(int speed); //Main function for API call

int getIntake();

//internal function prototypes

void _setIntakeMotor(int speed);

void _slewIntakeJoy(int &joyVal);

//declarations

const int nIntakeLogScale[17] =
        {
                0,   5,   9,   10,
                12,  15,  18,  24,
                30,  36,  43,  50,
                60,  72,  85, 100,
                100
        };

//function bodies
void _setIntakeMotor(int speed) { //set intake
		motor[INTAKE] = speed;
}

int getIntake() { //getter method for Intake
	return motor[INTAKE];
	}

void _slewIntakeJoy(int &joyVal) { //modify direct input to Log scale
			if (USE_LOG_SCALE) {
							joyVal /= 8;
							if (joyVal >= 0) //slew based on log val
											joyVal = nIntakeLogScale[joyVal];
									else
											joyVal = - nIntakeLogScale[- joyVal];
			}
}

void setIntake(int speed) {//This function is event facing
		_slewIntakeJoy(speed);
		_setIntakeMotor(speed);
}
