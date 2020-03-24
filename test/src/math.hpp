#include "../../src/javascript.hpp"

#define assertEqual(a, b) if (a!=b) {console.log(__LINE__); hadErrors=true;}
#define assertNotEqual(a, b) if (a==b) hadErrors=true;
#define assert(x) if (!x) hadErrors=true;

bool testMath() {

bool hadErrors=0;

assertEqual(Math.E, 2.718281828459045);
assertEqual(Math.LN10, 2.302585092994046);
assertEqual(Math.LN2, 0.6931471805599453);
assertEqual(Math.LOG10E, 0.4342944819032518);
assertEqual(Math.LOG2E, 1.4426950408889634);
assertEqual(Math.PI, 3.141592653589793);
assertEqual(Math.SQRT1_2, 0.7071067811865476);
assertEqual(Math.SQRT_2, 1.4142135623730951);

assertEqual(Math.abs(-1), Math.abs(1));

assertEqual(Math.acos(0), 1.5707963267948966);
assertEqual(Math.acosh(2), 1.3169578969248166);

assertEqual(Math.asin(1), 1.5707963267948966);
assertEqual(Math.asinh(1), 0.881373587019543);

assertEqual(Math.atan(1), 0.7853981633974483);
assertEqual(Math.atan2(10, 10), 0.7853981633974483);
assertEqual(Math.atanh(0.5), 0.5493061443340548);

assertEqual((int)Math.cbrt(27), 3);

assertEqual(Math.ceil(12.34), 13);
assertEqual(Math.ceil(-12.34), -12);

assertEqual(Math.clz32(0.5), 32);
assertEqual(Math.clz32(0), 32);
assertEqual(Math.clz32(0x0000ffff), 16);
assertEqual(Math.clz32(0xffffffff), 0);

assertEqual(Math.cos(0), 1);
assertEqual(Math.cosh(0), 1);

assertEqual(Math.exp(1), Math.E);
assertEqual(Math.expm1(1), Math.exp(1) - 1);

assertEqual(Math.floor(12.34), 12);
assertEqual(Math.floor(-12.34), -13);

assertEqual(Math.fround(5.05), 5.050000190734863);

assertEqual(Math.hypot(-16), Math.abs(-16));
assertEqual(Math.hypot(1, 1), 1.4142135623730951);
assertEqual(Math.hypot(1, 1, 1, 1), 2);

assertEqual(Math.imul(1.5, 3.5), 3);
assertEqual(Math.imul(2.5, -5), -10);

assertEqual(Math.log(1), 0);
assertEqual(Math.log10(100), 2);
assertEqual(Math.log1p(1), 0.6931471805599453);
assertEqual(Math.log2(32), 5);

assertEqual(Math.max(0, 1), 1);
assertEqual(Math.max(1, 2, 3, 4), 4);
assertEqual(Math.max(8, 4, 2, 1), 8);

assertEqual(Math.min(0, 1), 0);
assertEqual(Math.min(1, 2, 3, 4), 1);
assertEqual(Math.min(8, 4, 2, 1), 1);

assertEqual(Math.pow(2, 5), 32);

assertNotEqual(Math.random(), Math.random());

assertEqual(Math.round(0.1), 0);
assertEqual(Math.round(0.5), 1);
assertEqual(Math.round(0.9), 1);
assertEqual(Math.round(-0.1), -0);
assertEqual(Math.round(-0.5), -0);
assertEqual(Math.round(-0.9), -1);

assertEqual(Math.sign(-100), -1);
assertEqual(Math.sign(100), 1);

assertEqual(Math.sin(0), 0);
assertEqual(Math.sinh(0), 0);

assertEqual(Math.sqrt(9), 3);

assertEqual(Math.tan(1), 1.5574077246549023);
assertEqual(Math.tanh(1), 0.7615941559557649);

assertEqual(Math.trunc(0.001), Math.trunc(0.999));
assertEqual(Math.trunc(-0.001), Math.trunc(-0.999));

return hadErrors;

}
