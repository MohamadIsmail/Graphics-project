#ifndef UTILS_H
#define UTILS_H
#include"3dmath.h"
class Utils
{

public: 
	static double WrapAngle(double x);
	static double LimitAngle(double x, double min, double max);
	static double ToRadians(double value);
};

#endif