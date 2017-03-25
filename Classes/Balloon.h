/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Balloon.h
 * Author: guilherme
 *
 * Created on 22 de Março de 2017, 20:16
 */

#ifndef BALLOON_H
#define BALLOON_H

#define TYPE_BALLOON_RED 1
#define TYPE_BALLOON_YELLOW 2
#define TYPE_BALLOON_GREEN 3
#define TYPE_BALLOON_BLUE 4
#define TYPE_BALLOON_ORANGE 5
#define TYPE_BALLOON_PURPLE 6
#define TYPE_BALLOON_SKULL 51
#define TYPE_BALLOON_MINUS_SCORE 52
#define TYPE_BALLOON_MINUS_LIFE 53
#define TYPE_BALLOON_BIG 54
#define TYPE_BALLOON_RANDOM 100

#define BALLOON_COUNT 6

#define FILE_BALLOON "png/balloon"

#define MAX_SPEED_INITIAL 100.0f
#define MIN_SPEED_INITIAL 50.0f

#define TAG_BALLOON 555

#define TIMER_DIE 0.75f
#define SPEED_STEP 0.05f
#define MAX_SPEED_MULTIPLIER 5.0f

#include "cocos2d.h"
#include "AssetsHelper.h"
#include "GeneralHelper.h"
#include "GameScene.h"

enum _BalloonState {
    BALLOON_STATE_NORMAL,
    BALLOON_STATE_DIE
} typedef BalloonState;

using namespace cocos2d;

class Balloon : public cocos2d::Sprite {
public:
    Balloon();
    Balloon(const Balloon& orig);
    virtual ~Balloon();
    static Balloon* createSprite(Node* parent, Vec2 position = Vec2(0,0), int type = TYPE_BALLOON_RANDOM);     
    void onHit();    
    virtual void update (float dt);        
    int balloon_type=0;
    BalloonState state = BALLOON_STATE_NORMAL;
    float speed = MIN_SPEED_INITIAL;
    GameScene* gamescene;
    CREATE_FUNC(Balloon);    
private:
    float time_left_to_die=TIMER_DIE;
    std::string file_name;
};

#endif /* BALLOON_H */

