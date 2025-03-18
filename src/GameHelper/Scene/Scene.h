//
// Created by shuviu on 3/15/25.
//

#ifndef SCENE_H
#define SCENE_H
#include <vector>

#include "../Asset/Asset.h"

class Scene {
private:
    std::vector<Asset::Asset> assets_;
    int height_;
    char** sceneMatrix_;
    int width_;
public:
    Scene(int height, int width);
    ~Scene();
    int GetHeight() const;
    void SetHeight(int height);
    int GetWidth() const;
    void SetWidth(int width);
    char** GetSceneMatrix() const;
    void SetSceneMatrix(char** sceneMatrix);
    std::vector<Asset::Asset>* GetAssets();
    void SetAssetsVector(const std::vector<Asset::Asset>& assets_);
    void AddAsset(const Asset::Asset& asset);
    void RemoveAsset(const Asset::Asset& asset);
    void Render();
};



#endif //SCENE_H
