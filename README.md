syzygy
======

code that powers the robot for FTC team 3231.

In order to bind events to joystick commands, simply call the function within the appropriate case statement within the event handler function.

For example, if I had some function called moveRobot() that moved the robot and I wished to bind it to when button 2 was clicked, it would go here:

```
void onDriveJoyPressed(int button) {

	...
	case 1:
		moveRobot();
	break;
}
```
