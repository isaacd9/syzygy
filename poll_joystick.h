int _slewJoy(int l, int r) { //modify direct input to log scale
	//math gets done here
	int returnArray[2]={l,r};
	return returnArray;
}


task pollJoystick() {
	while(true) {
			getJoystickSettings(joystick); //register joystick input
			//any additional post processing
			wait1Msec(10);
		}
}
