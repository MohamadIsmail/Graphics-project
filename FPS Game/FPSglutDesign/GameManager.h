#ifndef GameManager_H
#define GameManager_H
#include"Environment1.h"
#include"Player.h"
#include"Keyboard.h"
#include"Mouse.h"
class GameManager
{
private:
	static Environment1 level;
	static void enable ();
	static void reshape (int w, int h);
	static void display ();
	static void LoadContent();
public:
	static Player p;
	static void init(int argc,char** argv);

};

#endif