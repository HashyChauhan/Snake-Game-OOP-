#ifndef APPLE_H_
#define APPLE_H_

#include <utility>      // NULL printf()
#include <stdlib.h>     //rand() srand()
#include <time.h>       //time() 
class Apple { 
	private:
	    std::pair<int, int> pos;
	    int speed;
	public:
	    Apple(std::pair<int, int> pos = {10, 10}, int speed = 1);
	    
	    std::pair<int, int> get_pos() const;
	    void generate_apple(int width, int height);  
	    ~Apple();
};
#endif

