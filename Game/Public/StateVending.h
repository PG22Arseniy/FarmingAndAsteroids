
#pragma once
#include "vector"
#include "Game/Public/Box.h"
#include "Game/Public/Drink.h"
#include "Game/Public/Square.h"
#include "Game/Public/Bullet.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include <algorithm>
#include <iostream>
#include <list>
enum class VendingStateDefinations
{
	SelectDrink,
	InsertCoins,
	CreateDrink,  
};

//template <VendingStateDefinations StateDefination>
class VendingState
{
public:
	virtual VendingStateDefinations GetState() = 0;
	virtual void EnterState();
	virtual void ExitState() = 0;
	virtual void RunState();
	int counter = 0;

	bool NextState = false; 

	int nKeys = 0;
	const Uint8* pState = SDL_GetKeyboardState(&nKeys); 

	Square* VendMachine; 
	std::list<Bullet*> coins;
};


class SelectDrinkState : public VendingState//<VendingStateDefinations::SelectDrink>
{

public:

	SelectDrinkState() {};
	VendingStateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;

	int ThirstMeter;

};

class CreateDrinkState : public VendingState//<VendingStateDefinations::CreateDrink>
{

public: // #Hydrated

	CreateDrinkState() {};
	VendingStateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;

	std::list<Drink*> drinks;   
	Drink* drink; 
};


class InsertCoinsState : public VendingState//<VendingStateDefinations::InsertCoins>
{

public: // Couldn't think about a funny idea

	InsertCoinsState() {};
	VendingStateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;

	float xPos = 450;    
};