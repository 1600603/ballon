/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AssetsHelper.cpp
 * Author: guilherme
 * 
 * Created on 21 de Março de 2017, 23:54
 */

#include "AssetsHelper.h"
#include "SimpleAudioEngine.h"



AssetsHelper::AssetsHelper() {
}

AssetsHelper::AssetsHelper(const AssetsHelper& orig) {
}

AssetsHelper::~AssetsHelper() {
}

void AssetsHelper::preload() {       
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(SND_BACKGROUND);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SND_GAMEOVER);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SND_LIFE);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SND_LIFESCORE);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SND_RECORD);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SND_SCORE);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SND_POP);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spritesheet.plist");
}

Sprite* AssetsHelper::spriteFactory(const std::string &filepath) {
    //return Sprite::create(filepath);
    return Sprite::createWithSpriteFrameName(filepath);
}

void AssetsHelper::playEffect(const char* filepath) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(filepath);
}

void AssetsHelper::playMusic(const char* filepath) {
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(filepath, true);  
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.50f);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0f);
}

void AssetsHelper::pauseMusic() {        
    CocosDenshion::SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();        
}

void AssetsHelper::resumeMusic() {       
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

