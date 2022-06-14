#pragma once
#include "Component.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
class ShapeComponent : public Component
{
public:
	ShapeComponent(GameObject* Owner, exColor color = {0,0,0,0}); 

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;
	
	virtual void Render(exEngineInterface* engine, int layer) = 0; 
protected:
	exColor mShapeColor;
	//TODO
};

