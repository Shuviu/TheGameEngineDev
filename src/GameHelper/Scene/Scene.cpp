//
// Created by shuviu on 3/15/25.
//

#include "Scene.h"

#include <iostream>
#include <ostream>
#include <TerminalUtilities.h>
#include <utility>

#include "SceneLoader.h"


// ---- Constructors ---- ////
Scene::Scene() {
    sceneMatrix_ = std::vector<std::string>();
    isUpdated_ = false;
}

Scene::Scene(const std::string* pathToFile) {
    sceneMatrix_ = SceneLoader::LoadSceneFile(pathToFile);
    isUpdated_ = false;
}

Scene::Scene(const std::string *pathToFile, std::map<std::string, std::function<Assets::Asset()>> assetMap) {
    const auto scene = SceneLoader::LoadSceneFile(pathToFile, assetMap);
    sceneMatrix_ = std::get<0>(scene);
    assets_ = std::get<1>(scene);
    isUpdated_ = false;
}


Scene::~Scene() {
    for (int i = 0; i < sceneMatrix_.size(); ++i) {
        std::free(&sceneMatrix_.at(i));
    }
    std::free(&sceneMatrix_);
}

// ---- Getter ---- ////
std::vector<Assets::Asset> *Scene::GetAssets() {
    return &assets_;
}

std::vector<std::string> Scene::GetSceneMatrix() const {
    return sceneMatrix_;
}

// ---- Setter ---- ////
void Scene::SetAssetsVector(const std::vector<Assets::Asset> &assets) {
    assets_ = assets;
}

void Scene::AddAsset(const Assets::Asset &asset) {

}
void Scene::RemoveAsset(const Assets::Asset &asset) {

}

void Scene::SetSceneMatrix(std::vector<std::string> sceneMatrix) {
    sceneMatrix_ = std::move(sceneMatrix);
}

// ---- Member functions ---- ////
void Scene::Render() {
    if (!isUpdated_) {
        isUpdated_ = true;
        Console::StdReset();
        for (int i = 0; i < sceneMatrix_.size(); ++i) {
            std::cout << sceneMatrix_.at(i) << std::endl;
        }
    }
}




