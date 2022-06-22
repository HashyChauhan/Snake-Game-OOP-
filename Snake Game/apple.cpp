#include "apple.h"
Apple::Apple(std::pair<int, int> pos, int speed):pos{pos}, speed{speed} {}

void Apple::generate_apple(int width, int height) {
    srand(time(0));
    pos.first = rand()%(width-2) + 1;
    pos.second = rand()%(height-2) + 1;
}
std::pair<int, int> Apple::get_pos() const {
	return pos;
}
Apple::~Apple() {}
