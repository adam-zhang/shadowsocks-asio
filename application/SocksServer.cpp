#include "SocksServer.h"
#include "Options.h"
#include <boost/asio.hpp>
#include <thread>

using namespace boost::asio;
using namespace boost::asio::ip;

void run_thread(tcp::socket& s)
{

}

void SocksServer::run()
{
	io_context io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 
			       Options::instance().localPort()));

	for(;;)
	{
		tcp::socket socket(io);
		acceptor.accept(socket);
//std::thread thread(run_thread, socket);
	}
}
