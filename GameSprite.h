//
//  GameSprite.h
//  Canicas
//
//  Created by Agustín on 17/03/14.
//
//

#ifndef __GAMESPRITE_SCENE_H__
#define __GAMESPRITE_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class GameSprite : public CCSprite {
public:
    
	CC_SYNTHESIZE(CCPoint, _nextPosition, NextPosition);
	
	CC_SYNTHESIZE(CCPoint, _vector, Vector);
    
    CC_SYNTHESIZE(CCTouch *, _touch, Touch);
	
	GameSprite(void);
	~GameSprite(void);
    
    static GameSprite* gameSpriteWithFile(const char * pszFileName);
    
	virtual void setPosition(const CCPoint& pos);
    
    float radius();
    
};

#endif /* defined(__GAMESPRITE_SCENE_H__) */
