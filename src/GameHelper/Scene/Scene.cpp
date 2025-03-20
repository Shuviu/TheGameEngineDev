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
    const std::tuple<std::vector<std::string>, std::vector<Asset::Asset>> scene = SceneLoader::LoadSceneFile(pathToFile);
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
std::vector<Asset::Asset> *Scene::GetAssets() {
    return &assets_;
}

std::vector<std::string> Scene::GetSceneMatrix() const {
    return sceneMatrix_;
}

// ---- Setter ---- ////
void Scene::SetAssetsVector(const std::vector<Asset::Asset> &assets) {
    assets_ = assets;
}

void Scene::AddAsset(const Asset::Asset &asset) {

}
void Scene::RemoveAsset(const Asset::Asset &asset) {

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




