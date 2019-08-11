#include <iostream>
#include "CommandLineParser.h"

using namespace std;

int main(int argc, char** argv)
{
	CommandLineParser::parse(argc, argv);
	return 0;
}
