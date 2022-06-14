#pragma once
#include <vector>
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "Engine/Public/EngineTypes.h" 

class GameObject
{
public:
	GameObject();

	~GameObject();

	virtual void Initialize();

	void AddComponent(Component* ComponentToAdd);

	template<typename T>
	T* FindComponent(ComponentTypes eType);

	void RemoveComponents(); 

	exColor mColor;

private:

	std::vector<Component*> mComponents;
};

