//
// Created by shuviu on 3/15/25.
//

#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <vector>

#include "../Asset/Asset.h"

class Scene {
private:
    std::vector<Asset::Asset> assets_;
    std::vector<std::string> sceneMatrix_;
    bool isUpdated_;
public:
    Scene();
    explicit Scene(const std::string* pathToFile);
    ~Scene();
    [[nodiscard]] std::vector<std::string> GetSceneMatrix() const;
    void SetSceneMatrix(std::vector<std::string> sceneMatrix);
    std::vector<Asset::Asset>* GetAssets();
    void SetAssetsVector(const std::vector<Asset::Asset>& assets_);
    void AddAsset(const Asset::Asset& asset);
    void RemoveAsset(const Asset::Asset& asset);
    void Render();
};



#endif //SCENE_H
