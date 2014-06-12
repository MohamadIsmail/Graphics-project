#include"Utils.h"

double Utils::  WrapAngle(double x)
{
	while (x >= 360)
		x -= 360;

	while (x < 0)
		x += 360;

	return x;
}

double Utils:: LimitAngle(double x, double min, double max)
{
	if (x < min)
		return min;
	else if (x > max)
		return max;
	else
		return x;
}
double Utils:: ToRadians(double value)
{
	return (value*(M_PI/180));
}