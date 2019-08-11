#ifndef __OPTIONS__H
#define __OPTIONS__H

#include <string>
#include "enums.h"

class Options
{
	enum MODE
	{
		TCP,
		UDP,
		TCP_AND_UDP,
	};
public:
	Options();
	~Options();
private:
	short localPort_;
	std::string localAddress_;
	short serverPort_;
	std::string serverHost_;
	std::string password_;
	int timeout_;
	EncryptMethods method_;
	std::string user_;
	std::string pidFile_;
	int maxNumberFiles_;
	std::string netowrkInterface_;
	std::string localAddressBind_;
	MODE mode_;
public:
	MODE mode()
	{ return mode_; }
	void setMode(MODE value)
	{ mode_ = value; }
	const std::string localAddressBind()
	{ return localAddressBind_; }
	void setLocalAddressBind(const std::string& value)
	{ localAddressBind_ = value; }
	const std::string& networkInterface()
	{ return netowrkInterface_; }
	void setNetworkInterface(std::string& value)
	{ netowrkInterface_ = value; }
	int maxNumberFiles()
	{ return maxNumberFiles_; }
	void setMaxNumberFiles(int value)
	{ maxNumberFiles_ = value; }
	std::string pidFile()
	{ return pidFile_; }
	void setPidFile(const std::string& value)
	{ pidFile_ =  value; }
	std::string user()
	{ return user_; }
	void setUser(const std::string& value)
	{ user_ = value; }
	const std::string localAddress()
	{ return localAddress_; }
	void setLocalAddress(const std::string& value)
	{ localAddress_ = value; }
	EncryptMethods method( )
	{ return method_; }
	void setMethod(EncryptMethods value)
	{ 
		method_ = value;
       	}
	int timeout()
	{ return timeout_; }
	void setTimeout(int value)
	{ timeout_ = value; }
	const std::string& passsword()
	{ return password_; }
	void setPassword(const std::string& value)
	{ password_ = value; }
	short localPort()
	{ return localPort_; }
	void setLocalPort(short value)
	{ localPort_ = value; }
	short serverPort()
	{ return serverPort_; }
	void setServerPort(short value)
	{ serverPort_ =  value; }
	void setServerHost(const std::string& value)
	{ serverHost_ = value; }
	const std::string& serverHost()
	{ return serverHost_; }
};
#endif//__OPTIONS__H
