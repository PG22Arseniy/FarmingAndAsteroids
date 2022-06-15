#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Coin : public GameObject, public IPhysicsCollisionEvent
{

public:

	Coin();
	Coin(exVector2 position, exVector2 velocity, float size, int value);

	virtual void Initialize()override;
	void Destroy();
	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mSize;
	int mValue; 
};