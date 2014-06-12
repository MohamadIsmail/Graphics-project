#ifndef ENVIRONMENT1_H
#define ENVIRONMENT1_H
#include"Environment.h"
#include"SkeletalObject.h"
#include"SkyBox.h"
class Environment1 :Environment
{
private:
	GLuint texture1,texture2; //the array for our texture
	objectLoader obj;
	SkeletalObject* street;
	SkyBox sky;

	void DrawCrate (GLfloat x,GLfloat y,GLfloat z,GLfloat ori);

	void drawWall(GLfloat x, GLfloat y, GLfloat z, GLfloat ori,string wall);


public:
	void LoadEnvironment();
	void UnLoadTextures();
	void DrawEnvironment();
};

#endif