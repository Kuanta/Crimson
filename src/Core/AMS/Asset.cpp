//
// Created by erdem on 18.08.2023.
//

#include "Core/AMS/Asset.h"

Crimson::Asset::Asset(Crimson::AssetType assetType, const std::string &guid, const std::string &name, const std::string &filepath)
{
    Guid = guid;
    Name = name;
    AssetType = assetType;
    Filepath = filepath;
}
