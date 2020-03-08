#include <iostream>

#include "javascript.hpp"

function add(int a, int b) {
	return a + b;
}

int main() {
	const a=1;

	var b=a;

	let c=b;

	std::cout << add(a, b) << "\n";

	return 0;
}