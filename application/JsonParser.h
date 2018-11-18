#ifndef __JSONPARSER__H
#define __JSONPARSER__H

#include <string>

class JsonParser
{
	private:
		JsonParser();
		~JsonParser();
	public:
		static bool parseConfiguration(const std::string& fileName);
};
#endif//__JSONPARSER__Hy
