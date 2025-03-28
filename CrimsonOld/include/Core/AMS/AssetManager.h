//
// Created by erdem on 18.08.2023.
//

#ifndef CRIMSON_ASSETMANAGER_H
#define CRIMSON_ASSETMANAGER_H

#include <string>
#include <map>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Core/sqlite3.h"
#include "AssetType.h"
#include "Core/Modules/EngineModule.h"


namespace Crimson
{

    class Asset;

    class AssetManager : EngineModule{

    public:
        bool Initialize();
        bool LoadAsset(const std::string& guid);
        bool LoadMultipleAssets(const std::vector<std::string>& guids);
        std::shared_ptr<Asset> GetAsset(const std::string& guid);
        bool UnloadAsset(const std::string& guid);

        std::string GenerateGuid();

    private:
        bool CreateTableIfNotExists();
        bool OpenDatabase();
        bool CloseDatabase();
        std::shared_ptr<Asset> CreateAsset(Crimson::AssetType type, const std::string &guid, const std::string &name, const std::string &path);

    private:
        std::string _databasePath = "./assetDatabase.db";
        sqlite3* _assetDB;
        std::map<std::string, std::shared_ptr<Asset>> assets; // Map of assets indexed by their unique name
    };

}

#endif //CRIMSON_ASSETMANAGER_H
