#include"Mouse.h"
void Mouse::centerMouse()
{
	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2,glutGet(GLUT_WINDOW_HEIGHT)/2);
}

void Mouse:: mouseMovement(int x,int y)
{
	double tmp=GameManager::p.getFacing()*0.001;
	tmp+= (x - glutGet(GLUT_WINDOW_WIDTH)/2) * -1;
	GameManager::p.setFacing(tmp);
	tmp=GameManager::p.getPitch()*0.001;
	tmp+= (y - glutGet(GLUT_WINDOW_HEIGHT)/2) * -1;
	GameManager::p.setPitch(tmp);
}