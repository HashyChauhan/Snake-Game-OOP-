#ifndef Game_H_
#define Game_H_

#include "snake.h"
#include "map.h"
#include "apple.h"
#include<algorithm>
#include <iostream>
class Game {
	private:
	    Map map;
	    Snake snake;
	    Apple apple;
	    int score;
	    int speed;
	public:
	    Game();
	    void check_eating();
	    bool ckeck_hitting_wall();
	    bool check_hitting_himself();
	    void running();
	    bool regame();
	    char controls();
	    void clearScreen();
		~Game();
};
#endif
