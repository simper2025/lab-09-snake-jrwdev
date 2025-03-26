#include "GameRunner.hpp"

float frame_duration = 0.1; //in seconds

int main() {
    GameRunner game(frame_duration * 1000);
    game.RunGame();
    return 0;
}