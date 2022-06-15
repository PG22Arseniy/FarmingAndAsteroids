#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Bullet.h"

Bullet::Bullet()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mSize = 0;
}

Bullet::Bullet(exVector2 position, exVector2 velocity, float size)
{
	mPosition = position;
	mVelocity = velocity;
	mSize = size;
}

//Overriden from the Ball class.
void Bullet::Initialize()
{
	//Added a Circle COmponent to our Circle;
<<<<<<< HEAD
	AddComponent(new CircleComponent(this, mSize * 5, {200,200,0,200})); 
=======
	AddComponent(new CircleComponent(this, mSize * 5, {100,100,200,200}));  
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, mVelocity));
	AddComponent(new Transform(this, mPosition));

	GameObject::Initialize();
}


//Collision Event Litsner
void Bullet::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}