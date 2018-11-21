#include "SocksServer.h"
#include "Options.h"
#include <boost/asio.hpp>
#include <thread>
#include <array>
#include <vector>
#include <iostream>
#include <memory>
#include <iomanip>


using namespace std;
using namespace boost;
using namespace boost::asio::ip;


void run_thread(tcp::socket& socket)
{
	std::array<uint8_t, 512> buffer;
	system::error_code error; // = 0;
	while(auto length = socket.read_some(asio::buffer(buffer), error) > 0)
	{
		cout << "reading:\n";
		vector<uint8_t> data(buffer.begin(), buffer.begin() + length);
		cout << (char*)&data[0] << endl;
	}
}

void printData(const vector<uint8_t>& data)
{
	cout << "I'm in printData\n";
	cout << "size:" << data.size() << endl;
	for(auto i = 0; i != data.size(); ++i)
	{
		cout << hex << setw(2) << setfill('0') << (unsigned int)data[i] << " ";
		cout << i << endl;
	}
}

void readData(const std::shared_ptr<tcp::socket>& socket)
{
	cout << "I'm in readData\n";
	system::error_code error;
	std::array<uint8_t, 512> buffer;
	while(auto length = socket->read_some(asio::buffer(buffer), error))
	{
		cout << "length:" << length << endl;
		vector<uint8_t> data(buffer.begin(), buffer.begin() + length);
		printData(data);
	}
}

void SocksServer::run()
{
	asio::io_context io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), Options::instance().localPort()));
	for(;;)
	{
		auto socket = make_shared<tcp::socket>(io);
		acceptor.accept(*socket);
		readData(socket);
		string message = "Hello";
		system::error_code error;
		asio::write(*socket, asio::buffer(message), error);
	}
}
