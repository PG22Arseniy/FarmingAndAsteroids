
#pragma once
#include "vector"
#include "Game/Public/Box.h"
#include "Game/Public/Plant.h"
#include "Game/Public/Drink.h"
#include "Game/Public/Square.h"
#include "Game/Public/Bullet.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include <algorithm>
#include <iostream>
#include <list>
enum class StateDefinations
{
	Select,
	CreatePlant,
	CreateDrink, 
	WaterPlant,
	AsteroidAttack,
	PlantGrowth 
};

//template <StateDefinations StateDefination>
class State
{
public:

	State(GameObject * param, std::vector<Plant*> plantList);

	virtual StateDefinations GetState() = 0;
	virtual void EnterState();
	virtual void ExitState() = 0;
	virtual void RunState();
	int counter = 0;

	std::vector<Plant*> plants; 
	 
	GameObject* mObj;
	//exVector2 plantPositions[4] = { {150, 250}, {350,250}, { 150, 450 }, { 350, 450 } }; 

	//Plant * plant1 = new Plant(plantPositions[0], { 0,0 }, 10, 0, 30, "Richard");
	//Plant * plant2 = new Plant(plantPositions[1], { 0,0 }, 10, 0, 30, "Becka");
	//Plant * plant3 = new Plant(plantPositions[2], { 0,0 }, 10, 0, 30, "Jane"); 
	//Plant * plant4 = new Plant(plantPositions[3], { 0,0 }, 10, 0, 30, "John"); 
	
  

	int currentPlant = 0;  

	bool NewDrinkState = false; 
	bool NewPlantState = false; 

	int nKeys = 0;
	const Uint8* pState = SDL_GetKeyboardState(&nKeys); 

};


class SelectState : public State//<StateDefinations::SelectDrink>
{

public:

	SelectState(GameObject * param, std::vector<Plant*> plantList);
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;


};

class CreateDrinkState : public State//<StateDefinations::CreateDrink>
{

public: // #Hydrated

	CreateDrinkState(GameObject * param, std::vector<Plant*> plantList);
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;

	std::list<Drink*> drinks;   
	Drink* drink; 
};


class CreatePlantState : public State//<StateDefinations::InsertCoins>
{

public: // Couldn't think about a funny idea

	CreatePlantState(GameObject * param, std::vector<Plant*> plantList);
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override; 

	float xPos = 450;    
};

class PlantGrowthState : public State//<StateDefinations::InsertCoins>
{

public: // Couldn't think about a funny idea

	PlantGrowthState(GameObject* param, std::vector<Plant*> plantList);
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;

	float xPos = 450; 
};


class WaterPlantState : public State//<StateDefinations::InsertCoins>
{

public: // Couldn't think about a funny idea

	WaterPlantState(GameObject* param, std::vector<Plant*> plantList);
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;

	float xPos = 450;
};