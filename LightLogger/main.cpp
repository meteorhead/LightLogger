#include "LightLogger.h"


int main()
{
	LOGLEVEL(LightLogger::LogLevel::INFO);
	LIGHTLOG << "Hello LightLogger!";

	return 0;
}