#include "JsonParser.h"
#include "json.hpp"
#include "Options.h"
#include <fstream>
#include <iterator>

using namespace std;
using json = nlohmann::json;

static string readFile(const string& fileName)
{
	ifstream file(fileName);
	if (!file)
		return string();
	return string(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
}

bool JsonParser::parseConfiguration(const string& fileName)
{
	string content = readFile(fileName);
	auto j = json::parse(content);
	Options::instance().setServerAddress(j["server"]);
	Options::instance().setServerPort(j["server_port"]);
	Options::instance().setLocalPort(j["local_port"]);
	Options::instance().setMethod(j["method"]);
	Options::instance().setKey(j["key"]);
	Options::instance().setTimeout(j["timeout"]);
	return true;
}
