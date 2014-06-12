#ifndef _OBJECT_LOADER_H_
#define _OBJECT_LOADER_H_

#include "GL/glew.h"
#include "GL/freeglut.h"
#include "3dmath.h"
#include "GL/glu.h"
#include "GL/gl.h"
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<cstdio>
#include<iostream>
using namespace std;


struct coordinate
{
public :
	float x,y,z;
	coordinate(float , float , float) ;
};

struct face {
	int facenum;
	bool four;
	int faces[4];
	face(int ,int,int ,int );
	face(int ,int ,int ,int ,int );

};

class objectLoader{
private : 
	
	int loadObject(const char *);
public:
	void init(const char *);
	static void display(objectLoader &);
	float angle;
	int cube;
};

#endif