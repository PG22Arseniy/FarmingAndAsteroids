#pragma once
#include <vector>
#include "ShapeComponent.h"
#include "Component.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 
#include "iostream"
class TextComponent : public Component
{
public:
	static std::vector<TextComponent*> AllTextComponents;
	TextComponent(GameObject* Owner, std::string text, exColor color = {0,220,110,100}); 
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render(exEngineInterface* engine, int layer); 

private:
	std::string mText;
	exColor mTextColor; 
};

