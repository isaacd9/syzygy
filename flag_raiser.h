//function prototypes

void driveFlagForward();
void driveFlagBack();
void stopFlag();

//function bodies

void driveFlagForward()
{
	motor[FLAG_RAISER] = FLAG_SPEED; //defined in main
}

void driveFlagBack()
{
	motor[FLAG_RAISER] = -FLAG_SPEED; //defined in main
}

void stopFlag()
{
	motor[FLAG_RAISER] = 0;
}
