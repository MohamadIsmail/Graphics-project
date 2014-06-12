#ifndef KEYBOARD_H
#define KEYBOARD_H
#include"Player.h"
class Keyboard{
private:
	static bool keyStates[256];
	static bool specialKeyStates[256];
public:
	static void keyOperations(Player &);
	static void specialKeyReleased(int, int , int);
	static void specialKeyPressed(int, int, int);
	static void keyReleased(unsigned char, int, int);
	static void keyPressed(unsigned char, int, int);
};
#endif