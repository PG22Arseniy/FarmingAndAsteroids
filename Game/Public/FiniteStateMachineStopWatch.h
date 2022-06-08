#pragma once
#include "StateStopWatch.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"  

class FiniteStateMachineStopWatch
{

public:

	FiniteStateMachineStopWatch (StopWatchStateDefinations StartingState);
	~FiniteStateMachineStopWatch();


	void RunStateMachine(float fDeltaT, exEngineInterface* engine);


	StopWatchState* mCurrentState; 
private:

	GoingState* mGoingState;
	PauseState* mPauseState;



	int TotalMoney = 0;

};

