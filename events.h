//include subroutines here!

#include "drivetrain/drivetrain.h"

//function prototypes
void onDriveJoyMove(int left, int right);
void onOpJoyMove(int left, int right);

void onDriveJoyPressed(int button);
void onOpJoyPressed(int button);
void onDriveJoyReleased(int button);
void onOpJoyReleased(int button);

//Function declarations. Do late binding here!

void onDriveJoyMove(int left, int right) {
		setDrivetrain(left, right);
	}

void onOpJoyMove(int left, int right) {

	}

void onDriveJoyPressed(int button) {
		switch(button) {
			case 0:
				//Binding goes in here. Each case corresponds to button-1
			break;

			case 1:
			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
			break;

			case 5:
			break;

			case 6:
			break;

			case 7:
			break;

			case 8:
			break;

			case 9:
			break;

			case 10:
			break;

			case 11:
			break;

			default:
				writeDebugStreamLine("Button does not exist");
			break;
		}
}

void onOpJoyPressed(int button) {
		switch(button) {
			case 0:
			break;

			case 1:
			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
			break;

			case 5:
			break;

			case 6:
			break;

			case 7:
			break;

			case 8:
			break;

			case 9:
			break;

			case 10:
			break;

			case 11:
			break;

			default:
				writeDebugStreamLine("Button does not exist");
			break;
		}
}

void onDriveJoyReleased(int button) {
		switch(button) {
			case 0:
			break;

			case 1:
			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
			break;

			case 5:
			break;

			case 6:
			break;

			case 7:
			break;

			case 8:
			break;

			case 9:
			break;

			case 10:
			break;

			case 11:
			break;

			default:
				writeDebugStreamLine("Button does not exist");
			break;
		}
}

void onOpJoyReleased(int button) {
		switch(button) {
			case 0:
			break;

			case 1:
			break;

			case 2:
			break;

			case 3:
			break;

			case 4:
			break;

			case 5:
			break;

			case 6:
			break;

			case 7:
			break;

			case 8:
			break;

			case 9:
			break;

			case 10:
			break;

			case 11:
			break;

			default:
				writeDebugStreamLine("Button does not exist");
			break;
		}
}
