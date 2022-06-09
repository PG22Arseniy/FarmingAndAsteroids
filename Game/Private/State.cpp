#include "Game/Public/State.h"
#include "Utils.h" 
#include "Game/Public/Ball.h"
#include "Game/Public/Bullet.h"
#include "Game/Public/box.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "Game/Public/Game.h"
#include "Game/Public/Plant.h"
#include "Game/Public/GameObjectHandle.h"  
#include "Game/Public/GameObjectManager.h" 
// SelectDrink STATE

void State::RunState()
{
	++counter;
}


State::State(GameObject* param)
{
	mObj = param;
}

void State::EnterState()
{
	counter = 0;
}

SelectState::SelectState(GameObject* param):State(param)
{

}

StateDefinations SelectState::GetState()
{
	return StateDefinations::Select;
}


void SelectState::EnterState()
{
	State::EnterState();



}

void SelectState::ExitState()
{
	NewDrinkState = false;
	NewPlantState = false; 

}


void SelectState::RunState()
{
	State::RunState();

	if (pState[SDL_SCANCODE_SPACE]) {

		NewDrinkState = true;

	}
	if (pState[SDL_SCANCODE_RETURN]) {

		
		NewPlantState = true; 
	}
}


// InsertCoins STATE

CreatePlantState::CreatePlantState(GameObject* param): State (param)
{
}

StateDefinations CreatePlantState::GetState()
{
	return StateDefinations::CreatePlant;
}


void CreatePlantState::EnterState()
{
	State::EnterState();


	xPos = 500; 


}

void CreatePlantState::ExitState()
{
	//for (Bullet* coin : coins) {
	//	delete coin;
	//}
	// 
	//coins.clear();

	mObj = new Plant(plantPositions[currentPosition], { 0,0 }, 10, 0, 30, "Richard");
	plants.push_back(dynamic_cast<Plant*>(mObj));
	mObj->Initialize();
	GameObjectHandle* mCurrentObjectHandle = new GameObjectHandle(Hash::GenerateHash(dynamic_cast<Plant*>(mObj))); 
	currentPosition++;   
}


void CreatePlantState::RunState()
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

	for (Plant* plant : plants) {
		plant->mFlowerSize = counter/6;  
	}

	State::RunState(); 
	 
}


// CreateDrink STATE

CreateDrinkState::CreateDrinkState(GameObject* param): State(param)
{
}

StateDefinations CreateDrinkState::GetState()
{
	return StateDefinations::CreateDrink;
}


void CreateDrinkState::EnterState()
{
	State::EnterState();
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
	State::RunState();

}

// WATER PLANT


WaterPlantState::WaterPlantState(GameObject* param) : State(param)
{
}

StateDefinations WaterPlantState::GetState()
{
	return StateDefinations::WaterPlant;
}


void WaterPlantState::EnterState()
{
	State::EnterState();

	xPos = 500;

	mObj = new Bullet({ plantPositions[currentPosition].x, plantPositions[currentPosition].y + 30}, {0,0}, 5);  
	mObj->Initialize();
	currentPosition++; 

}

void WaterPlantState::ExitState() 
{
	//for (Bullet* coin : coins) {
	//	delete coin;
	//}
	// 
	//coins.clear();
	delete mObj; 
}


void WaterPlantState::RunState()
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
	State::RunState();

}


//  PlantGrowth


PlantGrowthState::PlantGrowthState(GameObject* param) : State(param)
{
}

StateDefinations PlantGrowthState::GetState()
{
	return StateDefinations::PlantGrowth;
}


void PlantGrowthState::EnterState()
{
	State::EnterState();

	xPos = 500;



}

void PlantGrowthState::ExitState()
{
	delete mObj;
}


void PlantGrowthState::RunState()
{
	exColor c;
	c.mColor[0] = 250;
	c.mColor[1] = 250;
	c.mColor[2] = 50;
	c.mColor[3] = 250;


	 

	State::RunState();

}