#pragma once
#include "State.h"


class FiniteStateMachine
{

public:

	FiniteStateMachine(StateDefinations StartingState);
	~FiniteStateMachine();
	void Stop(); 

	void RunStateMachine();

private:

	GreenState* mGreenState;
	YellowState* mYellowState;
	RedState* mRedState;

	State* mCurrentState;

	int TotalMoney = 0;


	const int GREEN_DURATION = 40; 
	const int YELLOW_DURATION = 10; 
	const int RED_DURATION = 40; 

};

