#include "string.hpp"

_String::_String(const std::string internal) :
	internal(internal)
	{}

_String _String::operator()(const std::string internal) {
	return _String(internal);
}

char32_t _String::charAt(const unsigned int index) const {
	std::wstring_convert<std::codecvt_utf8_utf16<char32_t>, char32_t> conv;

	return conv.from_bytes(internal)[index];
}

unsigned int _String::charCodeAt(const unsigned int index) const {
	std::wstring_convert<std::codecvt_utf8_utf16<char32_t>, char32_t> conv;

	return conv.from_bytes(internal)[index];
}

unsigned int _String::codePointAt(const unsigned int index) const {
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;

	return conv.from_bytes(internal)[index];
}

bool _String::endsWith(const std::string end) const {
	if (internal.length() < end.length()) return false;
		
	return (internal.compare(
		internal.length() - end.length(),
		end.length(),
		end
	) == 0);
}

bool _String::includes(const std::string str) const {
	return internal.find(str) != -1;
}

int _String::indexOf(const std::string str) const {
	return internal.find(str);
}

int _String::lastIndexOf(const std::string str) const {
	if (!str.length()) return internal.length();

	return internal.find_last_of(str);
}

bool _String::startsWith(const std::string start) const {
	return (internal.rfind(start, 0) == 0);
}
