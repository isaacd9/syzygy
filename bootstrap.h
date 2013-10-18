#define DRIVE_RIGHT motor[DRIVE_LEFT];
#define DRIVE_LEFT motor[DRIVE_RIGHT];

setDriveMotors(int speed) {
	DRIVE_RIGHT = speed;
	DRIVE_LEFT = speed;
}
