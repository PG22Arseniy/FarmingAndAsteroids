#pragma once
#include "GameObject.h"
#include "GameObjectManager.h"
#include "GameObjectHandle.h"
#include "IPhysicsCollisionEvent.h"
#include <iostream> 
#include <string>  

class PhysicsComponent;
class Plant : public GameObject, public IPhysicsCollisionEvent
{

public:

	Plant();
	Plant(exVector2 position, exVector2 velocity, float stemSize, float flowerSize, float flowerMarginUp = 30, std::string name = "default", bool watered = false); 

	virtual void Initialize()override;
	void Uninitialize();
	void Destroy();  

	exVector2 getPosition(); 

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);
	float mFlowerSize; 
	float mFlowerMarginUp; 

	std::string mName;

	bool CheckIfMaxSize ();
	bool mWaterd; 

	GameObjectHandle* CurrentObjectHandle; 

private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mPlantSize; 

};