#pragma once
#include "GameObject.h"
#include "Component.h"

#include "Particle.h"
#include "IPhysicsCollisionEvent.h"

class ParticleSystem : public Component
{
	 
public:
	static std::vector<Particle*> AllParticles;

	ParticleSystem(GameObject* Owner, exVector2 position, int number, exColor color);
	void SleepAndKill();  
	void Play();
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;
	virtual void Initialize()override; 

private:
	exVector2 mPosition;
	exColor mParticleColor;
	int mValue; 
	
};