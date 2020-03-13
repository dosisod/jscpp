#pragma once

#include <cstdint>
#include <random>

class _Math {
public:
	_Math() {}

	const double E=2.718281828459045;
	const double LN10=2.302585092994046;
	const double LN2=0.6931471805599453;
	const double LOG10E=0.4342944819032518;
	const double LOG2E=1.4426950408889634;
	const double PI=3.141592653589793;
	const double SQRT1_2=0.7071067811865476;
	const double SQRT_2=1.4142135623730951;

	double abs(const double value) const;

	double acos(const double rad) const;
	double acosh(const double rad) const;
	double asin(const double rad) const;
	double asinh(const double rad) const;
	double atan(const double rad) const;
	double atan2(const double x, const double y) const;
	double atanh(const double rad) const;

	double cbrt(const double value) const;

	double ceil(const double value) const;

	unsigned int clz32(const uint32_t value) const;

	double cos(const double rad) const;
	double cosh(const double rad) const;

	double exp(const double value) const;
	double expm1(const double value) const;

	double floor(const double value) const;
	float fround(const double value) const;

	template<typename T>
	double hypot(const T num) const {
		//MDN says calling Math.hypot() with 1 parameter
		//is the same as calling Math.abs()

		return std::abs(num);
	}

	template<typename... Ts>
	double hypot(const Ts... nums) const {
		return std::sqrt(squaredSums(nums...));
	}

	int imul(const uint32_t a, const uint32_t b) const;

	double log(const double value) const;
	double log10(const double value) const;
	double log1p(const double value) const;
	double log2(const double value) const;

	template<typename T>
	double max(const T num1, const T num2) const {
		if (num1 < num2) return num2;
		return num1;
	}

	template<typename T, typename... Ts>
	double max(const T num, const Ts... nums) const {
		const double result=max(nums...);

		if (num < result) return result;
		return num;
	}

	template<typename T>
	double min(const T num1, const T num2) const {
		if (num1 > num2) return num2;
		return num1;
	}

	template<typename T, typename... Ts>
	double min(const T num, const Ts... nums) const {
		const double result=min(nums...);

		if (num > result) return result;
		return num;
	}

	double pow(const double base, const double power) const;

	double random();

	double round(const double value) const;

	double sign(const double value) const;

	double sin(const double rad) const;
	double sinh(const double rad) const;

	double sqrt(const double value) const;

	double tan(const double value) const;
	double tanh(const double value) const;

	int trunc(const double value) const;

private:

	//private functions for Math.hypot()
	template<typename T>
	double squaredSums(const T num) const {
		return num * num;
	}
	template<typename T, typename... Ts>
	double squaredSums(const T num, const Ts... nums) const {
		return squaredSums(num) + squaredSums(nums...);
	}

	//variables related to the random() function
	std::random_device rand_dev;
	std::mt19937 prng { rand_dev() };
	std::uniform_real_distribution<double> generator { 0, 1 };
};