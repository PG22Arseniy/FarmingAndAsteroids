#pragma once
#include <vector>
#include "ShapeComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "iostream"
class CircleComponent : public ShapeComponent
{
public:
	static std::vector<CircleComponent*> AllCircleComponents;
	CircleComponent(GameObject* Owner, float radius); 
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render(exEngineInterface* engine, exColor color, int layer);


	float mRadius;
};

