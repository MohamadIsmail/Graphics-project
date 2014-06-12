#include"SkyBox.h"

void SkyBox::loadSkybox(const char * a_sFront)
{
	texture=TextureLoader::LoadTexture(a_sFront,4096,4096);
}

void SkyBox::renderSkybox()
{
	// Store the current matrix
	GLUquadricObj *sphere;
	glPushMatrix();
//	Enable/Disable features
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_BLEND);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluQuadricTexture(sphere, GL_TRUE);
	gluQuadricNormals(sphere, GLU_SMOOTH);

	glBindTexture(GL_TEXTURE_2D, texture);

	gluSphere(sphere, 4000000.0, 1000, 1000);
	glEnd();
	glPopAttrib();
	glPopMatrix();



}

void SkyBox::releaseSkybox()
{
	   TextureLoader::FreeTexture(texture);
}