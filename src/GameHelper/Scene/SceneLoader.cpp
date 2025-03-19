//
// Created by shuviu on 3/19/25.
//

#include "SceneLoader.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "../Asset/Asset.h"

std::tuple<std::vector<std::string>, std::vector<Asset::Asset>> SceneLoader::LoadSceneFile(const std::string *pathToFile) {
    std::ifstream file (*pathToFile);
    std::string line;

    while (line != "[SCENE]") {
        std::getline(file, line);
    };

    std::tuple scene = {LoadSceneRegion(&file), std::vector<Asset::Asset>()};
    return scene;
}

std::vector<std::string>SceneLoader::LoadSceneRegion(std::ifstream* filestream) {
    std::string line;
    std::vector<std::string> lines;
    while (line != "[ENDSCENE]") {
        std::getline(*filestream, line);
        lines.push_back(line);
    }
    return lines;
}
