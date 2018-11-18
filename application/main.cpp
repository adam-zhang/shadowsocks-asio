#include <iostream>
#include "CommandLine.h"

using namespace std;

int main(int argc, char** argv)
{
	string error;
	auto ret = CommandLine::parse(argc, argv, error);
	if (!ret)
	{
		cout << error << endl;
		return -1;
	}
	return 0;
}
