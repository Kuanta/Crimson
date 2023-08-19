//
// Created by erdem on 18.08.2023.
//

#include "Rendering/ShaderAsset.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Rendering/Shader.h"

Crimson::ShaderAsset::ShaderAsset(Crimson::AssetType type, const std::string &guid, const std::string &name,
                                  const std::string &filepath) : Asset(type, guid, name, filepath) {

    //Parse the filepath
    std::vector<std::string> paths;
    std::stringstream ss(filepath);
    std::string path;

    fprintf(stdout, "Loaded asset at %s\n", filepath.c_str());

    while (std::getline(ss, path, ';')) {
        // Trim any whitespace
        path.erase(path.begin(), std::find_if(path.begin(), path.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        path.erase(std::find_if(path.rbegin(), path.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), path.end());

        paths.push_back(path);
    }

    if(paths.size() == 2)
    {
        fprintf(stdout, "Loaded new shader %s\n", name.c_str());
        shader = new Shader(paths.at(0).c_str(), paths.at(1).c_str());
    }else{
        shader == nullptr;
    }
}

