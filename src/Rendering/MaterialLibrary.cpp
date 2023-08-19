//
// Created by erdem on 19.08.2023.
//

#include "Rendering/MaterialLibrary.h"
#include "Rendering/Material.h"
#include "Core/EngineManager.h"
#include "Core/AMS/ShaderAsset.h"

namespace Crimson
{
    void MaterialLibrary::AddMaterial(const std::string& id, Material* material) {
        _materials[id] = material;
    }

    Material* MaterialLibrary::GetMaterial(const std::string& id) const {
        auto it = _materials.find(id);
        if (it != _materials.end()) {
            return it->second;
        }
        return GetDefaultMaterial();  // Return null if not found, you might want to handle this differently.
    }

    bool MaterialLibrary::Contains(const std::string& id) const {
        return _materials.find(id) != _materials.end();
    }

    bool MaterialLibrary::RemoveMaterial(const std::string& id) {
        auto it = _materials.find(id);
        if (it != _materials.end()) {
            delete it->second;  // Make sure to delete to prevent memory leaks.
            _materials.erase(it);
            return true;
        }
        return false;
    }

    MaterialLibrary::~MaterialLibrary() {
        for (auto& pair : _materials) {
            delete pair.second;
        }
        _materials.clear();
    }

    Material *MaterialLibrary::GetDefaultMaterial() const {
        return defaultMaterial;
    }

    void MaterialLibrary::Initialize() {
        defaultMaterial = new Material();
        std::shared_ptr<ShaderAsset> shaderAsset = std::static_pointer_cast<ShaderAsset>(EngineManager::GetInstance()->AssetManager.GetAsset("SimpleShader"));
        defaultMaterial->shader = shaderAsset->shader;
        defaultMaterial->AddParameter("Color",
                                     MaterialParameter(glm::vec3(0.5f, 0.5f, 0.5f)));
    }
}
