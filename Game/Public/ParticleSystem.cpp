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

ParticleSystem::ParticleSystem(GameObject* Owner, exVector2 position, int value, exColor color):Component(Owner),mPosition(position), mValue(value), mParticleColor(color)
{

}

//Overriden from the Ball class.
void ParticleSystem::Initialize()
{
	
	
}
void ParticleSystem:: Play() { 

	//mPosition = Owner->FindComponent<Transform>(ComponentTypes::Transform).
	mPosition =  this->mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->mPosition; 

	Particle* particle = new Particle({ mPosition.x , mPosition.y }, { -100,100 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { -100,0 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { -100,-100 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 0,-100 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 100,-100 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 100,0 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 100,100 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	particle = new Particle({ mPosition.x , mPosition.y }, { 0,100 }, 5);
	ParticleSystem::AllParticles.push_back(particle);

	for (Particle* particle : ParticleSystem::AllParticles)
	{
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
		delete particle;
	}
	ParticleSystem::AllParticles.clear();  
} 

//void ParticleSystem::SleepAndKill() { 
//	std::this_thread::sleep_for(std::chrono::milliseconds(3000));  
//	//Destroy();  
//}
