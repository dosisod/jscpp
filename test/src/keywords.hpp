#include "assert.hpp"
#include "../../src/javascript.hpp"

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

int testKeywords() {
	int errors=0;

	//test add function
	assert( add(1,2) == 3 );

	//test IIFE capabilities
	assert( function(){
		return 1;
	}() );

{
	//test extends functionality
	Base base;
	Der der;

	assert(base.num == 123);
	assert(der.num == 321);
}

{
	//test finally capabilities
	try {
		auto x=0;
	} catch(...) {
		assert(false);
	}
	finally {
		//good
	}
}

	assert(null == NULL);

	return errors;
}
