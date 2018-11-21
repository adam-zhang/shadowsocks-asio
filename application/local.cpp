#include <iostream>
#include "CommandLine.h"
#include "SocksServer.h"

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
	SocksServer server;
	server.run();
	return 0;
}
