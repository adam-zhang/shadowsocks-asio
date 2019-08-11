#ifndef __COMMANDLINEPARSER__H
#define __COMMANDLINEPARSER__H


class CommandLineParser
{
public:
	CommandLineParser();
	~CommandLineParser();
public:
	static void parse(int, char**);
};
#endif//__COMMANDLINEPARSER__H
