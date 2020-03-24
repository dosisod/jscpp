add_executable(jscpp main.cpp)

add_library(math math.cpp math.hpp)
add_library(string string.cpp string.hpp)

target_link_libraries(
	jscpp
	math
	string
)
