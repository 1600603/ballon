/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LostLayer.h
 * Author: guilherme
 *
 * Created on 4 de Abril de 2017, 22:04
 */
#ifndef LOSTLAYER_H
#define LOSTLAYER_H

#include "cocos2d.h"
#include "ui/UIWidget.h"
#include "ui/UIButton.h"
#include "cocostudio/CocoStudio.h"
#include "GameScene.h"

using namespace cocos2d;

class LostLayer : public cocos2d::LayerColor
{
public:
	LostLayer();
	~LostLayer();
	static cocos2d::LayerColor* createLayer(GameScene* gs, bool isRecord=false);
	virtual bool init();
        virtual void onEnter();
	static void setCallbacks(Node* parent);        
        static GameScene* gamescene;
        bool isrecord = false;
	CREATE_FUNC(LostLayer);
private:
    
};

#endif /* LOSTLAYER_H */

