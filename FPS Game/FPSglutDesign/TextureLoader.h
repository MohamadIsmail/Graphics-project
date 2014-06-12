#ifndef TextureLoader_H
#define TextureLoader_H
#include"3dmath.h"
class TextureLoader
{
public:
	static GLuint LoadTexture( const char * filename, int width, int height );
	static void FreeTexture( GLuint texture );
};

#endif