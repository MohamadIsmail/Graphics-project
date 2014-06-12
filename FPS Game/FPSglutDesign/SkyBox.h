#include"3dmath.h"
#include"TextureLoader.h"
class SkyBox
{
private:
	GLuint texture;

public:
	void loadSkybox(const char * a_sFront);
	void renderSkybox();
	void releaseSkybox();
};