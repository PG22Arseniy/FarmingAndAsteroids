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

	SelectState* mSelectState; 
	CreatePlantState* mCreatePlantState;
	CreateDrinkState* mCreateDrinkState;

	State* mCurrentState;

	int TotalMoney = 0;


	const int Select_DURATION = 100;   
	const int CreateDrink_DURATION = 160;   

};

