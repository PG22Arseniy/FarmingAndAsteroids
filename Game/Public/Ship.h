#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Ship : public GameObject, public IPhysicsCollisionEvent
{

public:

	Ship();
	Ship(exVector2 position, exVector2 velocity, float size);

	virtual void Initialize()override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mSize;
};