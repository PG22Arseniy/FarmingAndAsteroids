#include "Game/Public/ShapeComponent.h"

ShapeComponent::ShapeComponent(GameObject* Owner, exColor color):Component(Owner),mShapeColor(color)
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
