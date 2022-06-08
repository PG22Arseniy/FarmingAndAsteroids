#pragma once
#include "Component.h"
#include "Engine/Public/EngineInterface.h"
class Transform :public Component
{

public:
	Transform(GameObject* OwningGameObject );

	Transform(GameObject* OwningGameObject, exVector2 position );
	
	virtual ComponentTypes GetType()override;

	exVector2 mPosition;
};

