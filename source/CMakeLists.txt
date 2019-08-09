cmake_minimum_required(VERSION 2.8)
project(shadowsocks)
#set(BOOST_ROOT /usr/local/include)
#find_package(Boost)
set(sources main.cpp
	ParameterParser.cpp
	Options.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} libboost_program_options.a)
