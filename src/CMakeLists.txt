add_executable(jscpp main.cpp)

add_library(math math.cpp math.hpp)

target_link_libraries(
	jscpp
	math
)
