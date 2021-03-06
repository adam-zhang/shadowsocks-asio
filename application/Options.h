#ifndef __OPTIONS__H
#define __OPTIONS__H

#include "Properties.h"
#include "Singleton.h"
#include <string>

class Options : public Singleton<Options>
{
	public:
		Options();
		~Options();

	PROPERTY(std::string, serverAddress, setServerAddress);
	PROPERTY(int, serverPort, setServerPort);
	PROPERTY(int, localPort, setLocalPort);
	PROPERTY(std::string, key, setKey);
	PROPERTY(std::string, method, setMethod);
	PROPERTY(int, timeout, setTimeout);
};
#endif//__OPTIONS__H
