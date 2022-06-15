#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Particle : public GameObject, public IPhysicsCollisionEvent
{

public:

	Particle();
	Particle(exVector2 position, exVector2 velocity, float size, float lifetime = 2);  
	void Destroy(); 
	virtual void Initialize()override;
	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);
	float mLifeTime; 
private:
	exVector2 mPosition;
	exVector2 mVelocity;
	float mSize;

};