project(sa-server)
include_directories(../common)
set(sources main.cpp
	../common/CommandLineParser.cpp
	../common/GlobalVariable.cpp
	../common/Options.cpp)
set(headers ../common/CommandLineParser.h)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} 
	#common 
	libboost_program_options.a
	)
