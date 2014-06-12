#include"Keyboard.h"

bool Keyboard ::keyStates[256]={0};
bool Keyboard ::specialKeyStates[256]={0};

void Keyboard:: keyPressed(unsigned char key, int x, int y)
{
	keyStates[key]=true;
}

void Keyboard:: keyReleased(unsigned char key, int x, int y)
{
	keyStates[key]=false;
}
void Keyboard:: specialKeyPressed(int key, int x, int y)
{
	specialKeyStates[key]=true;
}

void Keyboard:: specialKeyReleased(int key, int x, int y)
{
	specialKeyStates[key]=false;
}

void Keyboard:: keyOperations(Player &p) 
{
	if(keyStates[27])
		glutLeaveMainLoop();
	if(keyStates['s'])
	{

		Vector3d tmp=p.getPosition();
		tmp+=p.Forwards()*0.8*glutGet(GL_TIME_ELAPSED);
		p.setPosition(tmp);
	}
	if(keyStates['w'])
	{
		Vector3d tmp=p.getPosition();
		tmp-=p.Forwards()*0.8*glutGet(GL_TIME_ELAPSED);
		p.setPosition(tmp);
	}
	if(keyStates['d'])
	{
		Vector3d tmp=p.getPosition();
		tmp+=p.Sideways()*0.8*glutGet(GL_TIME_ELAPSED);
		p.setPosition(tmp);
	}
	if(keyStates['a'])
	{
		Vector3d tmp=p.getPosition();
		tmp-=p.Sideways()*0.8*glutGet(GL_TIME_ELAPSED);
		p.setPosition(tmp);
	}
	if(specialKeyStates[GLUT_KEY_UP])
	{
		Vector3d tmp=p.getPosition();
		tmp.setY(tmp.getY()+5);
		p.setPosition(tmp);
	}
	if(specialKeyStates[GLUT_KEY_DOWN])
	{
		Vector3d tmp=p.getPosition();
		tmp.setY(tmp.getY()-5);
		p.setPosition(tmp);
	}
}