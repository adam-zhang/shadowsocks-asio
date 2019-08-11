#ifndef __JSONPARSER__H
#define __JSONPARSER__H

#include <string>

class JsonParser
{
private:
	JsonParser();
	~JsonParser();
public:
	static void parse(const std::string&);
};
#endif//__JSONPARSER__H
