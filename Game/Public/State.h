
#pragma once
#include "Game/Public/TrafficLight.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
enum class StateDefinations
{
	Green,
	Yellow,
	Red,
};

//template <StateDefinations StateDefination>
class State
{	
public:
	virtual StateDefinations GetState() = 0;
	virtual void EnterState();
	virtual void ExitState() = 0;
	virtual void RunState();
	int counter = 0;
	TrafficLight* trafficLight; 

};


class GreenState : public State//<StateDefinations::Green>
{

public:

	GreenState() {};
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;

	int ThirstMeter;

};

class RedState : public State//<StateDefinations::Red>
{

public: // #Hydrated

	RedState() {};
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;
};


class YellowState : public State//<StateDefinations::Yellow>
{

public: // Couldn't think about a funny idea

	YellowState() {};
	StateDefinations GetState() override;
	void EnterState() override;
	void ExitState() override;
	void RunState() override;
};