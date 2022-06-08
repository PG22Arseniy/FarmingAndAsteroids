#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"

Box::Box()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mSize = {0,0};
}

Box::Box(exVector2 position, exVector2 velocity, exVector2 size)
{
	mPosition = position;
	mVelocity = velocity;
	mSize = size;
}

//Overriden from the Ball class.
void Box::Initialize()
{
	//Added a Box COmponent to our Box; 
	AddComponent(new BoxComponent(this, mSize.x, mSize.y));  
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, mVelocity));
	AddComponent(new Transform(this, mPosition));

	GameObject::Initialize(); 
}


//Collision Event Litsner
void Box::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}