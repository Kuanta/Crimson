#include "Rendering/MeshInstance.h"
#include "Rendering/SubMesh.h"
#include "Rendering/Material.h"
#include "Core/AMS/MeshAsset.h"
#include "Core/EngineManager.h"

void Crimson::MeshInstance::Render(glm::mat4 modelMatrix) {

    for(int i=0;i<materials.size();++i)
    {
        Material* material = materials.at(i);
        material->Render();
        material->shader->setMat4("model", modelMatrix);

        for(int j=0;j<submeshes.size();++j)
        {
            if(submeshes[j]->GetMaterialIndex() != i) continue;
            submeshes[j]->Render();
        }
    }
}

void Crimson::MeshInstance::SetMeshAsset(std::shared_ptr<MeshAsset> meshAsset) {
    if(meshAsset == nullptr) return;

    EngineManager* em = EngineManager::GetInstance();

    materials.clear();
    for(int i=0; i<meshAsset->materialIds.size(); ++i)
    {
       materials.push_back(em->MaterialLibrary.GetMaterial(meshAsset->materialIds[i]));
    }
    if(materials.size() == 0)
    {
        materials.push_back(em->MaterialLibrary.GetDefaultMaterial());
    }
    for(int i=0;i < meshAsset->subMeshAssets.size();++i)
    {
        SubMesh* submesh = new SubMesh(&(meshAsset->subMeshAssets.at(i)));
        submeshes.push_back(submesh);
    }

}

Crimson::MeshInstance::MeshInstance() {

}
