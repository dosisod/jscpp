#include "../../src/javascript.hpp"

#define assertTrue(a, b) if (a!=b) hadErrors=true;
#define assertFalse(a, b) if (a==b) hadErrors=true;
#define assert(x) if (!x) hadErrors=true;

//test function keyword
function add(int a, int b) {
	return a + b;
}

int main() {
	int hadErrors=0;

	//test above add function
	assertTrue(
		add(1,2),
		3
	);

	//test IIFE
	assert( function(){
		return 1;
	}() );

	//test building of console commands
	console.log("log");
	console.warn("warn");
	console.error("error");

	if (hadErrors) {
		std::cout << "1 or more errors occurred.\n";
	}
	else {
		std::cout << "No errors occurred!\n";
	}

	return hadErrors;
}