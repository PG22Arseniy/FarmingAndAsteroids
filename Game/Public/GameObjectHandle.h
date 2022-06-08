#pragma once
#include "Plant.h"
class GameObject;

class Hash
{
	//override the = operator  for it to be accepted as a Key type
public :

	static int GenerateHash(Plant* ObjectToGenerateHashFor);
};


class GameObjectHandle
{
public :

	GameObjectHandle(int Hash);

	int mHash;

	bool IsValid();

	Plant* Get(); 
	
};

