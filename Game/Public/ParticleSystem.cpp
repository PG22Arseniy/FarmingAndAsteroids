#include "Game/Public/Box.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/TextComponent.h"
#include "Game/Public/PhysicsComponent.h" 
#include "Game/Public/Transform.h"
#include "Game/Public/Particle.h"
#include "Game/Public/ParticleSystem.h"
#include <chrono>
#include <time.h>
#include <string>
#include <iostream>
#include <thread>
std::vector<Particle*> ParticleSystem::AllParticles;

ParticleSystem::ParticleSystem(GameObject* Owner, exVector2 position, int value, exColor color, float lifetime):Component(Owner),mPosition(position), mValue(value), mParticleColor(color), mLifeTime(lifetime)
{

}

//Overriden from the Ball class.
void ParticleSystem::Initialize()
{
	Particle* particle = new Particle({ mPosition.x , mPosition.y }, { -100,100 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { -50,0 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { -50,-50 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 0,-50 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 50,-50 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 50,0 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 50,50 }, 5); 
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 0,50 }, 5);
	ParticleSystem::AllParticles.push_back(particle);
	
}
void ParticleSystem:: Play() { 

	//mPosition = Owner->FindComponent<Transform>(ComponentTypes::Transform).
	// mPosition =  this->mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->mPosition; 

	 
	On = true;
	for (Particle* particle : ParticleSystem::AllParticles)
	{
		particle->mPosition = this->mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->mPosition;
		particle->Initialize();
	}
	/*std::thread SleepAndKillThread(&ParticleSystem::SleepAndKill, this);
	SleepAndKillThread.join();*/

}

ComponentTypes ParticleSystem::GetType()
{
	return ComponentTypes::ParticleSystem;
}

void ParticleSystem:: Destroy() {
	for (Particle* particle: ParticleSystem::AllParticles)
	{
		particle->Destroy();
	}
	ParticleSystem::AllParticles.clear();  
	
} 
void ParticleSystem::Update(float deltaT) {

	if (!On) return;
		if (mLifeTime >= 0.0f)
		{
			mLifeTime -= deltaT;

			if (mLifeTime <= 0.0f)
			{
				Destroy();
				return;
			}
		} 
}
//void ParticleSystem::SleepAndKill() { 
//	std::this_thread::sleep_for(std::chrono::milliseconds(3000));  
//	//Destroy();  
//}
