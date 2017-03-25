/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TitleScreen.h
 * Author: guilherme
 *
 * Created on 21 de Março de 2017, 23:43
 */

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "cocos2d.h"
#include "ui/UIWidget.h"
#include "ui/UIButton.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

class TitleScene: public cocos2d::LayerColor  {
public:
    TitleScene();
    TitleScene(const TitleScene& orig);
    virtual ~TitleScene();
    static cocos2d::Scene* createScene();
    virtual bool init();          
    static void setCallbacks(Node *parent);
    void drawBackground();
    void addEvents();
    Node* ballo;
    CREATE_FUNC(TitleScene);
private:
    

};

#endif /* TITLESCENE_H */

