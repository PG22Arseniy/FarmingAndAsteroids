//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Public/Game.h"
#include "Game/Public/PhysicsComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h" 

#include "Game/Public/FiniteStateMachine.h"  

#include "Game/Public/CircleComponent.h"
#include "Game/Public/BoxComponent.h"
#include "Game/Public/TextComponent.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/Ball.h"
#include "Game/Public/Asteroid.h" 
#include "Game/Public/Box.h"
#include "Game/Public/Transform.h"
#include <thread> 
#include <time.h> 
#include <iostream>
#include <list>
#include <sstream>
#include <vector> 
#include <string>    
//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mUp( false )
	, mDown( false )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "Build/afternight.ttf", 30 );    

	mTextPosition.x = 50.0f;
	mTextPosition.y = 50.0f;
	GameObject owner;
	 
	StateMachine = new FiniteStateMachine(StateDefinations::Select);   
	
	bullet = new Bullet({ 500 ,500 }, { 0, 0 }, 5); 
	bullet->Initialize();
<<<<<<< HEAD

	asteroid = new Asteroid({ 500, 500 }, { 0, 0 }, 5);
	asteroid->Initialize();


=======
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
	exVector2 ballPos;
	ballPos.x = 300; 
	ballPos.y = 200;

	
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
 
void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	mUp = pState[SDL_SCANCODE_UP];
	mDown = pState[SDL_SCANCODE_DOWN];
	mLeft = pState[SDL_SCANCODE_LEFT];
	mRight = pState[SDL_SCANCODE_RIGHT];



	if (pState[SDL_SCANCODE_3]) { 
		//TODO: run statemachine on command 
	}
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{ 


	
	std::thread InputThread(&MyGame::Input,this);
	std::thread PhysicsThread(&MyGame::Physics,this, fDeltaT);
	std::thread RenderThread(&MyGame::Render,this); 
	InputThread.join(); 
	PhysicsThread.join();  
	RenderThread.join(); 
<<<<<<< HEAD
	StateMachine->RunStateMachine(mEngine);  
	


=======
	StateMachine->RunStateMachine(mEngine, fDeltaT);   
	

	
>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
}


void MyGame::Render()
{
	exColor b;

	b.mColor[0] = 200;
	b.mColor[1] = 0;
	b.mColor[2] = 0;
	b.mColor[3] = 255;


	exColor c;

	c.mColor[0] = 75;
	c.mColor[1] = 75;
	c.mColor[2] = 100;
	c.mColor[3] = 255;
	// rendering all boxes: 
	for (BoxComponent* box : BoxComponent::AllGameBoxComponents) {
		box->Render(mEngine, 1);
	}
	for (CircleComponent* circle : CircleComponent::AllCircleComponents) {
		circle->Render(mEngine, 1); 
	}
}

<<<<<<< HEAD
=======
	for (TextComponent* text : TextComponent::AllTextComponents) {
		text->Render(mEngine, 1);
	}
}

>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
void MyGame::Physics(float fDeltaT)
{
	// Updating all objects with physics component every frame
	for (PhysicsComponent* phComp : PhysicsComponent::mAllPhysicsComponents) {
		phComp->Update(fDeltaT);
<<<<<<< HEAD
=======

		 

>>>>>>> de1f366786b2e36ebfbc2f891cc4f0f8c39b1f14
	}
}

void MyGame::Input()
{
	if (mUp)
	{
	
		bullet->FindComponent<PhysicsComponent>(ComponentTypes::Physics)->mVelocity = { 0, -100 };
	}
	else if (mDown)
	{
	
		bullet->FindComponent<PhysicsComponent>(ComponentTypes::Physics)->mVelocity = { 0, 100 };
	}
	if (mLeft)
	{

		bullet->FindComponent<PhysicsComponent>(ComponentTypes::Physics)->mVelocity = { -100, 0 };
	}
	else if (mRight)
	{

		bullet->FindComponent<PhysicsComponent>(ComponentTypes::Physics)->mVelocity = { 100, 0 };
	}
}
