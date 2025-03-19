//
// Created by shuviu on 3/9/25.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <chrono>
#include <functional>
#include <thread>

#include "IO/InputHandlerAsync.h"
#include "Scene/Scene.h"
using namespace std::chrono;

class GameState {
private:
    Scene* currScene_{};
    int keyPressed_;
    bool isRunning_;
    bool keyUpdate_;
    static void StartInputHandlerAsync(UtilityClasses::InputHandlerAsync *inputHandler);
    int FetchPressedKey(UtilityClasses::InputHandlerAsync *inputHandler);

    public:
        GameState();
        void Initialize(const std::function<int(GameState*)>& UpdateLoop);
        int GetKeyPressed();
        [[nodiscard]] Scene* GetScene() const;
        void SetScene(Scene* scene);
        [[nodiscard]] bool GetKeyUpdate() const;

};

#endif //GAMESTATE_H
