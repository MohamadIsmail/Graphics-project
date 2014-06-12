#include "ObjectLoader.h"

coordinate:: coordinate(float _x , float _y, float _z) :x(_x), y(_y),z(_z){}

face ::face (int facen,int f1,int f2,int f3): facenum(facen)
{
	faces[0]=f1;
	faces[1]=f2;
	faces[2]=f3;
	four=false;
}

face::face(int facen,int f1,int f2,int f3,int f4) : facenum(facen){ //overloaded constructor for quad
	faces[0]=f1;
	faces[1]=f2;
	faces[2]=f3;
	faces[3]=f4;
	four=true;
}

int objectLoader:: loadObject(const char *filename)
{
	vector<string*> coord;
	vector<coordinate*>vertex;
	vector<face*>faces;
	vector<coordinate*>normals;
	ifstream in(filename);
	if(!in.is_open())
	{
		cout << "not opened\n";
		return -1;
	}
	char buffer[4096];
	while (!in.eof())
	{
		in.getline(buffer,4096);
		coord.push_back(new string (buffer));

	}

	for (int i = 0; i < (int)coord.size(); i++)
	{
		if(coord[i]->c_str()[0]=='#')   //if it is a comment (the first character is #)
			continue;       //we don't care about that
		else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' ') //if vector
		{
			float tmpx,tmpy,tmpz;
			sscanf_s(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);       //read in the 3 float coordinate to tmpx,tmpy,tmpz
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));       //and then add it to the end of our vertex list
		}
		else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]=='n')        //if normal vector
		{
			float tmpx,tmpy,tmpz;   //do the same thing
			sscanf_s(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));     
		}
		else if(coord[i]->c_str()[0]=='f')     //if face
		{
			int a,b,c,d,e;
			if(count(coord[i]->begin(),coord[i]->end(),' ')==3)     //if it is a triangle (it has 3 space in it)
			{
				sscanf_s(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				faces.push_back(new face(b,a,c,d));     //read in, and add to the end of the face list
			}
			else{
				sscanf_s(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				faces.push_back(new face(b,a,c,d,e));   //do the same, except we call another constructor, and we use different pattern
			}
		}
	}

	int num=glGenLists(1);

	glNewList(num,GL_COMPILE);
	for (int i = 0; i < (int)faces.size(); i++)
	{
		if(faces[i]->four)
		{
			glBegin(GL_QUADS);
			glNormal3f(normals[faces[i]->facenum-1]->x,normals[faces[i]->facenum-1]->y,normals[faces[i]->facenum-1]->z);
			//draw the faces
			glVertex3f(vertex[faces[i]->faces[0]-1]->x,vertex[faces[i]->faces[0]-1]->y,vertex[faces[i]->faces[0]-1]->z);
			glVertex3f(vertex[faces[i]->faces[1]-1]->x,vertex[faces[i]->faces[1]-1]->y,vertex[faces[i]->faces[1]-1]->z);
			glVertex3f(vertex[faces[i]->faces[2]-1]->x,vertex[faces[i]->faces[2]-1]->y,vertex[faces[i]->faces[2]-1]->z);
			glVertex3f(vertex[faces[i]->faces[3]-1]->x,vertex[faces[i]->faces[3]-1]->y,vertex[faces[i]->faces[3]-1]->z);
			glEnd();
		}
		else{
			glBegin(GL_TRIANGLES);
			glNormal3f(normals[faces[i]->facenum-1]->x,normals[faces[i]->facenum-1]->y,normals[faces[i]->facenum-1]->z);
			glVertex3f(vertex[faces[i]->faces[0]-1]->x,vertex[faces[i]->faces[0]-1]->y,vertex[faces[i]->faces[0]-1]->z);
			glVertex3f(vertex[faces[i]->faces[1]-1]->x,vertex[faces[i]->faces[1]-1]->y,vertex[faces[i]->faces[1]-1]->z);
			glVertex3f(vertex[faces[i]->faces[2]-1]->x,vertex[faces[i]->faces[2]-1]->y,vertex[faces[i]->faces[2]-1]->z);
			glEnd();
		}
	}
	glEndList();

	for (int i = 0; i <(int) coord.size(); i++)
		delete coord[i];

	for (int i = 0; i <(int) faces.size(); i++)
		delete faces[i];

	for(int i=0;i<(int) normals.size();i++)
		delete normals[i];

	for(int i=0;i<(int) vertex.size();i++)
		delete vertex[i];

	return num;
}

void objectLoader:: init(const char *filename)
{
	angle=0.0;
	//glClearColor(0.0,0.0,0.0,1.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(45,640.0/480.0,1.0,500.0);
	//glMatrixMode(GL_MODELVIEW);
	//glEnable(GL_DEPTH_TEST);
	cube=loadObject(filename);    //load the test.obj file
	//glEnable(GL_LIGHTING);  //we enable lighting, to make the 3D object to 3D
	//glEnable(GL_LIGHT0);
	//float col[]={1.0,1.0,1.0,1.0};  //light color is white
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
}

void objectLoader:: display(objectLoader &object)
{
	glPushMatrix();
	float pos[]={-2.0,3.0,-4.0,1.0};        //set the position
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	glTranslatef(0.0,0.0,-300.0);
	glRotatef(object.angle,1.0,1.0,1.0);
	glCallList(object.cube);  //draw the 3D mesh
	object.angle+=0.8f;
	if(object.angle>360)
		object.angle-=360;
	glEnd();
	glPopMatrix();
}
