#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/TrafficLight.h"

TrafficLight::TrafficLight()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mSize = 0;
}

TrafficLight::TrafficLight(exVector2 position, exVector2 velocity, float size, exColor color)
{
	mPosition = position;
	mVelocity = velocity;
	mSize = size;
	mColor = color;
}

//Overriden from the Ball class.
void TrafficLight::Initialize()
{
	//Added a Circle COmponent to our Circle;
	AddComponent(new CircleComponent(this, mSize));      
	AddComponent(new Transform(this, mPosition));

	GameObject::Initialize();
}


//Collision Event Litsner
void TrafficLight::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}