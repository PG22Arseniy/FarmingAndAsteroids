#include "Game/Public/GameObjectHandle.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/GameObjectManager.h"
#include "Game/Public/Plant.h"

#include "string"

int Hash::GenerateHash (Plant* ObjectToGenerateHashFor)
{
    //TODO write hash function
    if (!ObjectToGenerateHashFor)
    {
        return 0;
    }
       int result = 0;
     std::string name = ObjectToGenerateHashFor->mName;    

    for (int i = 0 ; i< name.size(); i++)
    {
        result += (int)(name[i]);        
    }
    return result%25;
}

GameObjectHandle::GameObjectHandle(int Hash):mHash(Hash)
{
}

bool GameObjectHandle::IsValid()
{
    if (this == nullptr) return false; 
    return GameObjectManager::GetInstance()->Exist(Get());
}

Plant* GameObjectHandle::Get() 
{
    return GameObjectManager::GetInstance()->Lookup(mHash);
}
