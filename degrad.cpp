/* ---------------------------------------------------------------------------
** The MIT License (MIT)
** 
** Copyright (c) 2013 Graham Pentheny
** 
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
** 
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
**
** degrad.cpp
** Example usage of the Degrees and Radians classes defined in degrad.h
**
** Author: Graham Pentheny 
** -------------------------------------------------------------------------*/

#include <iostream>
#include "degrad.h"

// Example of a function that accepts Degrees values.
void foo(const Degrees& d) {
	std::cout << d.getValue() << std::endl;
}

// Example of a constant Radians value.
// Because of how the literal suffix and identifier rules work, you can have 
// this constant share the same suffix, making it very clear what unit it is.
constexpr Radians PI_rad = Radians(PI);

int main() {
	Degrees degrees(180.0f);
	Radians radians(PI);

	foo(radians);

	degrees = 180_deg;
	radians = 3.14159_rad;

	foo(degrees);
	foo(radians);

	foo(PI_rad);
	foo(90_deg + 90_deg);

	// Showcasing a few of the operators...
	Degrees d = 4 * (-90_deg + 45_deg - 5_deg) / -2.5f; // d is 80 degrees
	foo(d);

	//90_deg = 180_deg;
}
