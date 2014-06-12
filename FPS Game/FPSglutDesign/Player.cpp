#include"Player.h"
#include"Utils.h"
Player::Player(double x,double y,double z)
{
	m_position.setX(x);
	m_position.setY(y);
	m_position.setZ(z);
}

Vector3d Player:: getPosition()
{
	return m_position;
}

void Player:: setPosition(Vector3d tmp)
{
	m_position=tmp;
}
double Player:: getFacing()
{
	return m_facing; 
}
void Player:: setFacing(double value)
{
	m_facing=Utils::WrapAngle(value);
}

double Player:: getPitch()
{
	return m_pitch; 

}
void Player::setPitch(double value)
{
	m_pitch = Utils::LimitAngle(value, -89, 89); 
}

Vector3d Player:: Forwards()
{

	double r = Utils::ToRadians(m_facing);
	return Vector3d(-sin(r), 0, -cos(r));

}

Vector3d Player:: Sideways()
{

	double r = Utils::ToRadians(m_facing);
	return  Vector3d(-cos(r), 0, sin(r));
}