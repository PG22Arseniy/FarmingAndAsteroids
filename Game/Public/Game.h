//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Game/Public/Ball.h" 
#include "Game/Public/TrafficLight.h" 
#include "Game/Public/Box.h" 
#include "Game/Public/Ship.h" 
#include "Game/Public/Bullet.h"  
#include "Game/Public/Asteroid.h" 
#include "Game/Public/FiniteStateMachine.h"  
#include "Game/Public/FiniteStateVendingMachine.h"  
#include "Game/Public/FiniteStateMachineStopWatch.h"  


//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed(); 

	virtual void				Run( float fDeltaT );

private:

	exEngineInterface*			mEngine;

	int							mFontID;
	float timer = 0; 
	bool						mUp;
	bool                        mTrafficLight = false;
	bool                        mVendingMachine = false;
	bool                        mStopWatch = false;  
	bool						mDown;
	bool						mLeft;
	bool						mRight; 

	bool Paused;
	bool Repeat;  
	bool Continue; 

	FiniteStateMachine*			TrafficLightStateMachine; 
	FiniteStateMachineStopWatch*			StopWatchStateMachine;
	FiniteStateVendingMachine*	VendingStateMachine;   
	Ball*						ball;  
	Ball*						ball2;
	Box*						box;  
	Box*						box2;
	Asteroid*					asteroid; 
	Ship*						ship; 
	Bullet*						bullet; 
	exVector2					mTextPosition; 

};
