#include "javascript.hpp"

function hello() {
	console.log("hello world!");
}

int main() {
	const a=1;
	const b=2;

	let c=a + b;

	console.log(c);

	console.warn("warning");
	console.error("error");

	hello();

	const f=function() {
		console.log("lambdas!");
	};

	f();

	console.log(Math.abs(-1));

	return 0;
}