#include "Game/Public/TextComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/Plant.h"
#include "Engine/Public/SDL.h" 
#include "Game/Public/Transform.h"
#include "iostream" 
std::vector<TextComponent*> TextComponent::AllTextComponents;

TextComponent::TextComponent(GameObject* Owner, std::string text, exColor color) :Component(Owner) , mText(text) 
{
}

void TextComponent::Initialize()
{
	TextComponent::AllTextComponents.push_back(this);
}

void TextComponent::Destroy()
{
	TextComponent::AllTextComponents.erase(std::remove(TextComponent::AllTextComponents.begin(), TextComponent::AllTextComponents.end(), this), TextComponent::AllTextComponents.end());
}

ComponentTypes TextComponent::GetType()
{
	return ComponentTypes::Text;
}
void TextComponent::Render(exEngineInterface* engine, int layer) {
	exVector2 position = mOwningGameObject->FindComponent<Transform>(ComponentTypes::Transform)->mPosition;

	int mFontID = engine->LoadFont("Build/afternight.ttf", 28);  

	std::string s = mText;
	char const* pchar = s.c_str();

	engine->DrawText(mFontID ,{ position.x - 7, position.y- 7}, pchar, mTextColor, layer);     
}  

