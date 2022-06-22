#include "map.h"
void ClearScreen()
{
	COORD cursorPosition;   cursorPosition.X = 0;   cursorPosition.Y = 0;   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
Map::Map(int width, int height)
    :width{width}, height{height}, board{std::vector<std::vector<char>> (height, std::vector<char>(width, ' '))} {} //removing garbage value from board 
    
void Map::draw(const Snake &s, const Apple &a) {
    ClearScreen();
    for(int i{0}; i < board.size(); i++)
        for (int j{0}; j < board[0].size(); j++) {
            if (i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1)
                board.at(i).at(j) = '#';     //set wall points
            else
                board.at(i).at(j) = ' ';
        }
    auto apple_pos = a.get_pos();
    board.at(apple_pos.second).at(apple_pos.first) = '*';
    auto snake_body = s.get_body();
    for (const auto &point : snake_body) //range based loop jb tak value return hogi ye chalega
        board.at(point.second).at(point.first) = s.get_body_style();
    	board.at(s.get_head().second).at(s.get_head().first) = s.get_head_style();
    for (const auto &row : board) { //board ki branches row me aayeingi
        for (const auto &point : row) //row ki strings 1 by 1 point me aayeingi
            std::cout << point;
        
        std::cout << std::endl;
    }
    std::cout << "Score = " << s.get_length() - 5 << std::endl;
}
int Map::get_width() const {
	return width;
}
int Map::get_height() const {
	return height;
}
std::vector<std::pair<int, int>> Map::get_wall() const {
    std::vector<std::pair<int, int>> wall_points;
    for (int i{0}; i < board.size(); i++)
        for (int j{0}; j < board.at(0).size(); j++)
            if (i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1)
                wall_points.push_back(std::make_pair(j, i));//(column,line)
                
    return wall_points;
}
Map::~Map() {}
