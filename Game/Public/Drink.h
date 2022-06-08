#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Drink : public GameObject, public IPhysicsCollisionEvent
{

public:

	Drink();
	Drink(exVector2 position, exVector2 velocity, float drinkSize, float fillAmount); 

	virtual void Initialize()override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);
	float mFillAmount; 
private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mDrinkSize; 

};