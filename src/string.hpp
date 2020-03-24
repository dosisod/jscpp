#include <codecvt>
#include <string>
#include <locale>

class _String {
public:
	_String(const std::string internal);

	//allow String() instance to create more _String's
	_String operator()(const std::string internal);

	char32_t charAt(const unsigned int index) const;

	unsigned int charCodeAt(const unsigned int index) const;
	unsigned int codePointAt(const unsigned int index) const;

	bool endsWith(const std::string end) const;

	bool includes(const std::string str) const;

	int indexOf(const std::string str) const;
	int lastIndexOf(const std::string str) const;

	bool startsWith(const std::string start) const;

	std::string internal="";
};
