#include "Game/Public/Transform.h"

Transform::Transform (GameObject* OwningGameObject):Component(OwningGameObject)
{
    mPosition = exVector2{ 0, 0 };
}

Transform::Transform(GameObject* OwningGameObject, exVector2 position) : Component(OwningGameObject)
{
    mPosition = position;
}

ComponentTypes Transform::GetType() 
{ 
    return ComponentTypes::Transform;
}

