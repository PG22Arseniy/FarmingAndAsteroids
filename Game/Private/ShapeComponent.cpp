#include "Game/Public/ShapeComponent.h"

ShapeComponent::ShapeComponent(GameObject* Owner):Component(Owner)
{
}

void ShapeComponent::Initialize() 
{
	//TODO
}

void ShapeComponent::Destroy()
{
	//TODO
}
 

ComponentTypes ShapeComponent::GetType()
{
	return ComponentTypes::Empty;
}
