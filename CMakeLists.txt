cmake_minimum_required(VERSION 3.28)
project(GameEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(GameEngine src/main.cpp
        src/GameHelper/GameState.cpp
        src/GameHelper/GameState.h
        src/Character/Player.cpp
        src/Character/Player.h
        src/GameHelper/Render/ScreenRenderer.cpp
        src/GameHelper/Render/ScreenRenderer.h
        src/GameHelper/IO/InputHandlerAsync.cpp
        src/GameHelper/IO/InputHandlerAsync.h
        src/GameHelper/Scene/Scene.cpp
        src/GameHelper/Scene/Scene.h
        src/GameHelper/Asset/Asset.cpp
        src/GameHelper/Asset/Asset.h)

set (TERMINALUTILS_PATH /usr/local/lib/cpp/terminalUtilities)
include_directories(${TERMINALUTILS_PATH}/include)
find_library(TERMINALUTILS NAMES TerminalUtilities PATHS ${TERMINALUTILS_PATH}/src)

if (NOT TERMINALUTILS)
    MESSAGE(FATAL_ERROR "TerminalUtilities not found!")
endif ()

target_link_libraries(GameEngine PRIVATE ${TERMINALUTILS})