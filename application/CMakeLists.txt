project(shadowsocks-local)
add_definitions(-std=c++11)
set(sources local.cpp
	CommandLine.cpp
	Options.cpp
	JsonParser.cpp
	Cipher.cpp
	SocksServer.cpp
	TcpClient.cpp
	Logger.cpp
	)
set(headers
	CommandLine.h
	Properties.h
	Options.h
	JsonParser.h
	json.hpp
	Cipher.h
	SocksServer.h
	TcpClient.h
	Logger.h
	)
add_executable(${PROJECT_NAME} ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} 
	pthread
	boost_system
	boost_program_options
	)
