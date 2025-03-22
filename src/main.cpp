#include <iostream>
#include <TerminalUtilities.h>
#include "GameHelper/GameState.h"
#include "GameHelper/Scene/SceneLoader.h"
using namespace UtilityClasses;

int updateLoop(GameState* gameState);

int main() {
    std::map<std::string, std::function<Assets::Asset()>> assetmap = {{"Tree", []{return Assets::Asset();}}};
    auto gameState = GameState();
    std::string path = "/home/shuviu/01_Data/24_Cpp/GameEngine/TestAssets/testScene.txt";
    gameState.SetScene(new Scene(&path, assetmap));
    gameState.Initialize(updateLoop);
    return 0;
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