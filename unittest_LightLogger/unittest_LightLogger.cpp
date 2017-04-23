// unittest_LightLogger.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <gtest\gtest.h>
#include <LightLogger.h>
#include <string>

// This tests the log level setup
TEST(LogLevelTest, LightLogTest)
{
	// INFO lvl
	LOGLEVEL(LightLogger::LogLevel::INFO);
	EXPECT_EQ(LightLogger::LogLevel::INFO, LightLogger::getLightLoggerInstance().getLoggingLevel());
	// WARNING lvl
	LOGLEVEL(LightLogger::LogLevel::WARNING);
	EXPECT_EQ(LightLogger::LogLevel::WARNING, LightLogger::getLightLoggerInstance().getLoggingLevel());
	// ERROR lvl
	LOGLEVEL(LightLogger::LogLevel::ERROR);
	EXPECT_EQ(LightLogger::LogLevel::ERROR, LightLogger::getLightLoggerInstance().getLoggingLevel());
}

// Log a message in a file and then verify that it is the same as expected "[INFO] test"

TEST(LogMessageTestFromFile, LightLogTest)
{

	std::ofstream ofs;
	ofs.open("log.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	LOGLEVEL(LightLogger::LogLevel::INFO);
	LIGHTLOG << "test";
	std::ifstream file;
	file.open("log.txt");
	std::string output, toTest = "[INFO] test";
	std::getline(file,output);
	file.close();
	ASSERT_STREQ(toTest.c_str(), output.c_str());
}


// Test the output of userdefined data
struct Dummy
{
	int age = 99;
	std::string name = "dummy";
	friend std::ostream & operator<<(std::ostream & os, const Dummy & i)
	{
		os << "name " << i.name << " age " << i.age;
		return os;
	}
};

TEST(LogMessageTestForUserData, LightLogTest)
{
	// user type 


	std::ofstream ofs;
	ofs.open("log.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	LOGLEVEL(LightLogger::LogLevel::INFO);
	Dummy d;
	LIGHTLOG << d;
	std::ifstream file;
	file.open("log.txt");
	std::string output, toTest = "[INFO] name dummy age 99";
	std::getline(file, output);
	ASSERT_STREQ(toTest.c_str(), output.c_str());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
