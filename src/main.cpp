#include <iostream>
#include <TerminalUtilities.h>
#include "GameHelper/GameState.h"
#include "GameHelper/Scene/SceneLoader.h"
using namespace UtilityClasses;

void testRenderPlayer(const std::tuple<int, int> &pos);

int updateLoop(GameState* gameState);


int main() {

    const std::tuple<int, int> pos = std::make_tuple(5, 5);
    testRenderPlayer(pos);

    auto gameState = GameState();
    std::string path = "/home/shuviu/01_Data/24_Cpp/GameEngine/TestAssets/testScene.txt";
    gameState.SetScene(new Scene(&path));
    gameState.Initialize(updateLoop);
    Console::StdReadKey();
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