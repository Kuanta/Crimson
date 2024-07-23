//
// Created by erdem on 18.08.2023.
//

#include "Core/AMS/AssetManager.h"
#include "Core/AMS/Asset.h"
#include "Core/AMS/ShaderAsset.h"
#include "Core/AMS/ModelAsset.h"

bool Crimson::AssetManager::Initialize() {
    return CreateTableIfNotExists();
}

bool Crimson::AssetManager::OpenDatabase() {
    int rc = sqlite3_open(_databasePath.c_str(), &_assetDB);
    if (rc != SQLITE_OK) {
        // Handle error, maybe print or log the error message
        if (_assetDB) {
            sqlite3_close(_assetDB);
            _assetDB = nullptr;
        }
        CloseDatabase();
        return false;
    }
    fprintf(stdout, "Loaded the database\n");
    return true;

}

bool Crimson::AssetManager::CreateTableIfNotExists() {

    if(!OpenDatabase()) return false;
    //Create general table
    const char* createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS assets (
            guid TEXT PRIMARY KEY,
            name TEXT NOT NULL,
            type INTEGER NOT NULL,
            path TEXT NOT NULL,
            eagerLoad BOOLEAN DEFAULT 0
        );
    )";

    char* errorMessage = nullptr;
    int result = sqlite3_exec(_assetDB, createTableSQL, nullptr, nullptr, &errorMessage);
    if (result != SQLITE_OK) {
        // Handle error, maybe print or log the error message
        fprintf(stderr, "Couldn't create a table: %s", errorMessage);
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

bool Crimson::AssetManager::LoadAsset(const std::string &guid) {

    std::string querySQL = "SELECT guid, name, type, path FROM assets WHERE guid = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(_assetDB, querySQL.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        // Handle error
        return false;
    }

    sqlite3_bind_text(stmt, 1, guid.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string retGuid = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        std::string name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        AssetType type = static_cast<AssetType>(sqlite3_column_int(stmt, 2)); // Assuming AssetType enum values match with DB
        std::string path = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));

        std::shared_ptr<Asset> asset = CreateAsset(type, retGuid, name, path);
        assets[guid] = asset;
    }

    // Clean up
    sqlite3_finalize(stmt);
    return true;
}

bool Crimson::AssetManager::LoadMultipleAssets(const std::vector<std::string> &guids) {
    if (guids.empty()) {
        return {};
    }

    std::string placeholders = std::string(guids.size() * 2 - 1, '?').insert(1, ", ");
    std::string querySQL = "SELECT guid, name, type, path FROM assets WHERE guid IN (" + placeholders + ");";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(_assetDB, querySQL.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        // Handle error
        return {};
    }

    for (size_t i = 0; i < guids.size(); ++i) {
        sqlite3_bind_text(stmt, i + 1, guids[i].c_str(), -1, SQLITE_STATIC);
    }

    std::vector<std::shared_ptr<Crimson::Asset>> loadedAssets;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* retGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        AssetType type = static_cast<AssetType>(sqlite3_column_int(stmt, 2));
        const char* arguments = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        loadedAssets.push_back(CreateAsset(type, retGuid, name, arguments));
    }

    // Clean up
    sqlite3_finalize(stmt);
    return true;
}

bool Crimson::AssetManager::UnloadAsset(const std::string &name) {
    return false;
}

std::shared_ptr<Crimson::Asset> Crimson::AssetManager::GetAsset(const std::string &guid) {
    auto it = assets.find(guid);
    if(it == assets.end())
    {
        //Not loaded, load it
       if(!LoadAsset(guid)) return nullptr;
    }
    return assets[guid];
}

bool Crimson::AssetManager::CloseDatabase() {
    sqlite3_close(_assetDB);
    return true;
}

std::string Crimson::AssetManager::GenerateGuid() {
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    return boost::uuids::to_string(uuid);
}

std::shared_ptr<Crimson::Asset> Crimson::AssetManager::CreateAsset(Crimson::AssetType type, const std::string &guid, const std::string &name,
                                   const std::string &path) {
    switch (type) {
        case Crimson::AssetType::Shader:
            return std::make_shared<ShaderAsset>(type, guid, name, path);
        case Crimson::AssetType::Mesh:
            return std::make_shared<ModelAsset>(guid, name, path);
        default:
            return nullptr;
    }
}
