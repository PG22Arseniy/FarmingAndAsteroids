#pragma once
#include "State.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 

class FiniteStateMachine
{

public:

	FiniteStateMachine(StateDefinations StartingState);
	~FiniteStateMachine();


	void RunStateMachine(exEngineInterface* engine);

private:

	SelectDrinkState* mSelectDrinkState;
	InsertCoinsState* mInsertCoinsState;
	CreateDrinkState* mCreateDrinkState;

	State* mCurrentState;

	int TotalMoney = 0;


	const int SelectDrink_DURATION = 100; 
	const int DRINK_PRICE = 120;   
	const int CreateDrink_DURATION = 160;   

};

