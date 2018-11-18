#include "Logger.h"
#include <sstream>
#include <iostream>

using namespace std;

void Logger::debug(const string& notice)
{
	cout << "Debug: "  << notice << endl;
}

void Logger::debug(const string& notice, size_t value)
{
	stringstream ss;
	ss << notice << ":" << value;
	debug(ss.str());
}




