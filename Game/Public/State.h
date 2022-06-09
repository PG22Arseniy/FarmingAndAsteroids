
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

	State(GameObject * param);

	virtual StateDefinations GetState() = 0;
	virtual void EnterState();
	virtual void ExitState() = 0;
	virtual void RunState();
	int counter = 0;

	GameObject* mObj;

	bool NewDrinkState = false; 
	bool NewPlantState = false; 

	int nKeys = 0;
	const Uint8* pState = SDL_GetKeyboardState(&nKeys); 

	Square* VendMachine; 
	std::list<Bullet*> coins;
};


class SelectState : public State//<StateDefinations::SelectDrink>
{

public:

	SelectState(GameObject * param);
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;
	int ThirstMeter;



};

class CreateDrinkState : public State//<StateDefinations::CreateDrink>
{

public: // #Hydrated

	CreateDrinkState(GameObject * param);
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

	CreatePlantState(GameObject * param);
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override; 

	float xPos = 450;    
};