#include "Game/Public/FiniteStateMachine.h"
#include <stdlib.h>
#include <time.h>
#include "Utils.h"

FiniteStateMachine::FiniteStateMachine(StateDefinations StartingState)
{
	//TODO 
	mSelectState = new SelectState(nullptr);
	mCreatePlantState = new CreatePlantState(nullptr);
	mCreateDrinkState = new CreateDrinkState(nullptr); 

	switch (StartingState)
	{
	case StateDefinations::Select:
		mCurrentState = mSelectState;
		break;
	case StateDefinations::CreatePlant:
		mCurrentState = mCreatePlantState;
		break;
	case StateDefinations::CreateDrink:
		mCurrentState = mCreateDrinkState;
		break;
	default:
		mCurrentState = mSelectState;
		break;
	}
	srand(time(NULL));

	mCurrentState->EnterState(); 
}

FiniteStateMachine::~FiniteStateMachine()
{
	delete mCreatePlantState;
	delete mCreateDrinkState;
	delete mSelectState;
}

void FiniteStateMachine::RunStateMachine(exEngineInterface* engine)
{

	exColor c;
	c.mColor[0] = 25;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;
	int mFontID = engine->LoadFont("Build/afternight.ttf", 30);
	engine->DrawText(mFontID, exVector2{ 250 ,50 }, "Farming And Asteroids", c, 0);     
	Drink * drink = new Drink({ 650 ,100 }, { 0, 0 }, 50, 0);  
	drink->Initialize();

	if (!mCurrentState) return;

	// ACTUAl STATE LOGIC
	
	switch (mCurrentState->GetState())
	{
	case StateDefinations::Select:
		mCurrentState->RunState();
		if (SelectState* CurrentSelectState = dynamic_cast<SelectState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentSelectState->NewDrinkState)  
			{
				mCurrentState->ExitState(); 
				mCurrentState = mCreateDrinkState;
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case StateDefinations::CreatePlant:
		mCurrentState->RunState();

		if (CreatePlantState* CurrentCreatePlantState = dynamic_cast<CreatePlantState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentCreatePlantState->counter >= CreateDrink_DURATION)
			{
				mCurrentState->ExitState();
				mCurrentState = mCreatePlantState;
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case StateDefinations::CreateDrink:
		mCurrentState->RunState();

		if (CreateDrinkState* CurrentCreateDrinkState = dynamic_cast<CreateDrinkState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentCreateDrinkState->counter >= CreateDrink_DURATION)
			{
				mCurrentState->ExitState();
				mCurrentState = mSelectState;
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
