/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Language.h
 * Author: guilherme
 *
 * Created on 6 de Abril de 2017, 19:48
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "cocos2d.h"
using namespace cocos2d;

#define MSG_SHARE_GAMEOVER 1
#define MSG_SHARE_GAMEOVER_RECORD 2
#define MSG_BEST 3
#define MSG_START 4



class Language: public Object{
public:
    Language();
    Language(const Language& orig);
    virtual ~Language();
    static char* msg(int msgcode);
    static void initialize();
    static LanguageType getLanguage();
    
private:
    static LanguageType lang;
};

#endif /* LANGUAGE_H */
