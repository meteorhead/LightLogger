#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/* The purpose of LightLogger is to provide a minimalistic thread-safe logging facility
*  that outputs log messages (including user defined types) to console or file 
*/
class LightLogger
{
private:

	//Prevent class instantiation
	LightLogger() = default;
public:
	enum class LogLevel { INFO = 0, WARNING = 1, ERROR = 2 };

	//Make it thread-safe
	static LightLogger & getLightLoggerInstance()
	{
		static LightLogger lightLog;
		return lightLog;
	}

	// Log messages to console
	template <typename T>
	void logToConsole(const T &iMessage, LogLevel iLevel = LogLevel::INFO)
	{
		switch (static_cast<int>(iLevel))
		{
		case 1:
			cout << "[WARNING] " << iMessage << endl;
			break;
		case 2:
			cout << "[ERROR] " << iMessage << endl;
			break;
		default:
			cout << "[INFO] " << iMessage << endl;
		}
		
	}

};

