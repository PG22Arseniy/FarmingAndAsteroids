#include "Game/Public/GameObject.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/Transform.h"
#include "Game/Public/CircleComponent.h"
#include "Game/Public/PhysicsComponent.h"



GameObject::GameObject()
{
}
// Destroyiing all the Componetns linked to Our Game Object.
GameObject::~GameObject()
{
	for (Component* IterationComponent : mComponents)
	{
		IterationComponent->Destroy();
		delete IterationComponent;
	}
}

// Initializing all the Components
void GameObject::Initialize()
{
	for (Component* IterationComponent : mComponents)
	{
		IterationComponent->Initialize();
	}
	mColor.mColor[0] = 0;
	mColor.mColor[1] = 0;
	mColor.mColor[2] = 0; 
	mColor.mColor[3] = 0;

}

void GameObject::AddComponent(Component* ComponentToAdd)
{
    mComponents.push_back(ComponentToAdd);
}


template<typename T>
T* GameObject::FindComponent(ComponentTypes eType)
{
	for ( Component* ComponentIterator : mComponents)
	{
		if (ComponentIterator->GetType() == eType)
		{
			return (T*)ComponentIterator;
		}
	}
	return nullptr;
}



template Transform* GameObject::FindComponent<Transform>(ComponentTypes eType);
template CircleComponent* GameObject::FindComponent<CircleComponent>(ComponentTypes eType);
template PhysicsComponent* GameObject::FindComponent<PhysicsComponent>(ComponentTypes eType);
template BoxComponent* GameObject::FindComponent<BoxComponent>(ComponentTypes eType);
