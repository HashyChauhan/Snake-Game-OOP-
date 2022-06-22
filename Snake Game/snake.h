#ifndef SNAKE_H_
#define SNAKE_H_

#include <deque>
class Snake {
	private:
	    int length;
	    std::deque<std::pair<int, int>> body;
	    char head_style{};
	    char body_style{};
	    char direction{};

	public:
	    Snake (int length = 2, char head_style = 'O', char body_style = 'o', char direction = 'd');
	    void move();
	    void set_direction(char c);
	    char get_direction() const;
	    void growup();
	    std::deque<std::pair<int, int>> get_body() const;
	    std::pair<int, int> get_head() const;
	    int get_length() const;
	    char get_head_style() const;
	    char get_body_style() const;
	    ~Snake();
};
#endif
