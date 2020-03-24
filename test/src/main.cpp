#include "../../src/javascript.hpp"

#define assertEqual(a, b) if (a!=b) {console.log(__LINE__); hadErrors=true;}
#define assertNotEqual(a, b) if (a==b) hadErrors=true;
#define assert(x) if (!x) hadErrors=true;

//test function keyword
function add(int a, int b) {
	return a + b;
}

//test class keyword
class Base {
	Base() {}
	int num=123;
};

class Der extends Base {
	Der() : Base() {}
	int num=321;
};

int main() {
	int hadErrors=0;

	//test above add function
	assertEqual( add(1,2), 3 );

	//test IIFE
	assert( function(){
		return 1;
	}() );


	//test building of console commands
	console.log("log");
	console.warn("warn");
	console.error("error");

	console.log("hello", "world!");
	console.warn("this", "is", "a", "warning");
	console.error("this", "is", "a", "error");


	assertEqual(Math.E, 2.718281828459045);
	assertEqual(Math.LN10, 2.302585092994046);
	assertEqual(Math.LN2, 0.6931471805599453);
	assertEqual(Math.LOG10E, 0.4342944819032518);
	assertEqual(Math.LOG2E, 1.4426950408889634);
	assertEqual(Math.PI, 3.141592653589793);
	assertEqual(Math.SQRT1_2, 0.7071067811865476);
	assertEqual(Math.SQRT_2, 1.4142135623730951);

	assertEqual(Math.abs(-1), Math.abs(1));

	assertEqual(Math.acos(0), 1.5707963267948966);
	assertEqual(Math.acosh(2), 1.3169578969248166);

	assertEqual(Math.asin(1), 1.5707963267948966);
	assertEqual(Math.asinh(1), 0.881373587019543);

	assertEqual(Math.atan(1), 0.7853981633974483);
	assertEqual(Math.atan2(10, 10), 0.7853981633974483);
	assertEqual(Math.atanh(0.5), 0.5493061443340548);

	assertEqual((int)Math.cbrt(27), 3);

	assertEqual(Math.ceil(12.34), 13);
	assertEqual(Math.ceil(-12.34), -12);

	assertEqual(Math.clz32(0.5), 32);
	assertEqual(Math.clz32(0), 32);
	assertEqual(Math.clz32(0x0000ffff), 16);
	assertEqual(Math.clz32(0xffffffff), 0);

	assertEqual(Math.cos(0), 1);
	assertEqual(Math.cosh(0), 1);

	assertEqual(Math.exp(1), Math.E);
	assertEqual(Math.expm1(1), Math.exp(1) - 1);

	assertEqual(Math.floor(12.34), 12);
	assertEqual(Math.floor(-12.34), -13);

	assertEqual(Math.fround(5.05), 5.050000190734863);

	assertEqual(Math.hypot(-16), Math.abs(-16));
	assertEqual(Math.hypot(1, 1), 1.4142135623730951);
	assertEqual(Math.hypot(1, 1, 1, 1), 2);

	assertEqual(Math.imul(1.5, 3.5), 3);
	assertEqual(Math.imul(2.5, -5), -10);

	assertEqual(Math.log(1), 0);
	assertEqual(Math.log10(100), 2);
	assertEqual(Math.log1p(1), 0.6931471805599453);
	assertEqual(Math.log2(32), 5);

	assertEqual(Math.max(0, 1), 1);
	assertEqual(Math.max(1, 2, 3, 4), 4);
	assertEqual(Math.max(8, 4, 2, 1), 8);

	assertEqual(Math.min(0, 1), 0);
	assertEqual(Math.min(1, 2, 3, 4), 1);
	assertEqual(Math.min(8, 4, 2, 1), 1);

	assertEqual(Math.pow(2, 5), 32);

	assertNotEqual(Math.random(), Math.random());

	assertEqual(Math.round(0.1), 0);
	assertEqual(Math.round(0.5), 1);
	assertEqual(Math.round(0.9), 1);
	assertEqual(Math.round(-0.1), -0);
	assertEqual(Math.round(-0.5), -0);
	assertEqual(Math.round(-0.9), -1);

	assertEqual(Math.sign(-100), -1);
	assertEqual(Math.sign(100), 1);

	assertEqual(Math.sin(0), 0);
	assertEqual(Math.sinh(0), 0);

	assertEqual(Math.sqrt(9), 3);

	assertEqual(Math.tan(1), 1.5574077246549023);
	assertEqual(Math.tanh(1), 0.7615941559557649);

	assertEqual(Math.trunc(0.001), Math.trunc(0.999));
	assertEqual(Math.trunc(-0.001), Math.trunc(-0.999));

	//test class code
	Base base;
	Der der;
	assertEqual(base.num, 123);
	assertEqual(der.num, 321);

	//finally test code
	try {
		auto x=0;
	} catch(...) {
		assert(false);
	}
	finally {
		//good
	}


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

	if (hadErrors) {
		std::cout << "1 or more errors occurred.\n";
	}
	else {
		std::cout << "No errors occurred!\n";
	}

	return hadErrors;
}