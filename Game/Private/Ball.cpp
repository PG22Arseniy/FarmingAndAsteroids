#include "Game/Public/Ball.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"

Ball::Ball()
{
	mPosition = exVector2{0,0}; 
	mVelocity = { 0,0 };
	mRaius = 0;
}

Ball::Ball(exVector2 position, exVector2 velocity, float radius)
{
	mPosition = position; 
	mVelocity = velocity;
	mRaius = radius;
}

//Overriden from the Ball class.
void Ball::Initialize()
{
	//Added a Circle COmponent to our Ball;
	AddComponent(new CircleComponent(this, mRaius));
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, mVelocity)); 
	AddComponent(new Transform(this, mPosition)); 

	GameObject::Initialize();
}


//Collision Event Litsner
void Ball::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something

	
}
