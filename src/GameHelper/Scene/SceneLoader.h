//
// Created by shuviu on 3/19/25.
//

#ifndef SCNELOADER_H
#define SCNELOADER_H
#include <functional>
#include <map>
#include <string>
#include <vector>

#include "../Asset/Asset.h"


class SceneLoader {
    private:
        static std::vector<std::string> LoadSceneRegion(std::ifstream* filestream);
        static std::vector<Assets::Asset> LoadAssets(std::ifstream* filestream, const std::map<std::string, std::function<Assets::Asset()>>& assetMap);
    public:
        static std::vector<std::string> LoadSceneFile(const std::string* pathToFile);
        static std::tuple<std::vector<std::string>, std::vector<Assets::Asset>> LoadSceneFile(
            const std::string* pathToFile,
            std::map<std::string, std::function<Assets::Asset()>>& assetMap);

};



#endif //SCNELOADER_H
