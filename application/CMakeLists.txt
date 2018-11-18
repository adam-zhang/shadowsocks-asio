project(shadowsocks_asio)
set(sources main.cpp
	CommandLine.cpp
	Options.cpp
	)
set(headers
	CommandLine.h
	Properties.h
	Options.h
	)
add_executable(${PROJECT_NAME} ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} boost_program_options)
