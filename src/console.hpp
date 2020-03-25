#pragma once

#include <iostream>
#include <string>

#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define CLEAR "\033[2J\033[1;1H"

class Console {
public:
	Console() {}

	void clear() const {
		std::cout << CLEAR << "\n";
	}

	template<typename T>
	void error(T data) const {
		std::cout << RED << data << RESET << "\n";
	}
	template<typename T, typename... Ts>
	void error(T data, Ts... other) const {
		std::cout << RED << data << RESET << " ";
		error(other...);
	}

	template<typename T>
	void log(T data) const {
		std::cout << data << "\n";
	}
	template<typename T, typename... Ts>
	void log(T data, Ts... other) const {
		std::cout << data << " ";
		log(other...);
	}

	template<typename T>
	void warn(T data) const {
		std::cout << YELLOW << data << RESET << "\n";
	}
	template<typename T, typename... Ts>
	void warn(T data, Ts... other) const {
		std::cout << YELLOW << data << RESET << " ";
		warn(other...);
	}
};
