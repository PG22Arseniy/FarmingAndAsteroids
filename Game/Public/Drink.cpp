#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Drink.h"

Drink::Drink()
{
	mPosition = { 0,0 };
	mVelocity = { 0,0 };
	mDrinkSize = 0;
	mFillAmount = 0;
}

Drink::Drink(exVector2 position, exVector2 velocity, float drinkSize, float fillAmount)
{
	mPosition = position;
	mVelocity = velocity;
	mDrinkSize = drinkSize;
	mFillAmount = fillAmount;
}

//Overriden from the Ball class.
void Drink::Initialize()
{

 
	AddComponent(new BoxComponent(this, mDrinkSize*1.5, mDrinkSize * 3));   
	AddComponent(new CircleComponent(this, mFillAmount)); 
	//Added a Circle COmponent to our Circle;
	
     
	AddComponent(new Transform(this, mPosition));

	GameObject::Initialize();
}


//Collision Event Litsner
void Drink::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	//Update Position
	// Play Particle
	//TODO something
}