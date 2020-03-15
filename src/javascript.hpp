#pragma once

#include "console.hpp"
Console console;

#include "math.hpp"
_Math Math;

//allows for const, var, and let
#define const const auto
#define var auto
#define let auto

//allows for JS style functions, and anonymous functions
#define function auto
#define auto() [=]()

//emulate JS public by default classes, and extends keyword
#define class struct
#define extends : public

//emulate JS finally keyword
#define finally