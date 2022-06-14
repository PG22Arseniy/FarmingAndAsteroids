#pragma once
#include <vector>
#include "ShapeComponent.h"
class BoxComponent : public ShapeComponent
{
public:
	static std::vector<BoxComponent*> AllGameBoxComponents;
	BoxComponent(GameObject* Owner, float width, float height, exColor color = {200,0,0,200}); 
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render(exEngineInterface* engine, int layer);

//private:

	float mWidth;
	float mHeight;
};

