#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/TextComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Particle.h"

#include <string>
#include <iostream>

Particle::Particle()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mSize = 0;
	mLifeTime = 0;
}

Particle::Particle(exVector2 position, exVector2 velocity, float size, float lifetime)
{
	mPosition = position;
	mVelocity = velocity;
	mSize = size;
	mLifeTime = lifetime;
}

//Overriden from the Ball class.
void Particle::Initialize()
{
	//Added a Circle COmponent to our Circle;
	AddComponent(new CircleComponent(this, mSize, {180,90,250,250}));    
	AddComponent(new Transform(this, mPosition));
	AddComponent(new PhysicsComponent(this, false, 1, 5, mVelocity, false)); 

	GameObject::Initialize();

}

void Particle::Destroy() {
	GameObject::~GameObject(); 
}

void Particle::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}