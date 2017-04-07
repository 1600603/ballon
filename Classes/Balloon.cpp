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


Balloon* Balloon::createSprite(Node* parent,int balloon_number, int type, Vec2 position) {
    std::string pngfile = FILE_BALLOON;
    
    int number = type;    
    if (type == TYPE_BALLOON_RANDOM) {
        number = RandomHelper::random_int(1, BALLOON_COUNT);
        pngfile = pngfile + "_" + Value(number).asString();
    }    else {
        if (type == TYPE_BALLOON_MINUS_LIFE) pngfile = pngfile + "_life";
        if (type == TYPE_BALLOON_MINUS_SCORE) pngfile = pngfile + "_score";
        if (type == TYPE_BALLOON_SKULL) pngfile = pngfile + "_die";
        if (type == TYPE_BALLOON_PLUS_LIFE) pngfile = pngfile + "_pluslife";
    }
    
    //auto sprite = Balloon::create(pngfile + "_1.png");    
    
    Balloon *sprite = new Balloon();
    sprite->balloon_number = balloon_number;
    sprite->setAnchorPoint(Vec2(0.5f,0.5f));
    sprite->setFlipX(false);
    sprite->setFlipY(false);
    //sprite->setTexture(pngfile + "_1.png");
    sprite->setSpriteFrame(pngfile + "_1.png");
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
    auto y = 0 - sprite->getBoundingBox().size.height/2;
    log("cria balao (min_x, max_x, randomx, y): %f, %f, %f, %f", min_x, max_x, x, y);
    sprite->setPosition(Vec2(x,y));    
    parent->addChild(sprite);
    sprite->scheduleUpdate();
    sprite->setTag(TAG_BALLOON);    
    sprite->file_name = pngfile;
    return sprite; 
    
}

void Balloon::onHit() {
    if (state == BALLOON_STATE_DIE || gamescene->getGameState() == GAME_STATE_GAME_OVER) return;
    
    if (this->balloon_type>=1 && this->balloon_type<=6) {
        state = BALLOON_STATE_DIE;
        AssetsHelper::playEffect(SND_POP);
        gamescene->addPoints(1);
        //this->removeFromParent();
        //     this->setTexture(file_name + "_pop.png");
        this->setSpriteFrame(file_name + "_pop.png");
        auto self = this;
        auto destroy = CallFunc::create([self] {
            self->removeFromParent();
        });

        FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
        this->runAction(fadeOut);
        this->runAction(Sequence::create(fadeOut, destroy, nullptr));
        return;
    }
    
     if (this->balloon_type == TYPE_BALLOON_MINUS_LIFE) {
        state = BALLOON_STATE_DIE;
        AssetsHelper::playEffect(SND_LIFE);
        gamescene->removeLife();        
        //this->setTexture(file_name + "_pop.png");
        this->setSpriteFrame(file_name + "_pop.png");
        auto self = this;
        auto destroy = CallFunc::create([self] {
            self->removeFromParent();
        });
        FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
        this->runAction(fadeOut);
        this->runAction(Sequence::create(fadeOut, destroy, nullptr));
        return;
    }
    
    if (this->balloon_type == TYPE_BALLOON_MINUS_SCORE) {
        state = BALLOON_STATE_DIE;
        AssetsHelper::playEffect(SND_SCORE);
        gamescene->removePoints(5);       
        //this->setTexture(file_name + "_pop.png");
        this->setSpriteFrame(file_name + "_pop.png");
        auto self = this;
        auto destroy = CallFunc::create([self] {
            self->removeFromParent();
        });
        FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
        this->runAction(fadeOut);
        this->runAction(Sequence::create(fadeOut, destroy, nullptr));
        return;
    }
    
    
    if (this->balloon_type == TYPE_BALLOON_SKULL) {
        state = BALLOON_STATE_DIE;
        AssetsHelper::playEffect(SND_POP);
        gamescene->removeAllLifes();
        //this->setTexture(file_name + "_pop.png");
        this->setSpriteFrame(file_name + "_pop.png");
        auto self = this;
        auto destroy = CallFunc::create([self] {
            self->removeFromParent();
        });
        FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
        this->runAction(fadeOut);
        this->runAction(Sequence::create(fadeOut, destroy, nullptr));
        return;
    }
    
    
    if (this->balloon_type == TYPE_BALLOON_PLUS_LIFE) {
        state = BALLOON_STATE_DIE;
        AssetsHelper::playEffect(SND_LIFESCORE);
        gamescene->addLife();
        //this->setTexture(file_name + "_pop.png");
        this->setSpriteFrame(file_name + "_pop.png");
        auto self = this;
        auto destroy = CallFunc::create([self] {
            self->removeFromParent();
        });
        FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
        this->runAction(fadeOut);
        this->runAction(Sequence::create(fadeOut, destroy, nullptr));
        return;
    }
    
    

    
    
}

void Balloon::update (float dt) {
    
    if (state == BALLOON_STATE_NORMAL) {
        auto y = this->getPositionY() + this->speed * dt;
        this->setPositionY(y);
        timer_anim -= dt;
        if (timer_anim<0) {
            timer_anim = TIMER_ANIMATION;
            currentframe = currentframe==1?2:1;
            //this->setTexture(file_name+"_"+ Value(currentframe).asString() + ".png");
            this->setSpriteFrame(file_name+"_"+ Value(currentframe).asString() + ".png");
        }
        

        if (y > GeneralHelper::size.height + this->getBoundingBox().size.height) {
            if (this->balloon_type>=1 && this->balloon_type <=6) { 
                gamescene->removeLife();
                if (gamescene->getGameState() == GAME_STATE_PLAYING) AssetsHelper::playEffect(SND_LIFE);
            }
            this->removeFromParent();            
        }
    }   
    
}


