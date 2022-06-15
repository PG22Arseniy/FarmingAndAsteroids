#include "Game/Public/PhysicsComponent.h"
#include "Game/Public/Transform.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/Particle.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/IPhysicsCollisionEvent.h" 
#include "Engine/Public/EngineInterface.h"
#include <iostream>
#include<cmath>

using namespace std;

 std::vector<PhysicsComponent*> PhysicsComponent::mAllPhysicsComponents; 


 std::vector<IPhysicsCollisionEvent*> PhysicsComponent::mCollisionEvents; 

PhysicsComponent::PhysicsComponent(GameObject* OwningGameObject, bool gravityEnabled, float gravityScale, float mass, exVector2 Velocity, bool collisionEnabled):Component(OwningGameObject)
{
	mTransform = nullptr;
	bGravityEnabled = gravityEnabled;
	mGravityScale = gravityScale;
	mMass = mass;
	mVelocity = Velocity;
	bIsCollisionEnabled = collisionEnabled;
}

void PhysicsComponent::Initialize()
{
	//TODO Initilize the Transform Component, and all the Other Components if necessary
//	mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->Initialize(); 

	mTransform = mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform); 
	
	mAllPhysicsComponents.push_back(this);
}

void PhysicsComponent::Destroy()
{
	PhysicsComponent::mAllPhysicsComponents.erase(std::remove(PhysicsComponent::mAllPhysicsComponents.begin(), PhysicsComponent::mAllPhysicsComponents.end(), this), PhysicsComponent::mAllPhysicsComponents.end());
}

ComponentTypes PhysicsComponent::GetType()
{
	return ComponentTypes::Physics;
}

bool PhysicsComponent::IsColliding(const PhysicsComponent* OtherPhysicsComponent)const 
{
	if (!bIsCollisionEnabled || !OtherPhysicsComponent->bIsCollisionEnabled) return false;  

	BoxComponent* MyBoxComp = mOwningGameObject->FindComponent<BoxComponent>(ComponentTypes::Box);
	CircleComponent* MyCircleComp = mOwningGameObject->FindComponent<CircleComponent>(ComponentTypes::Circle);
	BoxComponent* OtherBoxComp = OtherPhysicsComponent->mOwningGameObject->FindComponent<BoxComponent>(ComponentTypes::Box);
	CircleComponent* OtherCircleComp = OtherPhysicsComponent->mOwningGameObject->FindComponent<CircleComponent>(ComponentTypes::Circle);
	

	float x1 =	mTransform->mPosition.x;
	float y1 = mTransform->mPosition.y;

	float x2 = OtherPhysicsComponent->mTransform->mPosition.x; 
	float y2 = OtherPhysicsComponent->mTransform->mPosition.y;

	float distX = abs(x1 - y2);
	float distY = abs(y1 - y2);

	

	if (MyCircleComp !=  nullptr && OtherCircleComp !=  nullptr)
	{
		// circle to circle collision
		float distX = x1 - x2;
		float distY = y1 - y2;
		float distance = sqrt((distX * distX) + (distY * distY));

		// if the distance is less than the sum of the circle's
		// radii, the circles are touching!
		if (distance <= MyCircleComp->mRadius + OtherCircleComp->mRadius) { 
			return true;
		}
		return false;
	}
	if (MyBoxComp != nullptr && OtherBoxComp != nullptr)
	{
	// box to box collision
		if (x1 + MyBoxComp->mWidth >= x2 &&    
			x1 <= x2 + OtherBoxComp->mWidth &&    
			y1 + MyBoxComp->mHeight >= y2 &&    
			y1 <= y2 + OtherBoxComp->mHeight) {    
			return true;
		}
		return false;
	}
	if (MyCircleComp != nullptr && OtherBoxComp != nullptr)
	{
		// circle box collision

		float testX = x1;
		float testY = y1;

		// which edge is closest?
		if (x1 < x2)         testX = x2;      // test left edge
		else if (x1 > x2 + OtherBoxComp->mWidth) testX = x2 + OtherBoxComp->mWidth;   // right edge
		if (y1 < y2)         testY = y2;      // top edge
		else if (y1 > y2 + OtherBoxComp->mHeight) testY = y2 + OtherBoxComp->mHeight;   // bottom edge

		// get distance from closest edges
		float distX = x1 - testX;
		float distY = y1 - testY;
		float distance = sqrt((distX * distX) + (distY * distY));

		// if the distance is less than the radius, collision!
		if (distance <= MyCircleComp->mRadius) {
			return true;
		}
		return false;
	}
	if (MyBoxComp != nullptr && OtherCircleComp != nullptr)
	{
		// box circle collision

		float testX = x1;
		float testY = y1;

		// which edge is closest?
		if (x2 < x1)         testX = x1;      // test left edge
		else if (x2 > x1 + MyBoxComp->mWidth) testX = x1 + MyBoxComp->mWidth;   // right edge
		if (y2 < y1)         testY = y1;      // top edge
		else if (y2 > y1 + MyBoxComp->mHeight) testY = y1 + MyBoxComp->mHeight;   // bottom edge

		// get distance from closest edges
		float distX = x2 - testX;
		float distY = y2 - testY;
		float distance = sqrt((distX * distX) + (distY * distY));

		// if the distance is less than the radius, collision!
		if (distance <= OtherCircleComp->mRadius) {
			return true;
		}
		return false;
	}

	return false;
}

void PhysicsComponent::Update(float pDeltaTime)
{

	if (Particle* particle = dynamic_cast<Particle*>(mOwningGameObject)) {
		if (particle->mLifeTime >= 0.0f)
		{
			particle->mLifeTime -= pDeltaTime;

			if (particle->mLifeTime <= 0.0f) 
			{
				particle->RemoveComponents(); 
				particle = nullptr; 
				delete particle; 
			
				 
				return;  
			}
		}
	}

	mTransform->mPosition.x = mTransform->mPosition.x + mVelocity.x * pDeltaTime;
	mTransform->mPosition.y = mTransform->mPosition.y + mVelocity.y * pDeltaTime;


	if (bIsCollisionEnabled == true)
	{
		for (PhysicsComponent* PhysicsComponentIterator : mAllPhysicsComponents)
		{
			if (PhysicsComponentIterator == this)
			{
				continue;
			}

			//TODO - Maybe have IsColliding Produce a ExVector2 that contains the Normal of the COllision
			if (IsColliding(PhysicsComponentIterator))
			{
				// velocity reversed on collision 
				mVelocity.x *= -1; 
				mVelocity.y *= -1;

				// Adding Collision Check
				for (IPhysicsCollisionEvent* pCollisionEvent : mCollisionEvents)
				{
					pCollisionEvent->OnCollision(this, PhysicsComponentIterator);

				}
			}
			
		}
	}

}

void PhysicsComponent::AddColissionEventLitsner(IPhysicsCollisionEvent* pEvent)
{
	mCollisionEvents.push_back(pEvent);
}

//You can move the Update / Is Colliding / add CollisionEventLitsner / the Static Event Litsner Array to a singleton