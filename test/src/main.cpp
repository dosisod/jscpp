#include "../../src/javascript.hpp"
#include "keywords.hpp"
#include "console.hpp"
#include "string.hpp"
#include "math.hpp"

int main() {
	bool hadErrors=false;

	//tests that only need to be built, not ran
	testConsole();

	//tests that actually need to be ran
	hadErrors|=testMath();
	hadErrors|=testKeywords();
	hadErrors|=testString();

	if (hadErrors) {
		std::cout << "1 or more errors occurred.\n";
	}
	else {
		std::cout << "No errors occurred!\n";
	}

	return hadErrors;
}