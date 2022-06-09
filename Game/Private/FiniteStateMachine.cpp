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
	mWaterPlantState = new WaterPlantState(nullptr); 
	mPlantGrowthState = new PlantGrowthState(nullptr);

	switch (StartingState)
	{
	case StateDefinations::Select:
		mCurrentState = mSelectState;
		break;
	case StateDefinations::CreatePlant:
		mCurrentState = mCreatePlantState;
		break;
	case StateDefinations::WaterPlant:
		mCurrentState = mWaterPlantState;
		break;
	case StateDefinations::CreateDrink:
		mCurrentState = mCreateDrinkState;
		break;
	case StateDefinations::PlantGrowth:
		mCurrentState = mPlantGrowthState;
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
	delete mWaterPlantState;
	delete mCreateDrinkState;
	delete mPlantGrowthState;
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
			if (CurrentSelectState->NewPlantState)
			{
				mCurrentState->ExitState();
				mCurrentState = mCreatePlantState; 
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
				mCurrentState = mSelectState; 
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case StateDefinations::WaterPlant:
		mCurrentState->RunState();

		if (WaterPlantState* CurrentWaterPlantState = dynamic_cast<WaterPlantState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentWaterPlantState->counter >= WaterDrink_DURATION)
			{
				mCurrentState->ExitState();
				mCurrentState = mCreatePlantState; 
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case StateDefinations::PlantGrowth:
		mCurrentState->RunState();

		if (PlantGrowthState* CurrentPlantGrowthState = dynamic_cast<PlantGrowthState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentPlantGrowthState->counter >= PlantGrowth_DURATION) 
			{
				mCurrentState->ExitState();
				mCurrentState = mSelectState;
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
				mCurrentState = mWaterPlantState;
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
