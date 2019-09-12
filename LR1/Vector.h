#pragma once
#include<iostream>
#include<math.h>
class Vector {
private:
	double CoordinateX;
	double CoordinateY;
	double CoordinateZ;
public:
	void GetStr();
	Vector();
	Vector(double, double, double);
	Vector(Vector const&);
	Vector operator/(double);
	void operator/=(double);
	double operator^(Vector);
	bool operator>(Vector);
	bool operator>=(Vector);
	bool operator<(Vector);
	bool operator<=(Vector);
	double FindLength();
	void GetCoordinates(double, double, double);
	void operator=(Vector);
	void PutVector();

	Vector operator+(Vector);
	void operator+=(Vector);
	Vector operator-(Vector);
	void operator-=(Vector);
	Vector operator*(double);
	void operator*=(double);
	double operator*(Vector);
	double operator*=(Vector);
};
