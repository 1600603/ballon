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

Sprite* AssetsHelper::spriteFactory(const std::string &filepath) {
    return Sprite::create(filepath);
}

void AssetsHelper::playEffect(const char* filepath) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(filepath);
}

