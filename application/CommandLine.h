#ifndef __COMMANDLINE__H
#define __COMMANDLINE__H

#include <memory>

class Options;

class CommandLine
{
	private:
		CommandLine();
		~CommandLine();
	public:
		static bool parse(int, char**, std::string& error);

};
#endif//__COMMANDLINE__H
