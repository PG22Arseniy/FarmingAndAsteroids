#pragma once
#include "StateVending.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 

class FiniteStateVendingMachine
{

public:

	FiniteStateVendingMachine(VendingStateDefinations StartingState);
	~FiniteStateVendingMachine();


	void RunStateMachine(exEngineInterface* engine);

private:

	SelectDrinkState* mSelectDrinkState;
	InsertCoinsState* mInsertCoinsState;
	CreateDrinkState* mCreateDrinkState;

	VendingState* mCurrentState;

	int TotalMoney = 0;


	const int SelectDrink_DURATION = 100; 
	const int DRINK_PRICE = 120;   
	const int CreateDrink_DURATION = 160;   

};

