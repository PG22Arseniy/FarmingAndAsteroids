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
#include "Game/Public/Transform.h"
// SelectDrink STATE

void State::RunState()
{
	++counter;
}


State::State(GameObject* param, std::vector<Plant*> plantList)
{
	mObj = param;
	plants = plantList; 
}

void State::EnterState()
{
	counter = 0;
}

SelectState::SelectState(GameObject* param, std::vector<Plant*> plantList):State(param, plantList)
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

CreatePlantState::CreatePlantState(GameObject* param, std::vector<Plant*> plantList): State (param, plantList)
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
	if (currentPlant >= 4) return; 
	plants[currentPlant]->Initialize(); 
	currentPlant++;   
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
	State::RunState(); 
	 
}


// CreateDrink STATE

CreateDrinkState::CreateDrinkState(GameObject* param, std::vector<Plant*> plantList): State(param, plantList)
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


WaterPlantState::WaterPlantState(GameObject* param, std::vector<Plant*> plantList) : State(param, plantList)
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

	mObj = new Bullet({ plants[currentPlant]->getPosition(), {0,0}, 5 }); 
	mObj->Initialize();
	currentPlant++; 

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


PlantGrowthState::PlantGrowthState(GameObject* param, std::vector<Plant*> plantList) : State(param, plantList)
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

	for (Plant* plant : plants) {
		if (plant->CurrentObjectHandle->IsValid() && !plant->CheckIfMaxSize())
			plant->mFlowerSize = counter / 6; 
	}


	State::RunState();

}