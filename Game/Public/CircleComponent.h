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
	CircleComponent(GameObject* Owner, float radius, exColor color = {0,220,110,100}); 
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render(exEngineInterface* engine, int layer); 


	float mRadius;
};

