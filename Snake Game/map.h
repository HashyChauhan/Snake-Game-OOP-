#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <iostream>
#include <windows.h>
#include "snake.h"
#include "apple.h"
class Map {
	private:
	    int width;
	    int height;
	    std::vector<std::vector<char>> board;
	public:
	    Map(int width = 50, int height = 50);
	    void draw(const Snake &s, const Apple &a);
	    int get_width() const;
	    int get_height() const;
	    std::vector<std::pair<int, int>> get_wall() const;
	    ~Map();
};
#endif
