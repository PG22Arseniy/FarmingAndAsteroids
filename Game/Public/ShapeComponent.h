#pragma once
#include "Component.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
class ShapeComponent : public Component
{
public:
	ShapeComponent(GameObject* Owner);

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render(exEngineInterface* engine, exColor color, int layer) = 0;

	//TODO
};

