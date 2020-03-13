#pragma once

#include <iostream>
#include <string>

#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Console {
public:
	Console() {}

	template<typename T>
	void log(T data) const {
		std::cout << data << "\n";
	}

	template<typename T>
	void warn(T data) const {
		std::cout << YELLOW << data << RESET << "\n";
	}

	template<typename T>
	void error(T data) const {
		std::cout << RED << data << RESET << "\n";
	}
};
