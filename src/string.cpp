#include "string.hpp"

_String::_String(const std::string internal) :
	internal(internal)
	{}

_String _String::operator()() {
	return _String("");
}

_String _String::operator()(const std::string internal) {
	return _String(internal);
}

bool _String::operator==(const _String& other) const {
	return internal==other.internal;
}
bool _String::operator==(const _String& other) {
	return internal==other.internal;
}

bool _String::operator!=(const _String& other) const {
	return internal!=other.internal;
}
bool _String::operator!=(const _String& other) {
	return internal!=other.internal;
}

_String::operator bool() {
	return internal.length()>0;
}

_String _String::operator+(const _String& other) const {
	return _String(internal + other.internal);
}

_String& _String::operator+(const _String& other) {
	internal+=other.internal;
	return *this;
}

_String& _String::operator+=(const _String& other) {
	internal+=other.internal;
	return *this;
}

_String& _String::operator=(const _String& other) {
	internal=other.internal;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const _String& str) {
	return out << str.internal;
}

char32_t _String::operator[](const unsigned int index) const {
	return charAt(index);
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

_String _String::repeat(const unsigned int count) const {
	_String str=_String("");

	for (unsigned int i=0; i<count; i++) {
		str+=_String(internal);
	}

	return str;
}

bool _String::startsWith(const std::string start) const {
	return (internal.rfind(start, 0) == 0);
}

_String& _String::toString() {
	return *this;
}

_String& _String::valueOf() {
	return *this;
}
