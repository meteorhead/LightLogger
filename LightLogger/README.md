Light Logger is a written-on-a-sunday-afternoon logger


**HOW TO COMPILE**
LightLogger is a header only logging facility along with a main.cpp as an entry point
Developed with visual studio 2015, simply import the solution file and build it
++Deps:
  GoogleTest is needed as I used it for unit tests

** MOTIVATION AND RATIONALE**
  My take on it is to create a Meyer's like thread-safe LightLogger singleton (thanks to c++11)


•	I have implemented an enum class for log levels {INFO (default), WARNING, ERROR}

LOGLEVEL(LightLogger::LogLevel::INFO)

•	Then you specify the message to log


LIGHTLOG << "Message to log"

•	I have added a dual log for standard output (cout) and a file (ofstream)
•	Templates were used to enable the output of userdefined types


** IMPROVEMENTS**

   I think that using the tee_device from boost could simplify the "log" method
