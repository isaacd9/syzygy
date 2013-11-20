//init variables to store curr speed and dir
int driveJoyLeft;
int driveJoyRight;

int opJoyLeft;
int opJoyRight;

int lastDriveButtons[12]= {0,0,0,0,0,0,0,0,0,0,0,0}; //Store state
int lastOpButtons[12]= {0,0,0,0,0,0,0,0,0,0,0,0}; //Store state

task pollJoystick() {
	while(true) {
				getJoystickSettings(joystick);

				// Load stix into memory for this iteration

				driveJoyLeft = DRIVE_JOY_LEFT;
				driveJoyRight = DRIVE_JOY_RIGHT;

				opJoyLeft = OP_JOY_LEFT;
				opJoyRight = OP_JOY_RIGHT;

				onDriveJoyMove(driveJoyLeft, driveJoyRight); //These methods are stateless
				onOpJoyMove(opJoyLeft, opJoyRight);

				for(int i=0; i<11; i++) //Stateful implementation for the buttons
				{
					if(DRIVE_JOY_PRESSED(i+1)-lastDriveButtons[i] == 1) { //Call listeners
							onDriveJoyPressed(i);
							writeDebugStreamLine((char *) i);
						}
					if(OP_JOY_PRESSED(i+1)-lastOpButtons[i] == 1) {
							onOpJoyPressed(i);
						}
					if(DRIVE_JOY_PRESSED(i+1)-lastDriveButtons[i] == -1) {
							onDriveJoyReleased(i);
						}
					if(OP_JOY_PRESSED(i+1)-lastOpButtons[i] == -1) {
							onOpJoyReleased(i);
						}
					lastDriveButtons[i]=DRIVE_JOY_PRESSED(i+1); //Update state
					lastOpButtons[i]=OP_JOY_PRESSED(i+1);
				}
				wait1Msec(JOY_POLL_DELAY);
		}
}
