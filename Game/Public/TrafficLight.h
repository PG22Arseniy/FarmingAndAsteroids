#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class TrafficLight : public GameObject, public IPhysicsCollisionEvent
{

public:

	TrafficLight();
	TrafficLight(exVector2 position, exVector2 velocity, float size, exColor color = { 100,100,20 });  

	virtual void Initialize()override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

	

private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mSize;
};