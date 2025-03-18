#include <iostream>
#include <TerminalUtilities.h>
#include "GameHelper/GameState.h"
using namespace UtilityClasses;

void testRenderPlayer(const std::tuple<int, int> &pos);

int updateLoop(GameState* gameState);


int main() {

    const std::tuple<int, int> pos = std::make_tuple(5, 5);
    testRenderPlayer(pos);

    auto gameState = GameState();
    gameState.SetScene(new Scene(5, 5));
    gameState.Initialize(updateLoop);

    return 0;
}

void testRenderPlayer(const std::tuple<int, int> &pos) {
    Console::SetCursor(std::get<0>(pos), std::get<1>(pos));
    std::cout << 'x';
}

int updateLoop(GameState* gameState) {
    int keyPressed = gameState->GetKeyPressed() ? gameState->GetKeyPressed() : -1;

    if (keyPressed != -1) {
        std::cout << keyPressed;
    }

    if (keyPressed == 10) {
        return 1;
    }

    return 0;
}