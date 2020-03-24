#include "../../src/javascript.hpp"

#define assertEqual(a, b) if (a!=b) {console.log(__LINE__); hadErrors=true;}
#define assertNotEqual(a, b) if (a==b) hadErrors=true;
#define assert(x) if (!x) hadErrors=true;

function add(int a, int b) {
	return a + b;
}

class Base {
	Base() {}
	int num=123;
};
class Der extends Base {
	Der() : Base() {}
	int num=321;
};

bool testKeywords() {
	bool hadErrors=false;

	//test add function
	assertEqual( add(1,2), 3 );

	//test IIFE capabilities
	assert( function(){
		return 1;
	}() );

	//test extends functionality
	Base base;
	Der der;
	assertEqual(base.num, 123);
	assertEqual(der.num, 321);

	//test finally capabilities
	try {
		auto x=0;
	} catch(...) {
		assert(false);
	}
	finally {
		//good
	}

	return hadErrors;
}
