#include "Game.h"
Game::Game() {
      do {
        system("cls");
        map = Map(50, 25);
        snake = Snake(5, 'O', 'o');
        apple  = Apple();
        score = 0;
        speed = 10;
        running();
    } while(regame());
}
void Game::running() {
    while (!(ckeck_hitting_wall() || check_hitting_himself())) {
        clearScreen();
        map.draw(snake, apple);
        speed = ((30 - 2 * score) >= 0 )? (30 - 2 * score) : 0;
        snake.set_direction(controls());
        snake.move();
        check_eating();
        controls();
        Sleep(speed);
    }
}
bool Game::regame() {
    std::cout << "======Game over======" << std::endl;
    std::cout << "replay ?? (y/n) " << std::endl;
    char c{};
    bool isvalid{false};
    do {
        std::cin >> c;
        if (c == 'y')
            return true;
        else if (c == 'n')
            return false;
        else {
            std::cout << "invalid entry\n";
            isvalid = true;
        }
    } while(isvalid);
}

void Game::check_eating() {
    int x_snake_head = snake.get_head().first;
    int y_snake_head = snake.get_head().second;
    int x_apple = apple.get_pos().first;
    int y_apple = apple.get_pos().second;
    
    
    if (x_snake_head == x_apple && y_snake_head == y_apple) {
        score++;
        snake.growup();
        apple.generate_apple(map.get_width(), map.get_height());
    }
        
}
bool Game::ckeck_hitting_wall() {
    int x_snake_head = snake.get_head().first;
    int y_snake_head = snake.get_head().second;
    auto wall_points = map.get_wall();
    
    for (const auto &point : wall_points)
        if (x_snake_head == point.first && y_snake_head == point.second)
            return true;
    
    return false;
}
bool Game::check_hitting_himself() {
    auto snake_points = snake.get_body();
    auto snake_head = snake.get_head();
    if (std::count(snake_points.begin(), snake_points.end(), snake_head) > 1)
        return true;

    return false;
}
char Game::controls() {
    if (GetAsyncKeyState(VK_UP) && snake.get_direction() != 's')
        return 'w';
    else if (GetAsyncKeyState(VK_DOWN) && snake.get_direction() != 'w')
        return 's';
    else if (GetAsyncKeyState(VK_RIGHT) && snake.get_direction() != 'a')
        return 'd';
    else if (GetAsyncKeyState(VK_LEFT) && snake.get_direction() != 'd')
        return 'a';
}
void Game::clearScreen() {
	// Function which cleans the screen without flickering
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
Game::~Game() {}
