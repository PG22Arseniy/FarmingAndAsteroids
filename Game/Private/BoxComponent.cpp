#include "Game/Public/BoxComponent.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/Transform.h"
std::vector<BoxComponent*> BoxComponent::AllGameBoxComponents;

BoxComponent::BoxComponent(GameObject* Owner, float width, float height):ShapeComponent(Owner),mWidth(width)
,mHeight(height)
{
}

void BoxComponent::Initialize()
{
	BoxComponent::AllGameBoxComponents.push_back(this);
}

void BoxComponent::Destroy()
{
	BoxComponent::AllGameBoxComponents.erase(std::remove(BoxComponent::AllGameBoxComponents.begin(), BoxComponent::AllGameBoxComponents.end(), this), BoxComponent::AllGameBoxComponents.end());
}

ComponentTypes BoxComponent::GetType()
{
	return ComponentTypes::Box;
}

void BoxComponent::Render(exEngineInterface* engine, exColor color, int layer) 
{
	exVector2 position = mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->mPosition; 
 
	if (!(mOwningGameObject->mColor.mColor[0] == 0 && mOwningGameObject->mColor.mColor[1] == 0 && mOwningGameObject->mColor.mColor[2] == 0 && mOwningGameObject->mColor.mColor[3] == 0))
		color = mOwningGameObject->mColor;

	engine->DrawBox({position.x - mWidth/2, position.y - mHeight/2}, { position.x + mWidth / 2, position.y + mHeight / 2 }, color, layer);
}
