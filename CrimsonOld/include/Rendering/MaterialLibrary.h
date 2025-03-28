//
// Created by erdem on 19.08.2023.
//

#ifndef CRIMSON_MATERIALLIBRARY_H
#define CRIMSON_MATERIALLIBRARY_H

#include <string>
#include <unordered_map>

namespace Crimson
{
    class Material;

    class MaterialLibrary {
    public:

        MaterialLibrary() = default;
        ~MaterialLibrary();

        void Initialize();

        // Add a material with a specified ID/name.
        void AddMaterial(const std::string& id, Material* material);

        // Get a material by its ID/name.
        Material* GetMaterial(const std::string& id) const;

        Material* GetDefaultMaterial() const;

        // Check if a material with the given ID/name exists.
        bool Contains(const std::string& id) const;

        // Remove a material by its ID/name.
        bool RemoveMaterial(const std::string& id);

        // Maybe you'd want to load materials from disk or some other methods in the future.
        // void LoadMaterialsFromDisk(const std::string& directoryPath);
    private:
        std::unordered_map<std::string, Material*> _materials;
        Material* defaultMaterial;
    };

}


#endif //CRIMSON_MATERIALLIBRARY_H
