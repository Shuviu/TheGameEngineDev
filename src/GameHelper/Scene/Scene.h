//
// Created by shuviu on 3/15/25.
//

#ifndef SCENE_H
#define SCENE_H
#include <functional>
#include <map>
#include <string>
#include <vector>

#include "../Asset/Asset.h"

class Scene {
private:
    std::vector<Assets::Asset> assets_;
    std::vector<std::string> sceneMatrix_;
    bool isUpdated_;
public:
    Scene();
    explicit Scene(const std::string* pathToFile);
    Scene(const std::string* pathToFile, std::map<std::string, std::function<Assets::Asset()>> assetMap);
    ~Scene();

    [[nodiscard]] std::vector<std::string> GetSceneMatrix() const;
    void SetSceneMatrix(std::vector<std::string> sceneMatrix);
    std::vector<Assets::Asset>* GetAssets();
    void SetAssetsVector(const std::vector<Assets::Asset>& assets_);
    void AddAsset(const Assets::Asset& asset);
    void RemoveAsset(const Assets::Asset& asset);
    void Render();
};



#endif //SCENE_H
