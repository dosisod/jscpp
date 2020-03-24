#include "../../src/javascript.hpp"

#define assertEqual(a, b) if (a!=b) {console.log(__LINE__); hadErrors=true;}
#define assertNotEqual(a, b) if (a==b) hadErrors=true;
#define assert(x) if (!x) hadErrors=true;

bool testString() {
	bool hadErrors=false;

	assertEqual(String("abc").charAt(1), 'b')
	assertEqual(String("─").charAt(0), U'─')

	assertEqual(String("a").charCodeAt(0), 97)
	assertEqual(String("─").charCodeAt(0), 9472)

	//https://stackoverflow.com/a/43328217
	assertEqual(String("𠮷").charCodeAt(0), 55362)
	assertEqual(String("𠮷").codePointAt(0), 134071)

	assert(String("abc").startsWith("a"))
	assert(String("abc").startsWith(""))
	assert(!String("abc").startsWith("c"))

	assert(String("abc").endsWith("c"))
	assert(String("abc").endsWith(""))
	assert(!String("abc").endsWith("a"))

	assert(String("abc").includes("a"))
	assert(String("abc").includes(""))
	assert(String("abc").includes("b"))
	assert(!String("abc").includes("abcd"))

	assertEqual(String("abc").indexOf("b"), 1)
	assertEqual(String("abc").indexOf(""), 0)
	assertEqual(String("abc").indexOf("abcd"), -1)

	assertEqual(String("abcabc").lastIndexOf("c"), 5)
	assertEqual(String("abc").lastIndexOf("d"), -1)
	assertEqual(String("abc").lastIndexOf(""), 3)

	return hadErrors;
}
