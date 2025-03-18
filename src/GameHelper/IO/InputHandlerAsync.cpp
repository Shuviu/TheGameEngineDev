//
// Created by shuviu on 3/13/25.
//

#include "InputHandlerAsync.h"

#include <future>
#include <TerminalUtilities.h>

namespace UtilityClasses {
    InputHandlerAsync::InputHandlerAsync() {
        threadStopped_.store(false);
        keyUpdate_.store(false);
        inputKey_.store(-1);
    };
    InputHandlerAsync::~InputHandlerAsync() = default;


    void InputHandlerAsync::Start() {
            while (!threadStopped_.load()) {
                if (!keyUpdate_.load()) {
                    inputKey_.store(Console::StdReadKey());
                    keyUpdate_.store(true);
                    usleep(10);
                }
        };
    }

    void InputHandlerAsync::Stop() {
        threadStopped_.store(true);
    }

    int InputHandlerAsync::InputKey() {
        keyUpdate_.store(false);
        return inputKey_.load();
    }

    bool InputHandlerAsync::KeyUpdate() const {
        return keyUpdate_.load();
    }
}
