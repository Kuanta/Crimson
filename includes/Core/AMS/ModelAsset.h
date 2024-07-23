//
// Created by erdem on 20.08.2023.
//

#ifndef CRIMSON_MODELASSET_H
#define CRIMSON_MODELASSET_H

#include "Core/AMS/Asset.h"
#include "Core/Transform.h"

namespace Crimson
{
    class MeshAsset;
    class ModelNode
    {
    public:
        std::string name;
        Transform transform;
        MeshAsset* MeshAsset;
        std::vector<ModelNode*> children;
    };

    class ModelAsset : public Asset{

    public:
        ModelAsset(const std::string &guid, const std::string &name, const std::string &filepath);
    public:
        ModelNode* root;

    };

}


#endif //CRIMSON_MODELASSET_H
