add_executable(Test src/main.cpp)

include_directories(../src/)

target_link_libraries(
	Test
	math
	string
)
