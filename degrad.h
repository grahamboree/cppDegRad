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
** degrad.h
** Degrees and Radians classes, along with floating literal suffix operators.
**
** Author: Graham Pentheny 
** -------------------------------------------------------------------------*/

#ifndef DEGRAD_H_
#define DEGRAD_H_

constexpr float PI = 3.1415926535897932;
constexpr float RAD2DEG = 180.0f / PI;
constexpr float DEG2RAD = PI / 180.0f;

class Degrees;

/*-------------------------------------------------------------------------*/
class Radians {
    float value;
public:
    // Constructors:
    explicit constexpr Radians(float radiansValue) :value(radiansValue) {}
    Radians(Degrees degreesValue); // defined below
	Radians(const Radians& radiansValue) = default;
	Radians(Radians&& radiansValue) = default;

    // Accessor:
    constexpr float getValue() const { return value; }
    void setValue(float newValue) { value = newValue; }

	// Assignment operator:
	Radians& operator=(const Radians& rhs) & = default;
    Radians& operator=(Radians&& rhs) & noexcept = default;

    // Arithmetic operators:
    constexpr Radians operator -() const            { return Radians(-value); }
    constexpr Radians operator +(Radians rhs) const { return Radians(value + rhs.value); }
    constexpr Radians operator -(Radians rhs) const { return Radians(value - rhs.value); }
    constexpr Radians operator *(float rhs) const   { return Radians(value * rhs); }
    constexpr Radians operator /(float rhs) const   { return Radians(value / rhs); }
    constexpr float   operator /(Radians rhs) const { return (value / rhs.value); }
    constexpr friend Radians operator*(float f, Radians d) { return Radians(d.value * f); }

    // Comparison and relational operators:
    constexpr bool operator ==(Radians rhs) const { return value == rhs.value; }
    constexpr bool operator !=(Radians rhs) const { return value != rhs.value; }
    constexpr bool operator > (Radians rhs) const { return value >  rhs.value; }
    constexpr bool operator < (Radians rhs) const { return value <  rhs.value; }
    constexpr bool operator >=(Radians rhs) const { return value >= rhs.value; }
    constexpr bool operator <=(Radians rhs) const { return value <= rhs.value; }

    // Compound assignment operators:
    Radians& operator +=(Radians rhs) { value += rhs.value; return *this; }
    Radians& operator -=(Radians rhs) { value -= rhs.value; return *this; }
    Radians& operator *=(float rhs)   { value *= rhs; return *this; }
    Radians& operator /=(float rhs)   { value /= rhs; return *this; }
};

/*-------------------------------------------------------------------------*/
class Degrees {
    float value;
public:
    // Constructors:
    explicit constexpr Degrees(float degreesValue) :value(degreesValue) {}
    Degrees(Radians radiansValue) :value(radiansValue.getValue() * RAD2DEG) {}
	Degrees(const Degrees& degreesValue) = default;
	Degrees(Degrees&& degreesValue) = default;

    // Accessor:
    constexpr float getValue() const { return value; }
    void setValue(float newValue) { value = newValue; }

	// Assignment operator:
	Degrees& operator=(const Degrees& rhs) & = default;
	Degrees& operator=(Degrees&& rhs) & noexcept = default;
	
    // Arithmetic operators:
    constexpr Degrees operator -() const            { return Degrees(-value); }
    constexpr Degrees operator +(Degrees rhs) const { return Degrees(value + rhs.value); }
    constexpr Degrees operator -(Degrees rhs) const { return Degrees(value - rhs.value); }
    constexpr Degrees operator *(float rhs) const   { return Degrees(value * rhs); }
    constexpr Degrees operator /(float rhs) const   { return Degrees(value / rhs); }
    constexpr float   operator /(Degrees rhs) const { return (value / rhs.value); }
    constexpr friend Degrees operator*(float f, Degrees d) { return Degrees(d.value * f); }

    // Comparison and relational operators:
    constexpr bool operator ==(Degrees rhs) const { return value == rhs.value; }
    constexpr bool operator !=(Degrees rhs) const { return value != rhs.value; }
    constexpr bool operator > (Degrees rhs) const { return value >  rhs.value; }
    constexpr bool operator < (Degrees rhs) const { return value <  rhs.value; }
    constexpr bool operator >=(Degrees rhs) const { return value >= rhs.value; }
    constexpr bool operator <=(Degrees rhs) const { return value <= rhs.value; }

    // Compound assignment operators:
    Degrees& operator +=(Degrees rhs) { value += rhs.value; return *this; }
    Degrees& operator -=(Degrees rhs) { value -= rhs.value; return *this; }
    Degrees& operator *=(float rhs)   { value *= rhs; return *this; }
    Degrees& operator /=(float rhs)   { value /= rhs; return *this; }
};

/*-------------------------------------------------------------------------*/
inline Radians::Radians(Degrees degreesValue) :value(degreesValue.getValue() * DEG2RAD) {}

/*-------------------------------------------------------------------------*/
// User-defined literal suffix operators.
inline Radians operator"" _rad(long double r)        { return Radians(r); }
inline Radians operator"" _rad(unsigned long long r) { return Radians(r); }
inline Degrees operator"" _deg(long double d)        { return Degrees(d); }
inline Degrees operator"" _deg(unsigned long long d) { return Degrees(d); }

#endif // DEGRAD_H 

