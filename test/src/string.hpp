#include "assert.hpp"
#include "../../src/javascript.hpp"

int testString() {

int errors=0;

//empty ctor
{
	const str=String();
	assert(str == String(""));
}

// == operator
assert(String("abc") == String("abc"));
assert(String("abc") == "abc");

// != operator
assert(String("abc") != String("def"));
assert(String("abc") != "def");

// + operator
{
	assert(
		(String("abc") + String("def")) ==
		String("abcdef")
	);

	const str=String("abc") + String("def");
	assert(str == String("abcdef"));

	const lhs=String("lhs");
	const rhs=String("rhs");

	assert((lhs + String(" rhs")) == String("lhs rhs"));
	assert((String("lhs ") + rhs) == String("lhs rhs"));
	assert((lhs + rhs) == String("lhsrhs"));
}

// += operator
{
	let str=String("abc");
	str+=String("def");
	assert(str == String("abcdef"));

	const def=String("def");
	let tmp=String("abc");
	tmp+=def;

	assert(tmp == String("abcdef"));
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

// index ([]) operator
assert(String("abc")[1] == 'b');
assert(String("─")[0] == U'─');

assert(String("abc").charAt(1) == 'b');
assert(String("─").charAt(0) == U'─');

assert(String("a").charCodeAt(0) == 97);
assert(String("─").charCodeAt(0) == 9472);

//https://stackoverflow.com/a/43328217
assert(String("𠮷").charCodeAt(0) == 55362);
assert(String("𠮷").codePointAt(0) == 134071);

{
	assert(String("abc").concat("def") == String("abcdef"));
	assert(String("abc").concat("def", "ghi") == String("abcdefghi"));

	const str=String("abc");
	assert(str.concat("def") == String("abcdef"));
	assert(str.concat("def", "ghi") == String("abcdefghi"));
}

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

assert(String("abc").padEnd(10) == String("abc").padEnd(10, " "));
assert(String("abc").padEnd(1) == String("abc"));
assert(String("abc").padEnd(6) == String("abc   "));
assert(String("abc").padEnd(10, "foo") == String("abcfoofoof"));
assert(String("abc").padEnd(9, "abc") == String("abcabcabc"));

assert(String("abc").padStart(10) == String("abc").padStart(10, " "));
assert(String("abc").padStart(1) == String("abc"));
assert(String("abc").padStart(6) == String("   abc"));
assert(String("abc").padStart(10, "foo") == String("foofoofabc"));
assert(String("abc").padStart(6, "123456") == String("123abc"));

assert(String("a").repeat(3) == String("aaa"));
assert(String("b").repeat(0) == String(""));

assert(String("abc").slice(0, 3) == String("abc").slice(0));
assert(String("abc").slice(0) == String("abc"));
assert(String("abc").slice(10) == String(""));
assert(String("abc").slice(-10) == String("abc"));
assert(String("abc").slice(1) == String("bc"));
assert(String("abc").slice(0, -1) == String("ab"));
assert(String("abc").slice(0, 2) == String("ab"));
assert(String("abc").slice(1, 2) == String("b"));
assert(String("hello world").slice(-10, 5) == String("ello"));

assert(String("abc").startsWith("a"));
assert(String("abc").startsWith(""));
assert(!String("abc").startsWith("c"));

assert(String("hello").substring(0) == String("hello").substring(0, 5));
assert(String("hello").substring(0) == String("hello"));
assert(String("abc").substring(1) == String("bc"));
assert(String("abc").substring(0, 1) == String("abc").substring(1, 0));
assert(String("abc").substring(-2) == String("abc").substring(0));
assert(String("abc").substring(3, -2) == String("abc").substring(3, 0));
assert(String("abc").substring(1, 1) == String(""));
assert(String("abc").substring(1, 2) == String("b"));
assert(String("abc").substring(0, 100) == String("abc"));
assert(String("abc").substring(5, 100) == String(""));

assert(String("abc").toString() == String("abc"));

assert(String("abc").valueOf() == String("abc"));

return errors;
}
