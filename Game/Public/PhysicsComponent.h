#pragma once
#include <vector>
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "Engine/Public/EngineTypes.h" 


class Transform;
class IPhysicsCollisionEvent; 

class PhysicsComponent : public Component
{

public:

	PhysicsComponent(GameObject* OwningGameObject, bool gravityEnabled = false , float gravityScale = 1.0f, float mass = 0.0f, exVector2 Velocity = {0,0}, bool bIsCollisionEnabled = true);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	bool IsColliding(const PhysicsComponent* OtherPhysicsComponent) const;

	virtual void Update(float pDeltaTime);
	exVector2 mVelocity; 
private:

	// Store the Tranform of the Owning Game Object
	Transform* mTransform;
	bool bGravityEnabled;
	float mGravityScale;
	float mMass;
	//Replace this with ExVector2 from engine X

	bool bIsCollisionEnabled; 

	// add core functionality to Global Gravity Optional
	//static float Gravity; 

	// Add friction if you like.
	
public:

	//All Physics components
	static std::vector<PhysicsComponent*> mAllPhysicsComponents;  
	// Stores collision event handlers
	static std::vector<IPhysicsCollisionEvent*> mCollisionEvents;

	static void AddColissionEventLitsner(IPhysicsCollisionEvent* pEvent);
};

