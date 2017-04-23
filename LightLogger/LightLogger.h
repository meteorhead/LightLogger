#pragma once

/* The purpose of LightLogger is to provide a minimalistic thread-safe logging facility
*  that outputs log messages (including user defined types) to console or file
*/


#include <iostream>
#include <fstream>

//aliases 
#define LIGHTLOG LightLogger::getLightLoggerInstance()
#define LOGLEVEL(lvl) LightLogger::getLightLoggerInstance().setLoggingLevel(lvl)

using std::cout;
using std::endl;
using std::ofstream;

class LightLogger
{

public:
// Levels of log
enum class LogLevel { INFO = 0, WARNING = 1, ERROR = 2 };

//Make it thread-safe
static LightLogger & getLightLoggerInstance()
{
	static LightLogger lightLog;
	return lightLog;
}

// Log messages to file and console
template <typename T>
void log(const T &iMessage)
{
	ofstream logFile;
	logFile.open("log.txt", std::ios::out | std::ios::app);

		switch (static_cast<int>(getLoggingLevel()))
		{
		case 1:
			cout << "[WARNING] " << iMessage << endl;
			if (logFile.is_open()) logFile << "[WARNING] " << iMessage << endl;
			break;
		case 2:
			cout << "[ERROR] " << iMessage << endl;
			if (logFile.is_open()) logFile << "[ERROR] " << iMessage << endl;
			break;
		default:
			cout << "[INFO] " << iMessage << endl;
			if (logFile.is_open()) logFile << "[INFO] " << iMessage << endl;
		}
	logFile.close();
    }

void setLoggingLevel(LogLevel iLvl)
{
	_logLevel = iLvl;
}

LogLevel getLoggingLevel() const
{
	return _logLevel;
}
template <typename T>
LightLogger& operator<< (const T &iMessage)
{
	log<T>(iMessage);
	return *this;
}
private:

//Prevent class instantiation
LightLogger() = default;
LogLevel _logLevel = LogLevel::INFO;
};