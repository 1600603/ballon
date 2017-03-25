/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameScene.h
 * Author: guilherme
 *
 * Created on 22 de Março de 2017, 18:45
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
#include "GeneralHelper.h"
#include "AssetsHelper.h"
#include "ui/UIWidget.h"
#include "ui/UIButton.h"
#include "ui/UIText.h"
#include "cocostudio/CocoStudio.h"



using namespace cocos2d;

#define INTERVAL_BALLOONS_MIN 1.0f
#define INTERVAL_BALLOONS_MAX 2.0f

enum _GameState {
    GAME_STATE_PAUSE,
    GAME_STATE_PLAYING    
} typedef GameState;

class GameScene: public cocos2d::LayerColor {
public:
    GameScene();    
    GameScene(const GameScene& orig);
    virtual ~GameScene();
    static cocos2d::Scene* createScene();    
    virtual bool init();    
    virtual void update(float dt);        
    void addEvents();    
    void cleanLevel();
    void resetGame();
    void drawBackground();
    void checkGameOver();    
    void checkHit(Vec2 position) ;
    void addPoints(int p);
    void updateTxtPoints();
    int getPoints();
    CREATE_FUNC(GameScene);    
    
private:
    EventListenerTouchOneByOne* listener;
    GameState gamestate = GAME_STATE_PAUSE;
    Sprite* life1;
    Sprite* life2;
    Sprite* life3;
    ui::Text*  txtPoints;
    int points=0;
    int lifes=3;
    float timer_balloons=0;
    float when_next_balloon=1.0f;
};


#endif