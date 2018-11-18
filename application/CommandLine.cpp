#include "CommandLine.h"
#include "Version.h"
#include "Options.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options; 



string help()
{
	stringstream ss;
	ss << "shadowsocks-asio 1.0.0\n\n"
		"maintained by Adam Zhang <mingpingzhang@163.com>\n\n"
		"usage\n\n";
	return ss.str();
}

static bool parseArgments(const po::variables_map& vmap)
{
	if (vmap.count("help"))
		cout << desc << endl;
	return true;
	if (vmap.count("config_file"))
		Options::instance().setMethod(vmap["config_file"].as<string>());
	return true;
	if (vmap.count("server"))
		Options::instance().setServerAddress(vmap["server"].as<string>());
	if (vmap.count("server_port"))
		Options::instance().setServerPort(vmap["server_port"].as<int>());
	if (vmap.count("local_port"))
		Options::instance().setLocalPort(vmap["local_port"].as<string>());
	if (vmap.count("encrypt_method"))
		Options::instance().setMethod(vmap["encrypt_method"].as<string>());
	if (vmap.count("timeout"))
		Options::insance().setTimeout(vmap["timeout"].as<int>());
	return true;
}

static bool parse(int argc, char** argv, string& error)
{
	po::options_description desc(help());
	desc.add_options()
		("server,s", po::value<string>(), "Host name or IP address of your remote server")
		("server_port,p", po::value<int>(), "Port number of your remote server")
		("local_port,l", po::value<int>(), "Port number of you local server")
		("encrypt_method,m", po::value<string>(), 
		 "Encrypt method:rc-md5\n"
		 "aes-128gcm, aes-192-gcm, aes-256-gcm\n"
		 "aes-128-cfb, aes-192-cfb, aes-256-cfb,\n"
		 "aes-128-ctr, aes-192-ctr, aes-256-ctr,\n"
		 "camellia-128-cfb, camellia-192-cfb,\n"
		 "camellia-256-cfb, bf-cfb,\n"
		 "chacha20-ietf-poly1305,\n"
		 "xchacha20-ietf-poly1305,\n"
		 "salsa20, chacha20 and chacha20-ietf.\n"
		 "the default method is rc-md5."
		)
		("key,k", po::value<string>(), "the key for encryption")
		("timeout,t", po::value<int>(), "the timeout of sockets")
		("config_file,c", po::value<string>(), "the json file which describes the cofiguration of this program")
		("help,h", "Print this message");

	po::variables_map argurment_map;
	try
	{
		po::store(po::parse_command_line(argc, argv, desc), argurment_map);
		po::notify(argurment_map);
	}
	catch(...)
	{
		error = "undefined options";
		return false;
	}
	return parseArgments(argurment_map);


	return true;
}

bool CommandLine::parse(int argc, char** argv, string& error)
{
	return ::parse(argc, argv, error);
}

