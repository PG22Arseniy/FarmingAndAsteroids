#include "Game/Public/GameObjectHandle.h"
#include "Game/Public/GameObjectManager.h"
 
GameObjectManager* GameObjectManager::sInstance = nullptr;

GameObjectManager* GameObjectManager::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new GameObjectManager();
    }
    return sInstance;
}

void GameObjectManager::RegisterGameObject(Plant* ObjectToRegister)
{
    //TODO Call the Hash function with the Game Object
    int key = Hash::GenerateHash(ObjectToRegister);
    mGameObjectMap.emplace(key,ObjectToRegister);


}

void GameObjectManager::UnregisterGameObject(Plant* ObjectToUnregister)
{
    int key = Hash::GenerateHash(ObjectToUnregister);
    mGameObjectMap.erase(key);
}

Plant* GameObjectManager::Lookup(int Hash)
{
    auto iterator = mGameObjectMap.find(Hash);
    if (iterator != mGameObjectMap.end())
    {
       return iterator->second;
    }
    return nullptr;
}
 
bool GameObjectManager::Exist(Plant* ObjectToCheck) 
{
    if (Plant* FoundObject = Lookup(Hash::GenerateHash(ObjectToCheck)))
    {
        return true;
    }
    return false;
}
