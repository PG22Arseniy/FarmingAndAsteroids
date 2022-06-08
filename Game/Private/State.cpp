#include "Game/Public/State.h"
#include "Utils.h" 
#include "Game/Public/Ball.h"
#include "Game/Public/TrafficLight.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "Game/Public/Game.h"
// Green STATE

void State::RunState()
{
	++counter;
}

void State::EnterState()
{
	counter = 0;
}

StateDefinations GreenState::GetState()
{
	return StateDefinations::Green;
}


void GreenState::EnterState()
{
	State::EnterState();
	exColor c;
	c.mColor[0] = 25;
	c.mColor[1] = 255;
	c.mColor[2] = 0;
	c.mColor[3] = 255;

	trafficLight = new TrafficLight({ 100,100 }, { 0, 0 }, 40, c); 
	trafficLight->Initialize(); 
	trafficLight->mColor = c; 

}

void GreenState::ExitState()
{
	delete trafficLight; 
}


void GreenState::RunState()
{
	State::RunState();


}


// Yellow STATE

StateDefinations YellowState::GetState()
{
	return StateDefinations::Yellow;
}


void YellowState::EnterState()
{
	State::EnterState();
	exColor c;
	c.mColor[0] = 250;
	c.mColor[1] = 250; 
	c.mColor[2] = 50;  
	c.mColor[3] = 250; 

	trafficLight = new TrafficLight({ 100,300 }, { 0, 0 }, 40, c);
	trafficLight->Initialize();
	trafficLight->mColor = c;

}

void YellowState::ExitState()
{
	delete trafficLight; 
}


void YellowState::RunState()
{
	State::RunState();


}


// Red STATE

StateDefinations RedState::GetState()
{
	return StateDefinations::Red;
}


void RedState::EnterState()
{
	State::EnterState();

	exColor c;
	c.mColor[0] = 150;
	c.mColor[1] = 50;   
	c.mColor[2] = 50;
	c.mColor[3] = 250; 
	trafficLight = new TrafficLight({ 100,500 }, { 0, 0 }, 40, c);  
	trafficLight->Initialize();
	trafficLight->mColor = c;

}

void RedState::ExitState()
{
	delete trafficLight;
}


void RedState::RunState()
{
	State::RunState();

}

