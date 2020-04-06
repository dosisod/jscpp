#pragma once

#include "string.hpp"

void alert() {
	std::cout << "[OK] ";
	std::string s;
	std::getline(std::cin, s);
}

template<typename T>
void alert(T obj) {
	std::cout << "\n" << obj << "\n";
	alert();
}

bool confirm() {
	std::cout << "CANCEL [OK] ";

	std::string s;
	std::getline(std::cin, s);

	if (s.length() == 0) return true;

	char c=s[0];
	return (c=='o' || c=='O' || c==13 || c==10);
}

template<typename T>
bool confirm(T obj) {
	std::cout << "\n" << obj << "\n";
	return confirm();
}

_String prompt() {
	std::string str;
	std::getline(std::cin, str);

	return _String(str);
}

template<typename T>
_String prompt(T obj) {
	std::cout << "\n" << obj << "\n";
	return prompt();
}