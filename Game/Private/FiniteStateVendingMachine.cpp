#include "Game/Public/FiniteStateVendingMachine.h"
#include <stdlib.h>
#include <time.h>
#include "Utils.h"

FiniteStateVendingMachine::FiniteStateVendingMachine(VendingStateDefinations StartingState)
{
	//TODO 
	mSelectDrinkState = new SelectDrinkState();
	mInsertCoinsState = new InsertCoinsState();
	mCreateDrinkState = new CreateDrinkState();

	switch (StartingState)
	{
	case VendingStateDefinations::SelectDrink:
		mCurrentState = mSelectDrinkState;
		break;
	case VendingStateDefinations::InsertCoins:
		mCurrentState = mInsertCoinsState;
		break;
	case VendingStateDefinations::CreateDrink:
		mCurrentState = mCreateDrinkState;
		break;
	default:
		mCurrentState = mSelectDrinkState;
		break;
	}
	srand(time(NULL));

	mCurrentState->EnterState(); 
}

FiniteStateVendingMachine::~FiniteStateVendingMachine()
{
	delete mInsertCoinsState;
	delete mCreateDrinkState;
	delete mSelectDrinkState;
}

void FiniteStateVendingMachine::RunStateMachine(exEngineInterface* engine)
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
	case VendingStateDefinations::SelectDrink:
		mCurrentState->RunState();
		if (SelectDrinkState* CurrentSelectDrinkState = dynamic_cast<SelectDrinkState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentSelectDrinkState->NextState) 
			{
				mCurrentState->ExitState(); 
				mCurrentState = mInsertCoinsState;
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case VendingStateDefinations::InsertCoins:
		mCurrentState->RunState();

		if (InsertCoinsState* CurrentInsertCoinsState = dynamic_cast<InsertCoinsState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentInsertCoinsState->counter >= DRINK_PRICE) 
			{
				mCurrentState->ExitState();
				mCurrentState = mCreateDrinkState;
				mCurrentState->EnterState();
				break;
			}
		}
		break;
	case VendingStateDefinations::CreateDrink:
		mCurrentState->RunState();

		if (CreateDrinkState* CurrentCreateDrinkState = dynamic_cast<CreateDrinkState*>(mCurrentState))
		{
			//Exit Condition
			if (CurrentCreateDrinkState->counter >= CreateDrink_DURATION)
			{
				mCurrentState->ExitState();
				mCurrentState = mSelectDrinkState;
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
