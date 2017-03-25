/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TitleScreen.cpp
 * Author: guilherme
 * 
 * Created on 21 de Março de 2017, 23:43
 */

#include "TitleScene.h"
#include "GeneralHelper.h"
#include "AssetsHelper.h"
//#include "ConfigScene.h"
#include "GameScene.h"

TitleScene::TitleScene() {
}

TitleScene::TitleScene(const TitleScene& orig) {
}

TitleScene::~TitleScene() {
}


cocos2d::Scene* TitleScene::createScene() {    
    auto scene = Scene::create();
    auto layer = TitleScene::create();

    auto layer_in_file = CSLoader::createNode("res/TitleScene.csb");
    layer_in_file->setAnchorPoint(Vect(0.5f, 0.5f));
    layer_in_file->setPosition(Vect(GeneralHelper::size.width/2, GeneralHelper::size.height / 2));
    auto ballon = layer_in_file->getChildByName("ballon");
    auto timeline = CSLoader::createTimeline("res/TitleScene_balloon.csb"); // load the time line
    ballon->runAction(timeline); //set the timeline action
    timeline->gotoFrameAndPlay(0, true); //Actually play it
    //coins->setPosition(layer_in_file->convertToNodeSpace(Vect(coins->getPositionX(), GeneralHelper::size.height - coins->getBoundingBox().size.height/2 - 5)));
    layer->addChild(layer_in_file, 1);        
    scene->addChild(layer);
    TitleScene::setCallbacks(layer_in_file);      
    
    layer->ballo = ballon;
    return scene;
}
bool TitleScene::init() {
    if (!LayerColor::initWithColor(Color4B(255,255,0,255))) {	
	return false;
    }
    this->drawBackground();    
    addEvents();
    return true;
}
void TitleScene::setCallbacks(Node *parent) {
    log("set callbacks");
    /*
    ui::Button *btnPlay = (ui::Button *)parent->getChildByName("btnPlay");
    btnPlay->setTouchEnabled(true);
    btnPlay->setPressedActionEnabled(true);	
    btnPlay->addTouchEventListener([](Ref* ref, ui::Widget::TouchEventType type) {
        if (type == ui::Widget::TouchEventType::BEGAN) {
                    
        }
        else if (type == ui::Widget::TouchEventType::MOVED) {

        }
        else if (type == ui::Widget::TouchEventType::ENDED) {
            AssetsHelper::playEffect(SND_CLICK);
            auto scene = GameScene::createScene();            
            Director::getInstance()->replaceScene(TransitionFade::create(1, scene, Color3B(0,0,0)));
            log("btnPlay");
        }
        else if (type == ui::Widget::TouchEventType::CANCELED) {

        }		
    });*/
    
   log("set callbacks end");
}

void TitleScene::drawBackground() {
    
       std::string pngfile = PNG_BACKGROUND_REPEAT;
	
	if (BACKGROUND_MAX_PATTERNS > 1) {
		int num = RandomHelper::random_int(1, BACKGROUND_MAX_PATTERNS);
		//if (num > 0) {
			pngfile = pngfile + "_" + Value(num).asString() + ".png";
		//}
	}
       
        log(pngfile.c_str());


	Layer *layer = Layer::create();
	Sprite *sprite = Sprite::create(pngfile);
        //Sprite *sprite = Sprite::createWithSpriteFrameName(pngfile);        
	int col = ceil(GeneralHelper::size.width / sprite->getContentSize().width);
	int lin = ceil(GeneralHelper::size.height / sprite->getContentSize().height);
	float width = sprite->getContentSize().width ;
	float height = sprite->getContentSize().height;
	layer->setContentSize(Size(width*col, height*lin));
	layer->setAnchorPoint(Vect(0.0f, 0.0f));
	//layer->setPosition(Vect(GameHelper::screen_center_x, GameHelper::screen_center_y));
	layer->setPosition(layer->convertToNodeSpace(Vect(0, 0)));
	
	
	for (int i=0;i<col;i++)
		for (int j = 0; j < lin; j++) {
			auto tile = Sprite::create(pngfile);
                        //auto tile = Sprite::createWithSpriteFrameName(pngfile);
			tile->setAnchorPoint(Vect(0, 0));
			tile->setPosition(Vect(width*i, height*j));
			layer->addChild(tile);
			
		}

	
	//layer->setPosition(Vect(GameHelper::screen_center_x, GameHelper::screen_center_y));
	this->addChild(layer);
    
}


void TitleScene::addEvents()
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    //listener->setSwallowTouches(true);
    auto self = this;
    listener->onTouchBegan = [self](cocos2d::Touch* touch, cocos2d::Event* event)
    {   
        Vec2 p = touch->getLocation();        
        log("touch begin at x: %f; y: %f", p.x, p.y);       
        
        auto nodeBox = self->ballo->getChildByName("balloon")->getBoundingBox();
        
        auto origin_world = self->ballo->convertToWorldSpace(nodeBox.origin);
        
        
        auto balloon_x = origin_world.x;
        auto balloon_y = origin_world.y;
        auto balloon_width = nodeBox.size.width;
        auto balloon_height = nodeBox.size.height;      
        
        
	auto nodeRect = Rect(balloon_x, balloon_x, balloon_width, balloon_height);
        log("ballon x: %f; y: %f", origin_world.x, origin_world.y);       
        if (nodeRect.containsPoint(p)) {
            AssetsHelper::playEffect(SND_POP);
            auto scene = GameScene::createScene();            
            Director::getInstance()->replaceScene(TransitionFade::create(1, scene, Color3B(0,0,0)));
            log("OK");
        }
        return true; // we did not consume this event, pass thru.
    };

    listener->onTouchEnded = [self](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        //MySprite::touchEvent(touch);
        
    };
    
    //dispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);   
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

}
