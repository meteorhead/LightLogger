#include "LightLogger.h"


int main()
{
	LightLogger::getLightLoggerInstance().logToConsole("Trouble in paradise",LightLogger::LogLevel::WARNING);
	return 0;
}