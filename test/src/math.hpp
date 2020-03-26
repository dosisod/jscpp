#include "../../src/javascript.hpp"

int testMath() {

int errors=0;

assert(Math.E == 2.718281828459045);
assert(Math.LN10 == 2.302585092994046);
assert(Math.LN2 == 0.6931471805599453);
assert(Math.LOG10E == 0.4342944819032518);
assert(Math.LOG2E == 1.4426950408889634);
assert(Math.PI == 3.141592653589793);
assert(Math.SQRT1_2 == 0.7071067811865476);
assert(Math.SQRT_2 == 1.4142135623730951);

assert(Math.abs(-1) == Math.abs(1));

assert(Math.acos(0) == 1.5707963267948966);
assert(Math.acosh(2) == 1.3169578969248166);

assert(Math.asin(1) == 1.5707963267948966);
assert(Math.asinh(1) == 0.881373587019543);

assert(Math.atan(1) == 0.7853981633974483);
assert(Math.atan2(10, 10) == 0.7853981633974483);
assert(Math.atanh(0.5) == 0.5493061443340548);

assert((int)Math.cbrt(27) == 3);

assert(Math.ceil(12.34) == 13);
assert(Math.ceil(-12.34) == -12);

assert(Math.clz32(0.5) == 32);
assert(Math.clz32(0) == 32);
assert(Math.clz32(0x0000ffff) == 16);
assert(Math.clz32(0xffffffff) == 0);

assert(Math.cos(0) == 1);
assert(Math.cosh(0) == 1);

assert(Math.exp(1) == Math.E);
assert(Math.expm1(1) == Math.exp(1) - 1);

assert(Math.floor(12.34) == 12);
assert(Math.floor(-12.34) == -13);

assert(Math.fround(5.05) == 5.050000190734863);

assert(Math.hypot(-16) == Math.abs(-16));
assert(Math.hypot(1, 1) == 1.4142135623730951);
assert(Math.hypot(1, 1, 1, 1) == 2);

assert(Math.imul(1.5, 3.5) == 3);
assert(Math.imul(2.5, -5) == -10);

assert(Math.log(1) == 0);
assert(Math.log10(100) == 2);
assert(Math.log1p(1) == 0.6931471805599453);
assert(Math.log2(32) == 5);

assert(Math.max(0, 1) == 1);
assert(Math.max(1, 2, 3, 4) == 4);
assert(Math.max(8, 4, 2, 1) == 8);

assert(Math.min(0, 1) == 0);
assert(Math.min(1, 2, 3, 4) == 1);
assert(Math.min(8, 4, 2, 1) == 1);

assert(Math.pow(2, 5) == 32);

assert(Math.random() != Math.random());

assert(Math.round(0.1) == 0);
assert(Math.round(0.5) == 1);
assert(Math.round(0.9) == 1);
assert(Math.round(-0.1) == -0);
assert(Math.round(-0.5) == -0);
assert(Math.round(-0.9) == -1);

assert(Math.sign(-100) == -1);
assert(Math.sign(100) == 1);

assert(Math.sin(0) == 0);
assert(Math.sinh(0) == 0);

assert(Math.sqrt(9) == 3);

assert(Math.tan(1) == 1.5574077246549023);
assert(Math.tanh(1) == 0.7615941559557649);

assert(Math.trunc(0.001) == Math.trunc(0.999));
assert(Math.trunc(-0.001) == Math.trunc(-0.999));

return errors;

}
