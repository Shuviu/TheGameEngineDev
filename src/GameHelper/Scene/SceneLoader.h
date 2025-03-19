//
// Created by shuviu on 3/19/25.
//

#ifndef SCNELOADER_H
#define SCNELOADER_H
#include <string>
#include <vector>

#include "../Asset/Asset.h"


class SceneLoader {
private:
    static std::vector<std::string> LoadSceneRegion(std::ifstream* filestream);
        public:
                static std::tuple<std::vector<std::string>, std::vector<Asset::Asset>> LoadSceneFile(const std::string* pathToFile);

};



#endif //SCNELOADER_H
