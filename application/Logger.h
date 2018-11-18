#ifndef __LOGGER__H
#define __LOGGER__H

#include <string>

class Logger
{
	private:
		//static void trace(const std::string&);
		//static void trace(const std::string&, size_t );
		//static void trace(const std::string&, const std::string&);
		static void debug(const std::string&);
		static void debug(const std::string&, size_t);
		static void debug(const std::string&, const std::string&);
};
#endif//__LOGGER__H
