#include "Game/Public/FiniteStateMachine.h"
#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/TextComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/Particle.h" 
#include "Game/Public/ParticleSystem.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Utils.h"

FiniteStateMachine::FiniteStateMachine(StateDefinations StartingState)
{



	//TODO
	exVector2 plantPositions[4] = { {150, 250}, {350,250}, { 150, 450 }, { 350, 450 } }; 

	Plant * plant1 = new Plant(plantPositions[0], { 0,0 }, 10, 0, 30, "Richard");
	Plant * plant2 = new Plant(plantPositions[1], { 0,0 }, 10, 0, 30, "Becka");
	Plant * plant3 = new Plant(plantPositions[2], { 0,0 }, 10, 0, 30, "Jane"); 
	Plant * plant4 = new Plant(plantPositions[3], { 0,0 }, 10, 0, 30, "John"); 

	std::vector<Plant*> plants = {plant1,plant2,plant3, plant4};

	
<<<<<<< HEAD

=======
	// Plant's drink on the top right side
	Drink* drink = new Drink({ 650 ,100 }, { 0, 0 }, 50, 0);
	drink->Initialize();

	coin = new Coin({ 200, 450 }, { 0,-10 }, 5, 1);    
	coin->Initialize(); 
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14

	mSelectState = new SelectState(nullptr, plants);
	mCreatePlantState = new CreatePlantState(nullptr, plants);
	mCreateDrinkState = new CreateDrinkState(nullptr, plants);
	mWaterPlantState = new WaterPlantState(nullptr, plants);
	mPlantGrowthState = new PlantGrowthState(nullptr, plants);
	mGameOverState = new GameOverState(nullptr, plants);

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
	case StateDefinations::GameOver:
		mCurrentState = mGameOverState;
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
	delete mGameOverState;
}

<<<<<<< HEAD
void FiniteStateMachine::RunStateMachine(exEngineInterface* engine)
{

=======
void FiniteStateMachine::RunStateMachine(exEngineInterface* engine, float fDealtT)
{

	if (!coin->Dead())
	coin->InputCheck(fDealtT);  
	 
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
	exColor c;
	c.mColor[0] = 25;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;
	int mFontID = engine->LoadFont("Build/afternight.ttf", 30);
	engine->DrawText(mFontID, exVector2{ 250 ,50 }, "Farming And Asteroids", c, 0);     
	 
	if (reset) engine->DrawText(mFontID, exVector2{ 250 ,350 }, "Press enter to continue", c, 0);

<<<<<<< HEAD
	Drink * drink = new Drink({ 650 ,100 }, { 0, 0 }, 50, 0);  
	drink->Initialize();

=======
	// get font
	int mFontID = engine->LoadFont("Build/afternight.ttf", 30);

	// name of the game
	engine->DrawText(mFontID, exVector2{ 250 ,50 }, "Farming And Asteroids", c, 0);     
	 

	// game over text
	if (reset) engine->DrawText(mFontID, exVector2{ 250 ,350 }, "Press enter to continue", c, 0);



>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
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
<<<<<<< HEAD
			{
=======
			{	
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
				reset = false;
				mCurrentState->ExitState(); 
				mCurrentState = mCreateDrinkState;

				mCurrentState->EnterState();
				break;
			}
			if (CurrentSelectState->NewPlantState)
			{
				reset = false;
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
<<<<<<< HEAD
=======
				
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
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
				mCurrentState = mPlantGrowthState; 
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

			if (CurrentPlantGrowthState->gameover)
			{
				mCurrentState->ExitState();
				mCurrentState = mGameOverState; 
				mCurrentState->EnterState();

				break;
			}

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
<<<<<<< HEAD
=======
				coin->FindComponent<ParticleSystem>(ComponentTypes::ParticleSystem)->Destroy(); 
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
				mCurrentState->ExitState();
				mCurrentState = mWaterPlantState; 
				mCurrentState->EnterState();  
				break;
			}
		}
		break;
	case StateDefinations::GameOver:
		mCurrentState->RunState();
		if (GameOverState* CurrentGameOverState = dynamic_cast<GameOverState*>(mCurrentState))
		{
			reset = true; 
			//Exit Condition
			if (CurrentGameOverState->NewGameState)
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
