#include <iostream>
#include <boost/program_options.hpp>

using namespace boost;
using namespace std;

int main(int argc, char** argv)
{
	program_options::options_description desc;
	desc.add_options()
		("name,n", program_options::value<std::string>(), "zmp")
		("age", program_options::value<int>()->default_value(18));
	program_options::variables_map m;
	program_options::store(program_options::parse_command_line(argc, argv, desc), m);
	if (m.count("name") > 0)
		std::cout << "name:"<< m["name"].as<string>() << endl;
	std::cout << m["age"].as<int>() << endl;

	return 0;
}
