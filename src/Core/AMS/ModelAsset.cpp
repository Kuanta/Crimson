//
// Created by erdem on 20.08.2023.
//

#include "Core/AMS/ModelAsset.h"

Crimson::ModelAsset::ModelAsset(const std::string &guid, const std::string &name, const std::string &filepath) :
    Asset(AssetType::Mesh, guid, name, filepath){

}
