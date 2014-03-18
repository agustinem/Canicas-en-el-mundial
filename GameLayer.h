#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#define GOAL_WIDTH 400

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

enum {
    kPlayer1Tag,
    kPlayer2Tag
};

class GameLayer : public cocos2d::CCLayer
{
    
    GameSprite * _player1A;
	GameSprite * _player1B;
    GameSprite * _player1C;
	GameSprite * _player2A;
    GameSprite * _player2B;
	GameSprite * _player2C;
	GameSprite * _ball;
    
	CCArray * _players;
    CCLabelTTF * _player1ScoreLabel;
    CCLabelTTF * _player2ScoreLabel;
    
    CCSize _screenSize;
	
    int _player1Score;
    int _player2Score;
    
    void playerScore (int player);
    

    
public:
    ~GameLayer();
    
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
    
    //THE OVERRIDES
    virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
	virtual void ccTouchesMoved(CCSet* pTouches, CCEvent* event);
	virtual void ccTouchesEnded(CCSet* pTouches, CCEvent* event);
	
	void update (float dt);
};

#endif // __GAMELAYER_H__
