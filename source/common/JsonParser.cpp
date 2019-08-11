#include "JsonParser.h"
#include "json.hpp"
#include "GlobalVariable.h"
#include "Options.h"
#include <fstream>

using namespace std;
using json = nlohmann::json;

JsonParser::JsonParser()
{
}

JsonParser::~JsonParser()
{
}

string readFile(const std::string& fileName)
{
	ifstream file(fileName);
	if (!file.bad())
		return string();
	istreambuf_iterator<char> begin(file);
	istreambuf_iterator<char> end;
	return string(begin, end);
}

void JsonParser::parse(const std::string& fileName)
{
	json j = readFile(fileName);
	GlobalVariable::instance().option()->setServerPort(j["server-port"]);
	GlobalVariable::instance().option()->setServerHost(j["server-host"]);
	GlobalVariable::instance().option()->setLocalPort(j["local-port"]);
	GlobalVariable::instance().option()->setTimeout(j["timeout"]);
	GlobalVariable::instance().option()->setPassword(j["password"]);
	GlobalVariable::instance().option()->setMethod(j["encrypt-method"]);
}
