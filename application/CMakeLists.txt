project(shadowsocks-local)
set(sources main.cpp
	CommandLine.cpp
	Options.cpp
	JsonParser.cpp
	Cipher.cpp
	SocksServer.cpp
	TcpClient.cpp
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
	)
add_executable(${PROJECT_NAME} ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} boost_program_options)
