#include"3dmath.h"

Vector3d::Vector3d()
{
}
Vector3d::Vector3d(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3d&Vector3d:: operator+=(const Vector3d& r)
{
	x += r.x;
	y += r.y;
	z += r.z;
	return *this;
}

Vector3d& Vector3d::  operator-=(const Vector3d& r)
{
	x -= r.x;
	y -= r.y;
	z -= r.z;

	return *this;
}
Vector3d& Vector3d:: operator/=(const Vector3d& r)
{
	x /= r.x;
	y /= r.y;
	z /= r.z;

	return *this;
}
Vector3d& Vector3d::operator*(double f)
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}
Vector3d Vector3d::Cross(const Vector3d& v) const
{
	const double _x = y * v.z - z * v.y;
	const double _y = z * v.x - x * v.z;
	const double _z = x * v.y - y * v.x;
	return Vector3d(_x, _y, _z);
}
void Vector3d:: setX(double _x)
{
	x=_x;
}
void Vector3d:: setY(double _y)
{
	y=_y;
}
void Vector3d:: setZ(double _z)
{
	z=_z;
}
double Vector3d::getX()
{
	return x;
}
double Vector3d::getY()
{
	return y;
}
double Vector3d::getZ()
{
	return z;
}