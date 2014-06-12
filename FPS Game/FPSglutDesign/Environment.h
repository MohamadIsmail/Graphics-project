#ifndef Environment_H
#define Environment_H
#include"ObjectLoader.h"
#include"TextureLoader.h"
class Environment
{
public:
	virtual	void LoadEnvironment() {}
	virtual void UnLoadTextures() {}
	virtual void DrawEnvironment() {}
};

#endif