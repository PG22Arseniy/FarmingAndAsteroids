#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"
#include "Engine/Public/EngineTypes.h" 

class PhysicsComponent;
class Ball : public GameObject, public IPhysicsCollisionEvent
{

public :

	Ball();

	Ball(exVector2 position, exVector2 velocity, float radius); 

	virtual void Initialize()override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mRaius;

};

