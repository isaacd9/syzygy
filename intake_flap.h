//function prototypes

void flapOpen();
void flapClosed();
void toggleFlap();

bool _flapState = false;
//function bodies

void flapOpen() {
		servo[FLAP_SERVO] = (230);
		_flapState = true;
	}

void flapClosed() {
		servo[FLAP_SERVO] = 100;
		_flapState = false;
	}

void toggleFlap() {
	if (!_flapState) {
		flapOpen();
	}
	else {
		flapClosed();
		}
}
