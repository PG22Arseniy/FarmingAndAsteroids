
#pragma once
#include "Game/Public/TrafficLight.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"  
enum class StopWatchStateDefinations
{
	Going,
	Pause,
	Marsh,
};

//template <StopWatchStateDefinations StateDefination>
class StopWatchState
{	
public:
	virtual StopWatchStateDefinations GetState() = 0;
	virtual void EnterState();
	virtual void ExitState() = 0;
	virtual void RunState(float  fDeltaT);
	float counter; 



	int nKeys = 0;
	const Uint8* pState = SDL_GetKeyboardState(&nKeys);

	bool Paused = false;  
	bool Going = true;  
	bool tap = false;
};


class GoingState : public StopWatchState//<StopWatchStateDefinations::Going>
{

public:

	GoingState() {};
	StopWatchStateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState(float  fDeltaT) override;


};



class PauseState : public StopWatchState//<StopWatchStateDefinations::Pause>
{

public: // Couldn't think about a funny idea

	PauseState() {};
	StopWatchStateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState(float  fDeltaT) override;
};