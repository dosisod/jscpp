#include <cmath>

#include "math.hpp"

double _Math::abs(const double value) const {
	return std::abs(value);
}

double _Math::acos(const double rad) const {
	return std::acos(rad);
}

double _Math::acosh(const double rad) const {
	return std::acosh(rad);
}

double _Math::asin(const double rad) const {
	return std::asin(rad);
}

double _Math::asinh(const double rad) const {
	return std::asinh(rad);
}

double _Math::atan(const double rad) const {
	return std::atan(rad);
}

double _Math::atan2(const double x, const double y) const {
	return std::atan2(x, y);
}

double _Math::atanh(const double rad) const {
	return std::atanh(rad);
}

double _Math::cbrt(const double value) const {
	return std::cbrt(value);
}

double _Math::ceil(const double value) const {
	if (value > 0) {
		return std::ceil(value);
	}

	//js truncates values when doing Math.ceil() on negatives
	return trunc(value);
}

unsigned int _Math::clz32(const uint32_t value) const {
	int ret=0;
	while ((value & (1 << 31-ret))==0 && ret<32) {
		ret++;
	}

	return ret;
}

double _Math::cos(const double rad) const {
	return std::cos(rad);
}

double _Math::cosh(const double rad) const {
	return std::cosh(rad);
}

double _Math::exp(const double value) const {
	return std::exp(value);
}

double _Math::expm1(const double value) const {
	return std::expm1(value);
}

double _Math::floor(const double value) const {
	return std::floor(value);
}

float _Math::fround(const double value) const {
	//in js, this function is simply a cast to a float
	return value;
}

int _Math::imul(const uint32_t a, const uint32_t b) const {
	//Math.imul() is just (C style) Integer MULtiplication
	return a * b;
}

double _Math::log(const double value) const {
	return std::log(value);
}

double _Math::log10(const double value) const {
	return std::log10(value);
}

double _Math::log1p(const double value) const {
	return std::log1p(value);
}

double _Math::log2(const double value) const {
	return std::log2(value);
}

double _Math::pow(const double base, const double power) const {
	return std::pow(base, power);
}

double _Math::random() {
	return generator(prng);
}

double _Math::round(const double value) const {
	//negative values with with a decimal 0.5 are rounded to 0, not 1
	if (value < 0 && ((value)-(int)value)==-0.5) {
        return std::round(value) + 1;
    }
	return std::round(value);
}

double _Math::sign(const double value) const {
	return std::copysign(1, value);
}

double _Math::sin(const double rad) const {
	return std::sin(rad);
}

double _Math::sinh(const double rad) const {
	return std::sinh(rad);
}

double _Math::sqrt(const double value) const {
	return std::sqrt(value);
}

double _Math::tan(const double value) const {
	return std::tan(value);
}

double _Math::tanh(const double value) const {
	return std::tanh(value);
}

int _Math::trunc(const double value) const {
	return std::trunc(value);
}
