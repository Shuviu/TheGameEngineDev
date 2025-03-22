//
// Created by shuviu on 3/18/25.
//

#ifndef ASSET_H
#define ASSET_H

namespace Assets{

class Asset {
    protected:
        int xPos_;
    int yPos_;
    public:
        Asset() = default;
        Asset(const int x, const int y){xPos_ = x;yPos_ = y;};
        virtual ~Asset() = default;
};

} // Asset

#endif //ASSET_H
