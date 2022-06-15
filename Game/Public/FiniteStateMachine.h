#pragma once
#include "State.h"
#include "Coin.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "GameObject.h"
#include "Particle.h" 
#include "ParticleSystem.h"  
class FiniteStateMachine
{

public:

	FiniteStateMachine(StateDefinations StartingState);
	~FiniteStateMachine();


	void RunStateMachine(exEngineInterface* engine, float fDealtT);

private:

	SelectState* mSelectState; 
	CreatePlantState* mCreatePlantState;
	WaterPlantState* mWaterPlantState; 
	CreateDrinkState* mCreateDrinkState; 
	PlantGrowthState* mPlantGrowthState;
	GameOverState* mGameOverState;

	State* mCurrentState;

	int TotalMoney = 0;

	bool reset = false;

	const int Select_DURATION = 160;   
	const int CreateDrink_DURATION = 160;   
	const int WaterDrink_DURATION = 160;    
	const int PlantGrowth_DURATION = 160;     

	Coin* coin; 
};

