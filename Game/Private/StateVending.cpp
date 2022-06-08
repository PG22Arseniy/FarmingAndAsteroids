#include "Game/Public/StateVending.h"
#include "Utils.h" 
#include "Game/Public/Ball.h"
#include "Game/Public/Bullet.h"
#include "Game/Public/box.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "Game/Public/Game.h"
// SelectDrink STATE

void VendingState::RunState()
{
	++counter;
}

void VendingState::EnterState()
{
	counter = 0;
}

VendingStateDefinations SelectDrinkState::GetState()
{
	return VendingStateDefinations::SelectDrink;
}


void SelectDrinkState::EnterState()
{
	VendingState::EnterState();



}

void SelectDrinkState::ExitState()
{
	NextState = false; 
	delete VendMachine; 
}


void SelectDrinkState::RunState()
{
	VendingState::RunState();

	if (pState[SDL_SCANCODE_SPACE]) {

		NextState = true;

	}
	if (pState[SDL_SCANCODE_RETURN]) {

	}
}


// InsertCoins STATE

VendingStateDefinations InsertCoinsState::GetState()
{
	return VendingStateDefinations::InsertCoins;
}


void InsertCoinsState::EnterState()
{
	VendingState::EnterState();


	xPos = 500; 


}

void InsertCoinsState::ExitState()
{
	//for (Bullet* coin : coins) {
	//	delete coin;
	//}
	// 
	//coins.clear();
}


void InsertCoinsState::RunState()
{
	exColor c;
	c.mColor[0] = 250;
	c.mColor[1] = 250;
	c.mColor[2] = 50;
	c.mColor[3] = 250;
	//if (counter % 20 == 0) {
	//	Bullet* coin = new Bullet({ xPos ,350 }, { 0, 0 }, 5); 
	//
	//
	//	coin->Initialize();
	//	coin->mColor = c; 
	//	xPos = xPos + 50;
	//	coins.push_back(coin);
	//}
	VendingState::RunState(); 
	 
}


// CreateDrink STATE

VendingStateDefinations CreateDrinkState::GetState()
{
	return VendingStateDefinations::CreateDrink;
}


void CreateDrinkState::EnterState()
{
	VendingState::EnterState();
}

void CreateDrinkState::ExitState()
{
	for (Drink* drink : drinks) {
		delete drink;
	}
	drinks.clear();
}


void CreateDrinkState::RunState()

{
	drink = new Drink({ 650 ,100 }, { 0, 0 }, 50, counter/4);        
	drink->Initialize();
	drinks.push_back(drink); 
	VendingState::RunState();

}