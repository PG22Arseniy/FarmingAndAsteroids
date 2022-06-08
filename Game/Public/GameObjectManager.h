#pragma once
#include <map>
#include "Plant.h" 

class Plant;
class GameObjectHandle;

class GameObjectManager
{
public:

	static GameObjectManager* GetInstance();

	void RegisterGameObject(Plant* ObjectToRegister); 

	void UnregisterGameObject(Plant* ObjectToUnregister);

	Plant* Lookup(int Hash);

	bool Exist(Plant* ObjectToCheck);

private :
	//replace this with your own Hash map
	//std::map<Hash,GameObject* > mMap;
	std::map<int, Plant*> mGameObjectMap;
	static GameObjectManager* sInstance;  
};





