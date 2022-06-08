#include "Game/Public/FiniteStateMachine.h"
#include <stdlib.h>
#include <time.h>
#include "Utils.h"

FiniteStateMachine::FiniteStateMachine(StateDefinations StartingState)
{
	//TODO 
	mGreenState = new GreenState();
	mYellowState = new YellowState();
	mRedState = new RedState();

	switch (StartingState)
	{
	case StateDefinations::Green:
		mCurrentState = mGreenState;
		break;
	case StateDefinations::Yellow:
		mCurrentState = mYellowState;
		break;
	case StateDefinations::Red:
		mCurrentState = mRedState;
		break;
	default:
		mCurrentState = mGreenState;
		break;
	}
	srand(time(NULL));

	exColor c;
	c.mColor[0] = 25;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;

	mCurrentState->EnterState();
}

FiniteStateMachine::~FiniteStateMachine()
{
	delete mYellowState;
	delete mRedState;
	delete mGreenState;
}

void  FiniteStateMachine::Stop() {
	mCurrentState->ExitState(); 
}

void FiniteStateMachine::RunStateMachine()
{
	if (!mCurrentState) return;

	// ACTUAl STATE LOGIC
	
	switch (mCurrentState->GetState())
	{
	case StateDefinations::Green:
		mCurrentState->RunState();
		if (GreenState* CurrentGreenState = dynamic_cast<GreenState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentGreenState->counter >= GREEN_DURATION)
			{
				mCurrentState->ExitState();
				mCurrentState = mYellowState;
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case StateDefinations::Yellow:
		mCurrentState->RunState();

		if (YellowState* CurrentYellowState = dynamic_cast<YellowState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentYellowState->counter >= YELLOW_DURATION)
			{
				mCurrentState->ExitState();
				mCurrentState = mRedState;
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case StateDefinations::Red:
		mCurrentState->RunState();

		if (RedState* CurrentRedState = dynamic_cast<RedState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentRedState->counter >= RED_DURATION)
			{
				mCurrentState->ExitState();
				mCurrentState = mGreenState;
				mCurrentState->EnterState(); 
				break;
			}
		}
		break;
	default:
		mCurrentState->RunState();
		break;
	}

}
