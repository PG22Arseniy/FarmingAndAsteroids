#include "Game/Public/StateStopWatch.h"
#include "Utils.h" 
#include "Game/Public/Ball.h"
#include "Game/Public/TrafficLight.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "Game/Public/Game.h"


// Going STATE

void StopWatchState::RunState(float  fDeltaT) 
{
	
}

void StopWatchState::EnterState()
{

}

StopWatchStateDefinations GoingState::GetState()
{
	return StopWatchStateDefinations::Going;
}


void GoingState::EnterState()
{
	StopWatchState::EnterState();
}

void GoingState::ExitState()
{

}


void GoingState::RunState(float  fDeltaT)
{
	counter += fDeltaT; 

	if (pState[SDL_SCANCODE_SPACE]) {
	 
		Paused = true;
		Going = false;
	
	}
	if (pState[SDL_SCANCODE_RETURN]) {

		counter = 0; 
;
	}
}


// Pause STATE

StopWatchStateDefinations PauseState::GetState()
{
	return StopWatchStateDefinations::Pause;
}


void PauseState::EnterState()
{

	StopWatchState::EnterState(); 
}

void PauseState::ExitState()
{

}


void PauseState::RunState(float  fDeltaT)
{
	counter = counter;   
	if (pState[SDL_SCANCODE_RETURN]) {
	
		Paused = false;
		Going = true;
		counter = 0;
	
	} 
	if (pState[SDL_SCANCODE_TAB]) {
	
		Paused = false;
		Going = true; 
	}
	StopWatchState::RunState(fDeltaT);



}


