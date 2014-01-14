int lastMotors[2] = {0,0}; //Store previous state of motors
int timeElapsed = 0;

void macroRecorder() {
	timeElapsed += 10; //Increase time that the current instruction has been running for

	if(getDriveLeft() != lastMotors[0]	|| getDriveRight() != lastMotors[1]) {
		writeDebugStreamLine("Left: %d;", lastMotors[0]); //Write instruction to debug stream
		writeDebugStream(" Right: %d", lastMotors[1]);
		writeDebugStream(" Time: %d", timeElapsed);

		timeElapsed = 0; // Reset state
		lastMotors[0] = getDriveLeft();
		lastMotors[1]= getDriveRight();
	}
}
