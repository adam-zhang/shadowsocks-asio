#ifndef __OPTIONS__H
#define __OPTIONS__H

#include <string>

class Options
{
	enum Method
	{
		RC4_MD5,
		AES_128_GCM,
		AES_192_GCM,
		AES_256_GCM,
		AES_128_CFB,
		AES_192_CFB,
		AES_256_CFB,
		AES_128_CTR,
		AES_192_CTR,
		AES_256_CTR,
		camelia_128_cfb,
		camelia_192_cfb,
		camelia_256_cfb,
		bf_cfb,
		chacha20_ietf_poly1305,
		xchacha20_ietf_poly1305,
		salsa20,
		chacha20,
		chacha20_ietf,
	};
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
	short remotePort_;
	std::string remoteAddress_;
	std::string password_;
	int timeout_;
	Method method_;
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
	Method method( )
	{ return method_; }
	void setMethod(Method value)
	{ method_ = value; }
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
	short remotePort()
	{ return remotePort_; }
	void setRemotePort(short value)
	{ remotePort_ =  value; }
};
#endif//__OPTIONS__H
