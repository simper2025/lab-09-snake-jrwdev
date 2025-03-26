#include <chrono>
#include <Windows.h>
#include "GameRunner.hpp"
#include "Console.hpp"
#include <conio.h>


GameRunner::GameRunner(float fps)
    : frame_duration(fps),
    keypress(KeyCommand::NONE),
    snake(12, 14, { 10, 10 }, { 1, 0 }, 5),
    mouse(),
    game_over(false)
{
    mouse.Move(WIDTH, HEIGHT);
}

void GameRunner::RunGame() {
    Console::drawBorder(WIDTH, HEIGHT);
    snake.draw();
    mouse.draw();

    while (!game_over) {
        KeyCommand key = keyboard.get_key();
        if (key == KeyCommand::QUIT) {
            game_over = true;
            continue;
        }

        snake.move(key);

        if (snake.getHead().x == mouse.getLocation().x && snake.getHead().y == mouse.getLocation().y) {
            snake.grow();
            mouse.Move(WIDTH, HEIGHT);
        }

        if (snake.checkCollision(WIDTH, HEIGHT)) {
            game_over = true;
        }

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                Console::txtPlot({ x, y }, 0);
            }
        }

        Console::drawBorder(WIDTH, HEIGHT);
        snake.draw();
        mouse.draw();

        Console::setColor(15);
        Console::gotoXY(0, HEIGHT);
        _cprintf("Length: %d", snake.getLength());

        Sleep(frame_duration);
    }

    Console::setColor(15);
    Console::gotoXY(0, HEIGHT + 1);
    _cprintf("Game Over! Final Length: %d", snake.getLength());
}
