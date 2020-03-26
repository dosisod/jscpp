#include "../../src/javascript.hpp"
#include "keywords.hpp"
#include "console.hpp"
#include "string.hpp"
#include "math.hpp"

int main() {
	int errors=0;

	//tests that only need to be built, not ran
	testConsole();

	//tests that actually need to be ran
	errors+=testMath();
	errors+=testKeywords();
	errors+=testString();

	if (errors == 1) {
		std::cout << "1 error occurred.\n";
	}
	else if (errors > 0) {
		std::cout << errors << " errors occurred.\n";
	}
	else {
		std::cout << "No errors occurred!\n";
		return 0;
	}

	return 1;
}