project(common)
set(sources
	CommandLineParser.cpp
	GlobalVariable.cpp)
add_library(${PROJECT_NAME} SHARED ${sources})
