//
//  AirHockeyAppDelegate.cpp
//  AirHockey
//
//  Created by Roger Engelbert on 11/17/12.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//

#include "AppDelegate.h"
#include "SimpleAudioEngine.h"

#include "cocos2d.h"
#include "GameLayer.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
    
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    
    
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);
    
    CCSize screenSize = pEGLView->getFrameSize();
    //set design screen size to the iPad and ExactFit (image is stretched to fill screen
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(768, 1024, kResolutionExactFit);
    
    //if device's screen width is greater than 768, use high definition images
    CCFileUtils *fileUtils = CCFileUtils::sharedFileUtils();
    std::vector<std::string> searchPaths = fileUtils->getSearchPaths();
    if (screenSize.width > 768) {
        searchPaths.insert(searchPaths.begin(), "hd");
        fileUtils->setSearchPaths(searchPaths);
        pDirector->setContentScaleFactor(2);
        //or else, use standard definition
    } else {
        searchPaths.insert(searchPaths.begin(), "hd");
        fileUtils->setSearchPaths(searchPaths);
        pDirector->setContentScaleFactor(1);
    }
    
    //preload sound effects
    SimpleAudioEngine::sharedEngine()->preloadEffect(  CCFileUtils::sharedFileUtils()->fullPathForFilename("hit.wav").c_str() );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathForFilename("score.wav").c_str() );
    
    // turn on display FPS
    pDirector->setDisplayStats(false);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    CCScene *pScene = GameLayer::scene();
    
    // run
    pDirector->runWithScene(pScene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();
    
    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
