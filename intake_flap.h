//function prototypes

void flapForward();
void flapBack();
//function bodies

void flapForward() {
		servo[FLAP_SERVO] = (230);
	}

void flapBack() {
		servo[FLAP_SERVO] = 100;
	}
