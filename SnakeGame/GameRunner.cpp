#include <chrono>
#include <windows.h>
#include "GameRunner.hpp"
#include "Console.hpp"


GameRunner::GameRunner(float fps) {
    keypress = KeyCommand::RIGHT;
    mouse.Move(20, 20);
}

void GameRunner::RunGame() {
    int keypress = 0;
    std::chrono::time_point<std::chrono::system_clock> runTime;
    std::chrono::time_point<std::chrono::system_clock> currentTime;
    runTime = std::chrono::system_clock::now();
    Sleep(300);

    point playerloc = { 0, 10 };
    point direction = { 1, 0 };
    int length = 5;

    Keyboard keyboard;
    Console console;

    //Loop to start drawing and playing.
    while (keypress != key_ESCAPE) {
        KeyCommand key = keyboard.get_key();

        switch (key) {
        case KeyCommand::LEFT:
            direction = { -1, 0 };
            break;
        case KeyCommand::RIGHT:
            direction = { 0, -1 };
            break;
        case KeyCommand::UP:
            direction = { 0, -1 };
            break;
        case KeyCommand::DOWN:
            direction = { 0, 1 };
            break;
        case KeyCommand::QUIT:
            keypress = key_ESCAPE;
            break;
        default:
            break;
        }

    currentTime = std::chrono::system_clock::now();

    double elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - runTime).count();
    if (elapsedTime > 0.3 * 1000) {
        runTime = std::chrono::system_clock::now();

        //Most of your game logic goes here.
        /*console.txtPlot(playerloc, 31);

        console.setcolor(15);
        console.gotoxy(1, 21);
        _cprintf("Length: %i", length);*/


    }

    Sleep(10);
    //}
}
