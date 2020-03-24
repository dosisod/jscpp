#include "../../src/javascript.hpp"

void testConsole() {
	console.log("log");
	console.warn("warn");
	console.error("error");

	console.log("hello", "world!");
	console.warn("this", "is", "a", "warning");
	console.error("this", "is", "a", "error");
}
