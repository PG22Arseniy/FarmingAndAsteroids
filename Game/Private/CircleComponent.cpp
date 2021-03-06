#include "Game/Public/CircleComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/Plant.h"
#include "Engine/Public/SDL.h" 
#include "Game/Public/Transform.h"
#include "iostream" 
std::vector<CircleComponent*> CircleComponent::AllCircleComponents;

CircleComponent::CircleComponent(GameObject* Owner, float radius, exColor color) :ShapeComponent(Owner, color), mRadius(radius)
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
void CircleComponent::Render(exEngineInterface* engine, int layer) {

 
	exVector2 position = mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->mPosition;
	//color = mOwningGameObject->mColor; 
	float margin = 0;
	if (Plant* plant = dynamic_cast<Plant*>(mOwningGameObject))
	{
		margin = plant->mFlowerMarginUp;
		mRadius = plant->mFlowerSize; 
	} 
	
	engine->DrawCircle({ position.x, position.y - margin}, mRadius, mShapeColor, layer);   
}  

