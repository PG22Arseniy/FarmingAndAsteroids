#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Box : public GameObject, public IPhysicsCollisionEvent
{

public:

	Box();
	Box(exVector2 position, exVector2 velocity, exVector2 size);

	virtual void Initialize()override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

private:
	exVector2 mPosition;
	exVector2 mVelocity;
	exVector2 mSize; 
};