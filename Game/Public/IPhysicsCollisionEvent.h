#pragma once
#include <vector>
#include "PhysicsComponent.h"   
class PhysicsComponent ; 
class IPhysicsCollisionEvent
{
	
public:
	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent) = 0;  
};


