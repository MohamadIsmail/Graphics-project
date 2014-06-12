#include"Environment1.h"

void Environment1:: DrawCrate (GLfloat x,GLfloat y,GLfloat z,GLfloat ori) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(ori, 0, 1, 0);
	glBindTexture( GL_TEXTURE_2D, texture1 ); //bind our texture to our shape
	glBegin (GL_QUADS);

	glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(0, 0, 0);
	glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(20, 0, 0);
	glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(20, 20, 0);
	glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(0, 20, 0);

	glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(20, 0, 0);
	glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(20, 0, -20);
	glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(20, 20, -20);
	glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(20, 20, 0);

	glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(0, 0, 0);
	glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(0, 0, -20);
	glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(20, 0, -20);
	glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(20, 0, 0);

	glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(0, 0, -20);
	glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(0, 0, 0);
	glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(0, 20, 0);
	glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(0, 20, -20);

	glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(0, 20, 0);
	glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(20, 20, 0);
	glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(20, 20, -20);
	glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(0, 20, -20);

	glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(20, 0, -20);
	glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(0, 0, -20);
	glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(0, 20, -20);
	glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(20, 20, -20);

	glEnd();
	glPopMatrix();
}

void  Environment1:: drawWall(GLfloat x, GLfloat y, GLfloat z, GLfloat ori,string wall)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(ori, 0, 1, 0);
	glBindTexture( GL_TEXTURE_2D, texture2 ); //bind our texture to our shape
	glBegin (GL_QUADS);
	glColor3f((GLfloat)0.3,(GLfloat)0.3,(GLfloat)0.3);
	if (wall == "floor")
	{
		glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(0, 20, 0);
		glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(20, 20, 0);
		glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(20, 20, -20);
		glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(0, 20, -20);

		glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(0, 20, 0);
		glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(0, 20, -20);
		glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(20, 20, -20);
		glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(20, 20, 0);
	}
	else if (wall == "wall")
	{
		glTexCoord2d(0.0f, 1.0f - 0.0f); glVertex3d(0, 0, 0);
		glTexCoord2d(1.0f, 1.0f - 0.0f); glVertex3d(20, 0, 0);
		glTexCoord2d(1.0f, 1.0f - 1.0f); glVertex3d(20, 20, 0);
		glTexCoord2d(0.0f, 1.0f - 1.0f); glVertex3d(0, 20, 0);
	}
	glEnd();
	glPopMatrix();

}



 void Environment1:: LoadEnvironment()
{
	texture1 = TextureLoader::LoadTexture( "crate4.bmp", 1024, 1024 );
	texture2 = TextureLoader::LoadTexture( "floor2.bmp", 1024, 1024 );
	sky.loadSkybox(/*"jajlands1_ft.bmp"*/"sky2.bmp");
	obj.init("cube.obj");
	street=new SkeletalObject("MapShipment.3ds");
	//street->applyTexture("000c9d3e.dds");
	//street->applyTexture("4a535bac.dds");
	street->CreateVBO();
}
void  Environment1:: UnLoadTextures()
{
	TextureLoader::FreeTexture( texture1);
	TextureLoader::FreeTexture( texture2);
	sky.releaseSkybox();
}
void Environment1::  DrawEnvironment()
{
	sky.renderSkybox();
	DrawCrate(20, -39, -130, 0);
	for (GLfloat i = 0; i <= 140; i += 20)
	{
		for (GLfloat j = 0; j <= 140; j += 20)
		{
			drawWall(i, -60, -200 + j, 0, "floor");
			drawWall(i, 40, -200 + j, 0, "floor");
			drawWall(i, -60 + j, -200, 0, "wall");
			drawWall(i, -60 + j, -60, 0, "wall");
			drawWall(0, -60 + j, -200 + i, 90, "wall");
			drawWall(140, -60 + j, -200 + i, 90, "wall");
		}
	}
	objectLoader::display(obj);
	glPushMatrix();
	glRotatef(270,1,0,0);
	glTranslatef(-100,-100,0);
	glScalef(20,20,20);
	street->Draw();
	glPopMatrix();
}
