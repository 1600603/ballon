/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Balloon.cpp
 * Author: guilherme
 * 
 * Created on 22 de Março de 2017, 20:16
 */

#include "Balloon.h"

Balloon::Balloon() {
}

Balloon::Balloon(const Balloon& orig) {
}

Balloon::~Balloon() {
}


Balloon* Balloon::createSprite(Node* parent, Vec2 position, int type) {
    std::string pngfile = FILE_BALLOON;
    
    int number = type;    
    if (type == TYPE_BALLOON_RANDOM) {
        number = RandomHelper::random_int(1, BALLOON_COUNT);
    }    
    pngfile = pngfile + "_" + Value(number).asString();
    //auto sprite = Balloon::create(pngfile + "_1.png");    
    
    Balloon *sprite = new Balloon();
    
    sprite->setTexture(pngfile + "_1.png");
    sprite->balloon_type = number;    
    sprite->gamescene = (GameScene*)parent;
    auto current_points = sprite->gamescene->getPoints();
    float level = (1 +(current_points * SPEED_STEP));    
    level = level>MAX_SPEED_MULTIPLIER?MAX_SPEED_MULTIPLIER:level;
    log("level: %f", level);
    sprite->speed = RandomHelper::random_real(level*MIN_SPEED_INITIAL, level*MAX_SPEED_INITIAL);    
    auto min_x = sprite->getBoundingBox().size.width/2;
    auto max_x = GeneralHelper::size.width - sprite->getBoundingBox().size.width/2; 
    auto x = RandomHelper::random_real(min_x, max_x);
    auto y = 0 - sprite->getBoundingBox().size.height;
    sprite->setPosition(Vec2(x,y));    
    parent->addChild(sprite);
    sprite->scheduleUpdate();
    sprite->setTag(TAG_BALLOON);    
    sprite->file_name = pngfile;
    return sprite; 
    
}

void Balloon::onHit() {
    if (state == BALLOON_STATE_DIE) return;
    state = BALLOON_STATE_DIE;
    AssetsHelper::playEffect(SND_POP);
    gamescene->addPoints(1);
    //this->removeFromParent();
    this->setTexture(file_name + "_pop.png");
    auto self = this;
    auto destroy = CallFunc::create([self] {
        self->removeFromParent();
    });
    
    FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
    this->runAction(fadeOut);
    this->runAction(Sequence::create(fadeOut, destroy, nullptr));
}

void Balloon::update (float dt) {
    
    if (state == BALLOON_STATE_NORMAL) {
        auto y = this->getPositionY() + this->speed * dt;
        this->setPositionY(y);

        if (y > GeneralHelper::size.height + this->getBoundingBox().size.height) {
            this->removeFromParent();
        }
    }   
    
}


