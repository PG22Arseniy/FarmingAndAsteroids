 #pragma once

enum class ComponentTypes
{
	Empty,
	Transform,
	Physics,
	Box,
	Circle,
};

class GameObject;

class Component
{
public:

	Component(GameObject* Owner);
	~Component();

	virtual void Initialize();
	virtual void Destroy();
	virtual ComponentTypes GetType();




protected:

	GameObject* mOwningGameObject;
};

