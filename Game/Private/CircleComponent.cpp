#include "Game/Public/CircleComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Public/GameObject.h"
#include "Engine/Public/SDL.h" 
#include "Game/Public/Transform.h"
#include "iostream" 
std::vector<CircleComponent*> CircleComponent::AllCircleComponents;

CircleComponent::CircleComponent(GameObject* Owner, float radius):ShapeComponent(Owner), mRadius(radius)
{
}

void CircleComponent::Initialize()
{
	CircleComponent::AllCircleComponents.push_back(this);
}

void CircleComponent::Destroy()
{
	CircleComponent::AllCircleComponents.erase(std::remove(CircleComponent::AllCircleComponents.begin(), CircleComponent::AllCircleComponents.end(), this), CircleComponent::AllCircleComponents.end());
}

ComponentTypes CircleComponent::GetType()
{
	return ComponentTypes::Circle;
}
void CircleComponent::Render(exEngineInterface* engine, exColor color, int layer) {
	exVector2 position = mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->mPosition;
	//color = mOwningGameObject->mColor; 

	if (!(mOwningGameObject->mColor.mColor[0] == 0 && mOwningGameObject->mColor.mColor[1] == 0 && mOwningGameObject->mColor.mColor[2] == 0 && mOwningGameObject->mColor.mColor[3] == 0))
		color = mOwningGameObject->mColor; 
	
	engine->DrawCircle( position , mRadius, color, layer);     
} 

