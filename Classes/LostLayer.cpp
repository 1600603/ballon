/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LostLayer.cpp
 * Author: guilherme
 * 
 * Created on 4 de Abril de 2017, 22:04
 */

#include "LostLayer.h"
#include "GeneralHelper.h"
//#include "StartScene.h"
#include "ui/UIText.h"
//#include "Language.h"
#include "GameScene.h"

GameScene* LostLayer::gamescene = nullptr;

LostLayer::LostLayer()
{
}

LostLayer::~LostLayer()
{
    //GameHelper::hideAd();
}

cocos2d::LayerColor* LostLayer::createLayer(GameScene* gs, bool isRecord) {
	//auto scene = Scene::create();
    LostLayer::gamescene = gs;
    auto layer = LostLayer::create();
    Node* layer_in_file;
    if (!isRecord) 
        layer_in_file = CSLoader::createNode("res/GameOverLayer.csb");
    else {
        layer_in_file = CSLoader::createNode("res/GameOverRecordLayer.csb");       
        auto timeline = CSLoader::createTimeline("res/GameOverRecordLayer.csb"); // load the time line
        layer_in_file->runAction(timeline); //set the timeline action
        timeline->gotoFrameAndPlay(0, true); //Actually play it
    }
    layer->isrecord = isRecord;
    
    
    layer_in_file->setAnchorPoint(Vect(0.5f, 0.5f));
    layer_in_file->setPosition(Vect(GeneralHelper::size.width / 2, GeneralHelper::size.height / 2));
    layer_in_file->setName("layergameover");
    layer->addChild(layer_in_file, 5);
    

    LostLayer::setCallbacks(layer_in_file);

    ui::Text* txtPoints = dynamic_cast<ui::Text *>(layer_in_file->getChildByName("txtPoints"));
    txtPoints->setText(Value(LostLayer::gamescene->getPoints()).asString());
    return layer;
}

bool LostLayer::init() {
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 25)))
	{
		return false;
	}

	return true;
}

void LostLayer::setCallbacks(Node* parent) {
	/*ui::Button *btnHome = (ui::Button *)parent->getChildByName("btnHome");
	btnHome->setTouchEnabled(true);
	btnHome->setPressedActionEnabled(true);
	btnHome->addTouchEventListener([](Ref* ref, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::BEGAN) {

		}
		else if (type == ui::Widget::TouchEventType::MOVED) {

		}
		else if (type == ui::Widget::TouchEventType::ENDED) {
			auto scene = StartScene::createScene();
			//TransitionScene *transition = TransitionFade::create(1, scene);
			//Director::getInstance()->replaceScene(transition);
			Director::getInstance()->replaceScene(TransitionSlideInL::create(0.25f, scene));

		}
		else if (type == ui::Widget::TouchEventType::CANCELED) {

		}
	});*/

	ui::Button *btnLeaderboard = (ui::Button *)parent->getChildByName("btnLeaderboard");
	btnLeaderboard->setTouchEnabled(true);
	btnLeaderboard->setPressedActionEnabled(true);
	btnLeaderboard->addTouchEventListener([](Ref* ref, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::BEGAN) {

		}
		else if (type == ui::Widget::TouchEventType::MOVED) {

		}
		else if (type == ui::Widget::TouchEventType::ENDED) {
			GeneralHelper::showLeaderboard();
		}
		else if (type == ui::Widget::TouchEventType::CANCELED) {

		}
	});
        
        
        ui::Button *btnShare= (ui::Button *)parent->getChildByName("btnShare");
	btnShare->setTouchEnabled(true);
	btnShare->setPressedActionEnabled(true);
	btnShare->addTouchEventListener([](Ref* ref, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::BEGAN) {

		}
		else if (type == ui::Widget::TouchEventType::MOVED) {

		}
		else if (type == ui::Widget::TouchEventType::ENDED) {
			GeneralHelper::share();
		}
		else if (type == ui::Widget::TouchEventType::CANCELED) {

		}
	});

	ui::Button *btnReload = (ui::Button *)parent->getChildByName("btnReload");
	btnReload->setTouchEnabled(true);
	btnReload->setPressedActionEnabled(true);
	
	btnReload->addTouchEventListener([parent](Ref* ref, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::BEGAN) {

		}
		else if (type == ui::Widget::TouchEventType::MOVED) {

		}
		else if (type == ui::Widget::TouchEventType::ENDED) {
			//GameHelper::showLeaderboard();
			//auto gamescene = (GameScene *) GameHelper::getGameScene();
			LostLayer::gamescene->resetGame();
			
			
			
		}
		else if (type == ui::Widget::TouchEventType::CANCELED) {

		}
	});

}





void LostLayer::onEnter() {
    LayerColor::onEnter();
    
    //GameHelper::playEffect(SND_LEVEL_LOST);
   // std::string name_layer = "GameOverLayer";
    //if (isrecord) name_layer ="GameOverRecordLayer";
    //auto winlayer = this->getChildByName(name_layer);
    auto winlayer = this->getChildByName("layergameover");
    auto position = winlayer->getPosition();
    winlayer->setPosition(Vect(position.x, 0 - winlayer->getBoundingBox().size.height/2));    
    auto move = MoveTo::create(0.5f, Vect(position.x, position.y)) ;
    auto easing = EaseBackOut::create(move);
    winlayer->runAction(easing);
    //GameHelper::showAd();
    
}
