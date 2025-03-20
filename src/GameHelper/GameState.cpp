//
// Created by shuviu on 3/9/25.
//

#include "GameState.h"

#include "IO/InputHandlerAsync.h"


//// ---- Constructors ---- ////
GameState::GameState() {
    keyUpdate_ = false;
    isRunning_ = false;
    keyPressed_ = -1;
}
//// ---- Getter ---- ////
int GameState::GetKeyPressed() {
    keyUpdate_ = false;
    return keyPressed_;
}

bool GameState::GetKeyUpdate() const {
    return keyUpdate_;
}

Scene* GameState::GetScene() const {
    return currScene_;
}
//// ---- Setter ---- ////
void GameState::SetScene(Scene *scene) {
    currScene_ = scene;
}

//// ---- Methods ---- ////
void GameState::Initialize(const std::function<int(GameState *)> &UpdateLoop)
{
    // Init params
    isRunning_ = true;
    time_point<steady_clock> lastUpdate = std::chrono::steady_clock::now();
    UtilityClasses::InputHandlerAsync inputHandler = UtilityClasses::InputHandlerAsync();

    // Start the Inputhandler for async input fetching
    StartInputHandlerAsync(&inputHandler);

    while (true) {
        // Fetch curr time
        time_point<steady_clock> now = std::chrono::steady_clock::now();

        // Check if time passed is enough for new update
        auto duration = now - lastUpdate;

        if (duration.count() > 0.5l) {
            // Fetch the last keypress
            keyPressed_ = FetchPressedKey(&inputHandler);
            // Render current Scene
            currScene_->Render();
            // Call the update loop
            const int updateRet = UpdateLoop(this);
            // Check is updateLoop exits
            if (updateRet != 0) {
                // Break Gameloop
                break;
            }

            lastUpdate = now;
        }
        else {
            // Let thread sleep for rest duration
            std::this_thread::sleep_for(duration);
        }
    }

    // Clean up
    inputHandler.Stop();
    inputHandler.~InputHandlerAsync();
}

void GameState::StartInputHandlerAsync(UtilityClasses::InputHandlerAsync* inputHandler) {
    std::thread worker (&UtilityClasses::InputHandlerAsync::Start, inputHandler);
    worker.detach();
}

int GameState::FetchPressedKey(UtilityClasses::InputHandlerAsync *inputHandler) {
    if (inputHandler->KeyUpdate()) {
        keyUpdate_ = true;
        return inputHandler->InputKey();
    }
    else {
        keyUpdate_ = false;
        return -1;
    }
    return inputHandler->KeyUpdate() ? inputHandler->InputKey() : -1;
}