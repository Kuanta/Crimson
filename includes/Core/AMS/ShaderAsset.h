//
// Created by erdem on 18.08.2023.
//

#ifndef CRIMSON_SHADERASSET_H
#define CRIMSON_SHADERASSET_H

#include "Core/AMS/Asset.h"
#include "Core/AMS/AssetType.h"

namespace Crimson{

    class Shader;

    class ShaderAsset : public Asset{
    public:

        ShaderAsset(Crimson::AssetType type, const std::string &guid, const std::string &name, const std::string &path);

    public:
        Shader* shader;
    };
}
#endif //CRIMSON_SHADERASSET_H
