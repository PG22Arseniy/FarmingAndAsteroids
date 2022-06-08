#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Plant : public GameObject, public IPhysicsCollisionEvent
{

public:

	Plant();
	Plant(exVector2 position, exVector2 velocity, float stemSize, float flowerSize, float flowerMarginUp = 30, std::string name = "default"); 

	virtual void Initialize()override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);
	float mFlowerSize; 
	float mFlowerMarginUp; 

	std::string mName;

private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mPlantSize; 

};