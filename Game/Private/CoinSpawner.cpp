#include "Game/Public/CoinSpawner.h"
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
std::vector<Coin*> CoinSpawner::AllCoins;
CoinSpawner::CoinSpawner()
{


}
void CoinSpawner::SpawnCoin() {
	int randValue = rand() % 9 + 1;  
	coin = new Coin({ 200, 450 }, { 0,-20 }, 5, randValue);   
	coin->Initialize();

}

void CoinSpawner::RunCoinSpawner(exEngineInterface* engine, float fDealtT) 
{


	for (Coin* coin : AllCoins) {
		coin->InputCheck(fDealtT); 
	}
	if (cooldown >= 0.0f)
	{
		cooldown -= fDealtT;

		if (cooldown <= 0.0f)
		{
			SpawnCoin();
			cooldown = 5;
			return;
		}
	}
	
}
