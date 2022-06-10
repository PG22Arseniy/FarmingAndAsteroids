#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Plant.h"
#include "Game/Public/GameObjectHandle.h"  
#include "Game/Public/GameObjectManager.h" 

Plant::Plant()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mPlantSize = 0;
	mFlowerSize = 0;
	mFlowerMarginUp = 30;
}

Plant::Plant(exVector2 position, exVector2 velocity, float stemSize, float flowerSize, float flowerMarginUp, std::string name) 
{
	mPosition = position;
	mVelocity = velocity;
	mPlantSize = stemSize;
	mFlowerSize = flowerSize;
	mFlowerMarginUp = flowerMarginUp; 
	mName = name;
}

//Overriden from the Ball class.
void Plant::Initialize()
{

	CurrentObjectHandle = new GameObjectHandle(Hash::GenerateHash(dynamic_cast<Plant*>(this)));

	GameObjectManager::GetInstance()->RegisterGameObject(this);
	
	AddComponent(new BoxComponent(this, mPlantSize*1, mPlantSize * 5));     
	AddComponent(new CircleComponent(this, mFlowerSize)); 
	//Added a Circle COmponent to our Circle;
	
     
	AddComponent(new Transform(this, mPosition));

	GameObject::Initialize();
}
void Plant::Destroy()
{
	GameObjectManager::GetInstance()->UnregisterGameObject(this);
	delete this; 
}
exVector2 Plant::getPosition()
{
	return mPosition; 
}
//Collision Event Litsner
void Plant::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}

bool Plant::CheckIfMaxSize()
{
	if (mFlowerSize >= 25) {
		return true;
	}
	return false; 
}
