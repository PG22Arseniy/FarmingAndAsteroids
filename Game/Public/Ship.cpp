#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Ship.h"

Ship::Ship()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mSize = 0;
}

Ship::Ship(exVector2 position, exVector2 velocity, float size)
{
	mPosition = position;
	mVelocity = velocity;
	mSize = size;
}

//Overriden from the Ball class.
void Ship::Initialize()
{
	//Added a Circle and box COmponent to our Ship;
	AddComponent(new BoxComponent(this, mSize * 40, mSize * 10)); 
	AddComponent(new CircleComponent(this, mSize * 10));    
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, mVelocity));
	AddComponent(new Transform(this, mPosition));

	GameObject::Initialize();
}
 

//Collision Event Litsner
void Ship::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}