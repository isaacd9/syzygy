//include subroutines here!

#include "drivetrain2.h"
#include "flag_raiser.h"
#include "arm.h"
//#include "hanging.h"
#include "intake.h"
#include "intake_flap.h"

//function prototypes

void onDriveJoyMove(int left, int right); //Binding for drive sticks
void onOpJoyMove(int left, int right); //Binding for op sticks

void onDriveJoyPressed(int button); //Bindings for drive joy button pressed
void onOpJoyPressed(int button); //Bindings for op joy button pressed
void onDriveJoyReleased(int button); //Bindings for drive joy released
void onOpJoyReleased(int button); //Bindings for op joy released

//Function declarations. Do binding here!

//All bindings here should be STATELESS
void onDriveJoyMove(int left, int right) {
		setDrivetrain(left, right);
	}

void onOpJoyMove(int left, int right) {
		setArm(left);
		setIntake(right);
	}

//Binding goes in here. Each case corresponds to button-1

//Bindings here can be stateful
void onDriveJoyPressed(int button) {
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

void onOpJoyPressed(int button) {
		switch(button) {
			case 0:
			break;

			case 1:
				flapForward();
			break;

			case 2:
			break;

			case 3:
				flapBack();
			break;

			case 4:
			break;

			case 5:
			break;

			case 6:
				driveFlagBack();
			break;

			case 7:
				driveFlagForward();
			break;

			case 8:
				//hangRobot();
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
				stopFlag();
			break;

			case 7:
				stopFlag();
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
