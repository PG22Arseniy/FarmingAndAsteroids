#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/TextComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Coin.h"
#include "Game/Public/ParticleSystem.h"
#include <string>
#include <iostream>

Coin::Coin()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mSize = 0;
	mValue = 0;
}

Coin::Coin(exVector2 position, exVector2 velocity, float size, int value)
{
	mPosition = position;
	mVelocity = velocity;
	mSize = size;
	mValue= value;
}

//Overriden from the Ball class.
void Coin::Initialize()
{
	//Added a Circle COmponent to our Circle;
	AddComponent(new CircleComponent(this, mSize * 5, {200,200,0,250}));   
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, mVelocity));
	AddComponent(new Transform(this, mPosition));
	AddComponent(new TextComponent(this, std::to_string(mValue), { 200,0,240,250 })); 
	AddComponent(new ParticleSystem(this,mPosition, mValue, { 200,0,240,250 }, 0.2));   

	GameObject::Initialize();

	switch (mValue)
	{
		case 1:
			keyState = SDL_SCANCODE_1;
			break;
		case 2:
			keyState = SDL_SCANCODE_2;
			break;
		case 3:
			keyState = SDL_SCANCODE_3;
			break;
		case 4:
			keyState = SDL_SCANCODE_4;
			break;
		case 5:
			keyState = SDL_SCANCODE_5;
			break;
		case 6:
			keyState = SDL_SCANCODE_6;
			break;
		case 7:
			keyState = SDL_SCANCODE_7;
			break;
		case 8:
			keyState = SDL_SCANCODE_8;
			break;
		case 9:
			keyState = SDL_SCANCODE_9; 
			break;
		default:
			break;
	}
}

void Coin::Destroy() {

	
	GameObject::~GameObject(); 
}
//Collision Event Litsner
void Coin::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}

void Coin::InputCheck(float deltaT) {

	if (pState[keyState]) { 

		FindComponent<ParticleSystem>(ComponentTypes::ParticleSystem)->Play();
	
	}

	if (FindComponent<ParticleSystem>(ComponentTypes::ParticleSystem)->On) {
		FindComponent<ParticleSystem>(ComponentTypes::ParticleSystem)->Update(deltaT); 
	}

	if (FindComponent<ParticleSystem>(ComponentTypes::ParticleSystem)->mLifeTime <= 0.0f)  
		Destroy(); 
	
}