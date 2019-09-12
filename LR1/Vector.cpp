#include "Vector.h"
void Vector::GetStr() {

}
Vector::Vector() : CoordinateX(0), CoordinateY(0), CoordinateZ(0)
{}
Vector::Vector(double X, double Y, double Z) : CoordinateX(X), CoordinateY(Y), CoordinateZ(Z)
{}
Vector Vector::operator/(double K) {
	return Vector(CoordinateX / K, CoordinateY / K, CoordinateZ / K);
}
void Vector::operator/=(double K) {
	CoordinateX /= K;
	CoordinateY /= K;
	CoordinateZ /= K;
}
double Vector::operator^(Vector SecondVec) {
	double Chisl, Znam;
	Chisl = (CoordinateX + SecondVec.CoordinateX) * (CoordinateY + SecondVec.CoordinateY) * (CoordinateZ + SecondVec.CoordinateZ);
	Znam = sqrt(pow(CoordinateX, 2) + pow(CoordinateY, 2) + pow(CoordinateZ, 2)) * sqrt(pow(SecondVec.CoordinateX, 2) + pow(SecondVec.CoordinateY, 2) + pow(SecondVec.CoordinateZ, 2));
	return Chisl / Znam;
}
bool Vector::operator>(Vector SecondVec) {
	double FirstLength, SecondLength;
	FirstLength = FindLength();
	SecondLength = SecondVec.FindLength();
	return FirstLength > SecondLength;
}
double Vector::FindLength() {
	return sqrt(pow(CoordinateX, 2) + pow(CoordinateY, 2) + pow(CoordinateZ, 2));
}
bool Vector::operator>=(Vector SecondVec) {
	double FirstLength, SecondLength;
	FirstLength = FindLength();
	SecondLength = SecondVec.FindLength();
	return FirstLength >= SecondLength;
}
bool Vector::operator<(Vector SecondVec) {
	double FirstLength, SecondLength;
	FirstLength = FindLength();
	SecondLength = SecondVec.FindLength();
	return FirstLength < SecondLength;
}
bool Vector::operator<=(Vector SecondVec) {
	double FirstLength, SecondLength;
	FirstLength = FindLength();
	SecondLength = SecondVec.FindLength();
	return FirstLength <= SecondLength;
}
Vector Vector::operator+(Vector Vec) {
	return Vector(CoordinateX + Vec.CoordinateX, CoordinateY + Vec.CoordinateY, CoordinateZ + Vec.CoordinateZ);
}

void Vector::operator+=(Vector Vec) {
	CoordinateX += Vec.CoordinateX;
	CoordinateY += Vec.CoordinateY;
	CoordinateZ += Vec.CoordinateZ;
}

Vector Vector::operator-(Vector Vec) {
	return Vector(CoordinateX - Vec.CoordinateX, CoordinateY - Vec.CoordinateY, CoordinateZ - Vec.CoordinateZ);
}

void Vector::operator-=(Vector Vec) {
	CoordinateX -= Vec.CoordinateX;
	CoordinateY -= Vec.CoordinateY;
	CoordinateZ -= Vec.CoordinateZ;
}

Vector Vector::operator*(double K) {
	return Vector(CoordinateX * K, CoordinateY * K, CoordinateZ * K);
}

void Vector::operator*=(double K) {
	CoordinateX *= K;
	CoordinateY *= K;
	CoordinateZ *= K;
}

double Vector::operator*(Vector Vec) {
	return CoordinateX * Vec.CoordinateX + CoordinateY * Vec.CoordinateY + CoordinateZ * Vec.CoordinateZ;
}

double Vector::operator*=(Vector Vec) {
	return CoordinateX * Vec.CoordinateX + CoordinateY * Vec.CoordinateY + CoordinateZ * Vec.CoordinateZ;
}
void Vector::GetCoordinates(double X, double Y, double Z) {
	CoordinateX = X;
	CoordinateY = Y;
	CoordinateZ = Z;
}
void Vector::operator=(Vector Vec) {
	CoordinateX = Vec.CoordinateX;
	CoordinateY = Vec.CoordinateY;
	CoordinateZ = Vec.CoordinateZ;
}
Vector::Vector(Vector const& Vec) :CoordinateX(Vec.CoordinateX), CoordinateY(Vec.CoordinateY), CoordinateZ(Vec.CoordinateZ)
{}
void Vector::PutVector() {
	std::cout << "ответ : ";
	std::cout << "(" << CoordinateX << "," << CoordinateY << "," << CoordinateZ << ")" << std::endl;
}