#ifndef PLAYER_H
#define PLAYER_H
#include"3dmath.h"
class Player
    {
	private: 
		Vector3d m_position;
		double m_facing;
		double m_pitch;

	public: 
		Player(double x,double y,double z);
		Vector3d getPosition();
		void setPosition(Vector3d tmp);
		double getFacing();
		void setFacing(double value);
		double getPitch();
		void setPitch(double value);
		Vector3d Forwards();
		Vector3d Sideways();
    };

#endif