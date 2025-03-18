//
// Created by shuviu on 3/15/25.
//

#include "Scene.h"


// ---- Constructors ---- ////
Scene::Scene(const int height, const int width) {
    height_ = height;
    width_ = width;

    sceneMatrix_ = new char*[height];

    for (int i = 0; i < ( sizeof(sceneMatrix_) / sizeof(sceneMatrix_[0])); ++i) {
        sceneMatrix_[i] = new char[width];
    }

}

Scene::~Scene() {
    for (int i = 0; i < ( sizeof(sceneMatrix_) / sizeof(sceneMatrix_[0])); ++i) {
        delete[] sceneMatrix_[i];
    }
    delete[] sceneMatrix_;
}
// ---- Getter ---- ////
int Scene::GetHeight() const {
        return height_;
}

int Scene::GetWidth() const {
    return width_;
}

std::vector<Asset::Asset> *Scene::GetAssets() {
    return &assets_;
}

char **Scene::GetSceneMatrix() const {
    return sceneMatrix_;
}

// ---- Setter ---- ////
void Scene::SetHeight(int height) {
    height_ = height;
}
void Scene::SetWidth(int width) {
    width_ = width;
}
void Scene::SetAssetsVector(const std::vector<Asset::Asset> &assets) {
    assets_ = assets;
}

void Scene::AddAsset(const Asset::Asset &asset) {

}
void Scene::RemoveAsset(const Asset::Asset &asset) {

}
void Scene::SetSceneMatrix(char **sceneMatrix) {
    sceneMatrix_ = sceneMatrix;
}

// ---- Member functions ---- ////

void Scene::Render() {

}




