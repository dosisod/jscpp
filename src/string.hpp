#include <algorithm>
#include <codecvt>
#include <string>
#include <locale>

class _String {
public:
	_String(const std::string internal);

	//allow String() instance to create more _String's
	_String operator()(const std::string internal);
	_String operator()();

	bool operator==(const _String& other) const;
	bool operator==(const _String& other);
	bool operator==(const std::string& other) const;
	bool operator==(const std::string& other);

	bool operator!=(const _String& other) const;
	bool operator!=(const _String& other);
	bool operator!=(const std::string& other) const;
	bool operator!=(const std::string& other);

	operator bool();

	_String operator+(const _String& other) const;
	_String& operator+(const _String& other);

	_String& operator+=(const _String& other);

	_String& operator=(const _String& other);

	friend std::ostream& operator<<(std::ostream& out, const _String& str);

	char32_t operator[](const unsigned int index) const;

	char32_t charAt(const unsigned int index) const;

	unsigned int charCodeAt(const unsigned int index) const;
	unsigned int codePointAt(const unsigned int index) const;

	_String concat(std::string str) const {
		return _String(internal + str);
	}

	template<typename... Ts>
	_String concat(Ts... ts) const {
		return _String(internal + sum(ts...));
	}

	bool endsWith(const std::string end) const;

	bool includes(const std::string str) const;

	int indexOf(const std::string str) const;
	int lastIndexOf(const std::string str) const;

	_String padEnd(const unsigned int length) const;
	_String padEnd(const unsigned int length, std::string str) const;

	_String padStart(const unsigned int length) const;
	_String padStart(const unsigned int length, std::string str) const;

	_String repeat(const unsigned int count) const;

	_String slice(int begin) const;
	_String slice(int begin, int end) const;

	bool startsWith(const std::string start) const;

	_String substring(int begin) const;
	_String substring(int begin, int end) const;

	_String toLowerCase() const;

	_String& toString();

	_String toUpperCase() const;

	_String& valueOf();

	std::string internal="";

private:
	std::string sum(std::string str) const {
		return str;
	}

	template<typename... Ts>
	std::string sum(std::string str, Ts... ts) const {
		return str + sum(ts...);
	}
};
