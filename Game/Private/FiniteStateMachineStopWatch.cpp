#include "Game/Public/FiniteStateMachineStopWatch.h"
#include <stdlib.h>
#include <time.h>
#include "Utils.h"
#include <iostream>
#include <list>
#include <sstream>
#include <vector> 
#include <string>  
FiniteStateMachineStopWatch::FiniteStateMachineStopWatch( StopWatchStateDefinations StartingState)
{
	//TODO 
	mGoingState = new GoingState();
	mPauseState = new PauseState();


	switch (StartingState)
	{
	case StopWatchStateDefinations::Going:
		mCurrentState = mGoingState;
		break;
	case StopWatchStateDefinations::Pause:
		mCurrentState = mPauseState;
		break;
	default:
		mCurrentState = mGoingState;
		break;
	}
	srand(time(NULL));

	exColor c;
	c.mColor[0] = 25;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;
	mCurrentState->counter = 0; 
	mCurrentState->EnterState();
}

FiniteStateMachineStopWatch::~FiniteStateMachineStopWatch()
{
	delete mPauseState;
	delete mGoingState;
}

void FiniteStateMachineStopWatch::RunStateMachine(float fDeltaT,exEngineInterface* engine)
{
	if (!mCurrentState) return;


	exColor c;
	c.mColor[0] = 25;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;

	int mFontID = engine->LoadFont("Build/afternight.ttf", 30);
	float timer = mCurrentState->counter; 
	std::string s = std::to_string(mCurrentState->counter);
	char const* pchar = s.c_str();
	engine->DrawText(mFontID, exVector2{ 300,200 }, pchar, c, 0);
 


	// ACTUAl STATE LOGIC
	
	switch (mCurrentState->GetState())
	{
	case StopWatchStateDefinations::Going:
		
		mCurrentState->RunState(fDeltaT); 
		if (GoingState* CurrentGoingState = dynamic_cast<GoingState*>(mCurrentState))
		{

	
			//Exit Condition
			if (mCurrentState->Paused)
			{
				mCurrentState->ExitState();
				mCurrentState = mPauseState;
				mCurrentState->counter = timer; 
				mCurrentState->Going = false;
				mCurrentState->Paused = true; 
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case StopWatchStateDefinations::Pause:
		mCurrentState->RunState(fDeltaT);

		if (PauseState* CurrentPauseState = dynamic_cast<PauseState*>(mCurrentState))
		{
			//Exit Condition
			if (mCurrentState->Going)      
			{
				mCurrentState->ExitState(); 
				mCurrentState = mGoingState;
				mCurrentState->counter = timer;
				mCurrentState->Paused = false;
				mCurrentState->Going = true; 
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	default: 
		mCurrentState->RunState(fDeltaT);
		break;
	}

}
