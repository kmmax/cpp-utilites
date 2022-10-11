cmake_minimum_required(VERSION 3.2)

# prints variable's context
# prints vars context
function(print)
	message(STATUS ================)
	message(STATUS "Dumping ${ARGC} variables:")
	foreach(VAR_NAME ${ARGN})
		message(STATUS " ${VAR_NAME} == \"${${VAR_NAME}}\"")
	endforeach()
	message(STATUS ================)
endfunction()


set(CMAKE_CXX_STADARD 14)

option(BytesConverter "Converts bytetes to float" ON)
option(RegCalculater "Works with modbus registers" ON)

project(Templates LANGUAGES CXX)

if (BytesConverter)
	add_subdirectory(BytesConverter)
endif()

if (RegCalculater)
	add_subdirectory(RegCalculater)
endif()

