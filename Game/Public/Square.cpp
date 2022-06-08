#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Square.h"

Square::Square()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mSize = 0;
}

Square::Square(exVector2 position, exVector2 velocity, float size)
{
	mPosition = position;
	mVelocity = velocity;
	mSize = size;
}

//Overriden from the Ball class.
void Square::Initialize()
{
	//Added a Circle COmponent to our Circle;
	AddComponent(new BoxComponent(this, 150, 200)) ; 
	 
	AddComponent(new Transform(this, mPosition));

	GameObject::Initialize();
}


//Collision Event Litsner
void Square::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}