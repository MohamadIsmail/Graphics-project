#include"GameManager.h"
Player GameManager :: p= Player(20,0,-100);
Environment1 GameManager ::level =Environment1();
void GameManager::enable() 
{
    glEnable (GL_DEPTH_TEST); //enable the depth testing
	glEnable( GL_TEXTURE_2D );
	glEnable(GL_MULTISAMPLE);
   // glEnable (GL_LIGHTING); //enable the lighting
   // glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
	glutSetCursor(GLUT_CURSOR_NONE);
}

void GameManager::reshape (int w, int h) 
{
	glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
	glMatrixMode (GL_PROJECTION); //set the matrix to projection
	glLoadIdentity ();
	gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 10000000.0); //set the perspective (angle of sight, width, height, , depth)
	glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}

void GameManager::display () 
{
	Keyboard::keyOperations(p);
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glLoadIdentity();  
	glRotated(-p.getPitch(), 1.0f, 0.0f, 0.0f);
	glRotated(-p.getFacing(), 0.0f, 1.0f, 0.0f);
	glTranslatef(-(GLfloat)p.getPosition().getX(),-(GLfloat)p.getPosition().getY(),-(GLfloat)p.getPosition().getZ());
	level.DrawEnvironment();
    glutSwapBuffers(); //swap the buffers
	glFinish();
}

void GameManager::LoadContent()
{
	level.LoadEnvironment();
}

void GameManager::init(int argc,char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH| GLUT_MULTISAMPLE|GLUT_RGBA);
    glutInitWindowSize (1024, 600);
    glutInitWindowPosition (150, 60);
    glutCreateWindow ("Epic Room");
	glewInit();
	LoadContent();
	enable();
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);
	glutKeyboardFunc(Keyboard::keyPressed);
	glutKeyboardUpFunc(Keyboard:: keyReleased);
	glutSpecialFunc(Keyboard:: specialKeyPressed);
	glutSpecialUpFunc(Keyboard:: specialKeyReleased);
	glutPassiveMotionFunc(Mouse:: mouseMovement);
	Mouse::centerMouse();
    glutMainLoop ();
	level.UnLoadTextures();
}