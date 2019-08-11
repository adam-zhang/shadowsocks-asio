#include "CommandLineParser.h"
#include "GlobalVariable.h"
#include "enums.h"
#include "Options.h"
#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include <map>

using namespace std;

CommandLineParser::CommandLineParser()
{
}

CommandLineParser::~CommandLineParser()
{
}

string printHelpMessage()
{
	cout << "shadowsocks-asio 1.0.0\n\n"
  	"maintained by Mingping (Adam) Zhang <mingpingzhang@163.com>\n\n"
	"usage:\n\n"
    	"ss-local\n\n"
       "\t-s, --server_host        Host name or IP address of your remote server.\n"
       "\t-p, --server_port        Port number of your remote server.\n"
       "\t-l, --local_port         Port number of your local server.\n"
       "\t-k, --password           Password of your remote server.\n"
       "\t-m, --encrypt_method     Encrypt method: rc4-md5,\n"
       "\t                         aes-128-gcm, aes-192-gcm, aes-256-gcm,\n"
       "\t                         aes-128-cfb, aes-192-cfb, aes-256-cfb,\n"
       "\t                         aes-128-ctr, aes-192-ctr, aes-256-ctr,\n"
       "\t                         camellia-128-cfb, camellia-192-cfb,\n"
       "\t                         camellia-256-cfb, bf-cfb,\n"
       "\t                         chacha20-ietf-poly1305,\n"
       "\t                         xchacha20-ietf-poly1305,\n"
       "\t                         salsa20, chacha20 and chacha20-ietf.\n"
       "\t                         The default cipher is rc4-md5.\n\n"
       "\t-t, --timeout -t         Socket timeout in seconds.\n"
       "\t-c, --config-file        The path to config file.\n"
       "\t-h, --help               Print this message.\n";
}


EncryptMethods queryMethod(const string& method)
{
	map<string, EncryptMethods> m = 
	{
		{"aes-128-gcm", EncryptMethods::AES_128_GCM},
		{"aes-192-gcm", EncryptMethods::AES_192_GCM},
		{"aes-256-gcm", EncryptMethods::AES_256_GCM},
		{"aes-128-cfb", EncryptMethods::AES_128_CFB},
		{"aes-192-cfb", EncryptMethods::AES_192_CFB},
		{"aes-256-cfb", EncryptMethods::AES_256_CFB},
       		{"aes-128-ctr", EncryptMethods::AES_128_CTR},
		{"aes-192-ctr", EncryptMethods::AES_192_CTR},
		{"aes-256-ctr", EncryptMethods::AES_256_CTR},
       		{"camellia-128-cfb", EncryptMethods::camellia_128_cfb},
		{"camellia-192-cfb", EncryptMethods::camellia_192_cfb},
		{"camellia-256-cfb", EncryptMethods::camellia_256_cfb},
		{"bf-cfb", EncryptMethods::bf_cfb},
       		{"chacha20-ietf-poly1305", EncryptMethods::chacha20_ietf_poly1305},
       		{"xchacha20-ietf-poly1305",  EncryptMethods::xchacha20_ietf_poly1305},
		{"salsa20", EncryptMethods::salsa20},
		{"chacha20", EncryptMethods::chacha20},
		{"chacha20-ietf", EncryptMethods::chacha20_ietf},
		{"rc4-md5", EncryptMethods::rc4_md5}

	};
	if (m.find(method) == m.end())
	{
		cout << "invalid" << endl;
		return EncryptMethods::INVALID_VALUE;
	}
	return m[method];
}

static bool parseCommandLine(const vector<option>& options, int argc, char** argv)
{
	int options_index = 0;
	while(true)
	{
		int c = getopt_long(argc, argv, "hm:s:", &options[0], &options_index);
		if (c == -1)
			break;
		cout << "c:" << char(c) << endl;
		switch(c)
		{
			case 'h':
				printHelpMessage();
				break;
			case 'm':
				GlobalVariable::instance().option()->setMethod(queryMethod(optarg));
				break;
			case 's':
				GlobalVariable::instance().option()->setServerHost(optarg);
				break;
		}
	}
}

void CommandLineParser::parse(int argc, char** argv)
{
	vector<option> long_options = 
	{
		{"help", no_argument, 0, 'h'}
		,{"method", required_argument, 0, 'm'}
		,{"server_host", required_argument, 0, 's'}
	};
	parseCommandLine(long_options, argc, argv);
}


