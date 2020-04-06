#include "../../src/ui.hpp"

//manually add keys to stdin to simulate a keyboard
void keyboard(std::string str) {
	for (unsigned int i=0; i<str.length(); i++) {
		ungetc(str[str.length() - i - 1], stdin);
	}
}

int testUI() {
	int errors=0;

	//test alert w/o parameters
	keyboard("\n");
	alert();

	//test alert w/ parameters
	keyboard("\n");
	alert("hello!");

	//test accept confirm w/o params
	keyboard("\n");
	assert(confirm());

	//test accept confirm w/ params
	keyboard("\n");
	assert(confirm("confirm?"));

	//test accept confirm via "o" or "O"
	keyboard("o\n");
	assert(confirm("confirm?"));
	keyboard("O\n");
	assert(confirm("confirm?"));

	//test deny confirm (non "o" or "O")
	keyboard("c\n");
	assert(!confirm("confirm?"));

	//test prompt w/o params
	keyboard("hi\n");
	assert(prompt() == "hi");

	//test prompt w/ params
	keyboard("bob\n");
	assert(prompt("name?") == "bob");

	return errors;
}
