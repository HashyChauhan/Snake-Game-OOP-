#include "snake.h"

Snake::Snake(int length, char head_style, char body_style, char direction) 
    :length{length}, head_style{head_style}, body_style{body_style}, direction{direction} {

	    for (int i{1}; i <= length; i++)
			body.push_front(std::pair<int, int>{i, 1});
}
char Snake::get_direction() const {
	return direction;
}
int Snake::get_length() const {
	return length;
}
char Snake::get_head_style() const {
	return head_style;
}
char Snake::get_body_style() const {
	return body_style;
}
void Snake::move() {
        std::pair<int, int> forward_point;
        if (direction == 'a')
            forward_point = std::make_pair(get_head().first - 1, get_head().second); //(column,line)
        else if (direction == 'd')
            forward_point = std::make_pair(get_head().first + 1, get_head().second);
        else if (direction == 'w')
            forward_point = std::make_pair(get_head().first, get_head().second - 1);    
        else if (direction == 's')
            forward_point = std::make_pair(get_head().first, get_head().second + 1);
        body.push_front(forward_point);
        body.pop_back(); //For balancing
}
void Snake::growup() {
    body.push_back(body.back());
    length++;
}
std::deque<std::pair<int, int>> Snake::get_body() const {
    return body;
}
std::pair<int, int> Snake::get_head() const {
    return body.front();
}
void Snake::set_direction(char c) {
    if (c == 'a' || c == 'd' || c == 's' || c == 'w') {
        direction = c;
    }
}
Snake::~Snake() {}
