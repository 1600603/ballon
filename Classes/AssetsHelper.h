/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AssetsHelper.h
 * Author: guilherme
 *
 * Created on 21 de Março de 2017, 23:54
 */

#ifndef ASSETSHELPER_H
#define ASSETSHELPER_H

#define BACKGROUND_MAX_PATTERNS 7
#define PNG_BACKGROUND_REPEAT "png/background"
#define PNG_TITLE_SCREEN_BALLOON_POP "png/title_screen_ballon_pop.png"
#define MAX_BACKGROUNDS 4

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
#define SND_CLICK "snd/click.ogg"
#else
#define SND_CLICK "snd/click.mp3"
#endif

#define SND_POP "snd/pop.wav"


#include "cocos2d.h"

using namespace cocos2d;

class AssetsHelper {
public:
    AssetsHelper();
    AssetsHelper(const AssetsHelper& orig);
    static Sprite* spriteFactory(const std::string &filepath);
    static void playEffect(const char* filepath);
    virtual ~AssetsHelper();
private:

};

#endif /* ASSETSHELPER_H */

