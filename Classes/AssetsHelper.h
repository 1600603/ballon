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

#define BACKGROUND_MAX_PATTERNS 6
#define PNG_BACKGROUND_REPEAT "png/background"
#define PNG_TITLE_SCREEN_BALLOON_POP "png/title_screen_ballon_pop.png"
#define PNG_STATUS_BAR_LIFE "png/life"
#define MAX_BACKGROUNDS 4

/*
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
#define SND_CLICK "snd/click.ogg"
#else
#define SND_CLICK "snd/click.mp3"
#endif*/

#define SND_POP "snd/pop.mp3"
#define SND_BACKGROUND "snd/background.mp3"
#define SND_GAMEOVER "snd/game-over.mp3"
#define SND_LIFE "snd/life.mp3"
#define SND_LIFESCORE "snd/life-score.mp3"
#define SND_RECORD "snd/new-record.mp3"
#define SND_SCORE "snd/score.mp3"


#include "cocos2d.h"

using namespace cocos2d;

class AssetsHelper {
public:
    AssetsHelper();
    AssetsHelper(const AssetsHelper& orig);
    static Sprite* spriteFactory(const std::string &filepath);
    static void playEffect(const char* filepath);
    static void playMusic(const char* filepath);
    static void pauseMusic();
    static void resumeMusic();
    static void preload();
    virtual ~AssetsHelper();
private:

};

#endif /* ASSETSHELPER_H */

