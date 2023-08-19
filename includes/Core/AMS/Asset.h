//
// Created by erdem on 18.08.2023.
//

#ifndef CRIMSON_ASSET_H
#define CRIMSON_ASSET_H

#include <string>
#include "AssetType.h"

namespace Crimson
{


    class Asset {
    public:
        Asset(AssetType type, const std::string &guid, const std::string &name, const std::string &filepath);

    public:
        std::string Guid;
        std::string Name;
        std::string Filepath;
        AssetType AssetType;
    };

}



#endif //CRIMSON_ASSET_H
