#pragma once
#include "State.h"
#include "Coin.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "GameObject.h"
#include "Particle.h" 
#include "ParticleSystem.h"  
class CoinSpawner
{

public:

	CoinSpawner(); 

	~CoinSpawner();

	void SpawnCoin(); 

	void RunCoinSpawner(exEngineInterface* engine, float fDealtT);

private:

	static std::vector<Coin*> AllCoins;  

	Coin* coin; 

	int TotalMoney = 0;

	float cooldown = 5;  
};

