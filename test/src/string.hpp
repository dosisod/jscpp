#include "assert.hpp"
#include "../../src/javascript.hpp"

int testString() {

int errors=0;

// == operator
assert(String("abc") == String("abc"));

// != operator
assert(String("abc") != String("def"));

// + operator
{
	const str=String("abc") + String("def");
	assert(str == String("abcdef"));
}

// += operator
{
	let str=String("abc");
	str+=String("def");
	assert(str == String("abcdef"));
}

// = operator
{
	let str=String("old value");
	str=String("new value");
	assert(str == String("new value"));
}

// bool operator
assert(String("valid")); //truthy
assert(!String("")); //falsey

// stream (<<) operator
std::cout << String("testing stream operator...\n");

assert(String("abc").charAt(1) == 'b');
assert(String("─").charAt(0) == U'─');

assert(String("a").charCodeAt(0) == 97);
assert(String("─").charCodeAt(0) == 9472);

//https://stackoverflow.com/a/43328217
assert(String("𠮷").charCodeAt(0) == 55362);
assert(String("𠮷").codePointAt(0) == 134071);

assert(String("abc").startsWith("a"));
assert(String("abc").startsWith(""));
assert(!String("abc").startsWith("c"));

assert(String("abc").endsWith("c"));
assert(String("abc").endsWith(""));
assert(!String("abc").endsWith("a"));

assert(String("abc").includes("a"));
assert(String("abc").includes(""));
assert(String("abc").includes("b"));
assert(!String("abc").includes("abcd"));

assert(String("abc").indexOf("b") == 1);
assert(String("abc").indexOf("") == 0);
assert(String("abc").indexOf("abcd") == -1);

assert(String("abcabc").lastIndexOf("c") == 5);
assert(String("abc").lastIndexOf("d") == -1);
assert(String("abc").lastIndexOf("") == 3);

return errors;
}
