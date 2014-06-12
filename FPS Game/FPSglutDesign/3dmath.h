#ifndef DMATH_H
#define DMATH_H
#define _USE_MATH_DEFINES
#pragma warning(disable: 4996)
#include<GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string>
#include<iostream>
using namespace std;
class Vector3d
{
private:	
	double x;
	double y;
	double z;


public:	Vector3d();
		Vector3d(double _x, double _y, double _z);
		Vector3d& operator+=(const Vector3d& r);
		Vector3d& operator-=(const Vector3d& r);
		Vector3d& operator/=(const Vector3d& r);
		Vector3d& operator*(double f);
		Vector3d Vector3d::Cross(const Vector3d& v) const;
		void setX(double _x);
		void setY(double _y);
		void setZ(double _z);
		double getX();
		double getY();
		double getZ();
};
#endif