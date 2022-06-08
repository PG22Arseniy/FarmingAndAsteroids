#pragma once
#include <vector>
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "Engine/Public/EngineTypes.h" 

class GameObject
{
public:
	GameObject();
	GameObject(std::string name); 
	~GameObject();

	virtual void Initialize();

	void AddComponent(Component* ComponentToAdd);

	template<typename T>
	T* FindComponent(ComponentTypes eType);

	exColor mColor;

	std::string mName;

private:

	std::vector<Component*> mComponents;
};

