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
bool _String::operator==(const std::string& other) const {
	return internal==other;
}
bool _String::operator==(const std::string& other) {
	return internal==other;
}

bool _String::operator!=(const _String& other) const {
	return internal!=other.internal;
}
bool _String::operator!=(const _String& other) {
	return internal!=other.internal;
}
bool _String::operator!=(const std::string& other) const {
	return internal!=other;
}
bool _String::operator!=(const std::string& other) {
	return internal!=other;
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

_String _String::padEnd(const unsigned int length) const {
	return padEnd(length, " ");
}

_String _String::padEnd(const unsigned int length, std::string str) const {
	if (internal.length() >= length) {
		return _String(internal);
	}

	std::string ret=internal;
	int total=length - ret.length();

	for (unsigned int i=0; i < (total/str.length()) ; i++) {
		ret+=str;
	}

	return _String(
		ret+=str.substr(0, total % str.length())
	);
}

_String _String::padStart(const unsigned int length) const {
	return padStart(length, " ");
}

_String _String::padStart(const unsigned int length, std::string str) const {
	if (internal.length() >= length) {
		return _String(internal);
	}

	std::string ret="";
	int total=length - internal.length();

	for (unsigned int i=0; i < (total/str.length()) ; i++) {
		ret+=str;
	}

	return _String(
		ret +
		str.substr(0, total % str.length()) +
		internal
	);
}

_String _String::repeat(const unsigned int count) const {
	_String str=_String("");

	for (unsigned int i=0; i<count; i++) {
		str+=_String(internal);
	}

	return str;
}

_String _String::slice(int begin) const {
	return slice(begin, internal.length());
}

_String _String::slice(int begin, int end) const {
	if (begin < 0) {
		begin=internal.length() + begin;
	}
	if (end < 0) {
		end=internal.length() + end;
	}

	if (begin >= (int)internal.length()) {
		return _String("");
	}
	else if (begin <= 0) {
		return _String(internal.substr(0, end));
	}
	else {
		return _String(internal.substr(begin, end - begin));
	}
}

bool _String::startsWith(const std::string start) const {
	return (internal.rfind(start, 0) == 0);
}

_String _String::substring(int begin) const {
	return _String(substring(
		begin,
		internal.length()
	));
}

_String _String::substring(int begin, int end) const {
	if (begin < 0) begin=0;
	if (end < 0) end=0;

	if (begin > end) {
		const int tmp=end;
		end=begin;
		begin=tmp;
	}

	if (begin > internal.length()) {
		begin=internal.length();
	}

	return _String(internal.substr(
		begin,
		end - begin
	));
}

_String& _String::toString() {
	return *this;
}

_String& _String::valueOf() {
	return *this;
}
