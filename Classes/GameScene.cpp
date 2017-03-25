/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameScene.cpp
 * Author: guilherme
 * 
 * Created on 22 de Março de 2017, 18:45
 */

#include "GameScene.h"
#include "GeneralHelper.h"
#include "AssetsHelper.h"
#include "Balloon.h"

GameScene::GameScene() {
}

GameScene::GameScene(const GameScene& orig) {
}

GameScene::~GameScene() {
}


Scene* GameScene::createScene()
{
    
    auto scene = Scene::create();
    
    auto layer = GameScene::create();    
    
    scene->addChild(layer);
	 
    
    return scene;
}



bool GameScene::init()
{
    //if (!LayerColor::initWithColor(ccc4(255, 255, 255, 255))) 
    
    if (!LayerColor::initWithColor(Color4B(255,255,255,255))) {
        return false;
    }   
      
    this->addEvents();    
    
    this->resetGame();    
    return true;
}

void GameScene::update(float dt) {    
    if (!this->gamestate == GAME_STATE_PLAYING) return;
    this->checkGameOver();
    timer_balloons += dt;
    if (timer_balloons > when_next_balloon) {
        //addballon;
        timer_balloons=0.0f;
        when_next_balloon = RandomHelper::random_real(INTERVAL_BALLOONS_MIN, INTERVAL_BALLOONS_MAX);
        auto balao = Balloon::createSprite(this); 
    }
    
}


void GameScene::addEvents()
{
    listener = cocos2d::EventListenerTouchOneByOne::create();
    //listener->setSwallowTouches(true);
    auto self = this;
    listener->onTouchBegan = [self](cocos2d::Touch* touch, cocos2d::Event* event)
    {   
        Vect p = touch->getLocation();        
        //log("touch begin at x: %f; y: %f", p.x, p.y);       
        
        /*
        log ("touch x,y: %f, %f", p.x, p.y);
        auto nodeBox = self->getBoundingBox();
        
        auto origin_world = nodeBox.origin;                
        auto balloon_x = origin_world.x;
        auto balloon_y = origin_world.y;
        auto balloon_width = nodeBox.size.width;
        auto balloon_height = nodeBox.size.height;     
        
        
	auto nodeRect = Rect(balloon_x, balloon_x, balloon_width, balloon_height);
        self
        if (nodeRect.containsPoint(p)) {
            self->onHit();
        }*/
        
        self->checkHit(p);
        
        return true; // we did not consume this event, pass thru.
    };

    listener->onTouchEnded = [self](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        //MySprite::touchEvent(touch);
        
    };
    
    //dispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);   
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto _keyboardListener = EventListenerKeyboard::create();
	_keyboardListener->onKeyPressed = [self](EventKeyboard::KeyCode keyCode, Event* event) {
		//if (self->didstarttouch) return;
		if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
			
		}
        if (keyCode == EventKeyboard::KeyCode::KEY_END) {
            
        }
        if (keyCode == EventKeyboard::KeyCode::KEY_HOME) {
            
        }
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_keyboardListener, this);
}


void GameScene::checkGameOver() {
    
    
}


void GameScene::resetGame() {
	this->cleanLevel();        
	this->drawBackground();	
        log("dra ok")	;
        auto status = CSLoader::createNode("res/StatusLayer.csb");
        status->setAnchorPoint(Vect(0.5f, 1.0f));
        status->setPosition(Vect(GeneralHelper::size.width/2, GeneralHelper::size.height));	
        life1 = (Sprite*)status->getChildByName("life_1");
        life2 = (Sprite*)status->getChildByName("life_2");
        life3 = (Sprite*)status->getChildByName("life_3");
        txtPoints = (ui::Text*) status->getChildByName("txtPoints");
        this->addChild(status,10);
        lifes=3;
        points=0;    
        updateTxtPoints();
        
        when_next_balloon = RandomHelper::random_real(INTERVAL_BALLOONS_MIN, INTERVAL_BALLOONS_MAX);
        timer_balloons = when_next_balloon + 1.0f;
        gamestate = GAME_STATE_PLAYING;
        this->scheduleUpdate();
}

void GameScene::cleanLevel() {
	
	this->removeAllChildrenWithCleanup(true);
	this->cleanup();
}




void GameScene::drawBackground() {
    
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



void GameScene::checkHit(Vec2 position) {
    
    log ("enter hit: %f, %f", position.x, position.y);
    auto children = this->getChildren();
    auto count = this->getChildrenCount();    
    Balloon *selected=nullptr;
    for(int i = 0; i < count; i++)
    {
        
        //auto circle = (Circle *) children->objectAtIndex(i);;
        auto child = children.at(i);
        if (child->getTag() != TAG_BALLOON) continue;
        
        auto nodeBox = child->getBoundingBox();
        
        auto origin_world = nodeBox.origin;                
        auto balloon_x = origin_world.x;
        auto balloon_y = origin_world.y;
        auto balloon_width = nodeBox.size.width;
        auto balloon_height = nodeBox.size.height;             
        
	auto nodeRect = Rect(balloon_x, balloon_y, balloon_width, balloon_height);
        //log("balloon: %f, %f - %f, %f", balloon_x, balloon_y, balloon_width, balloon_height);
        
        if (nodeRect.containsPoint(position)) {            
        
            auto zorder = child->getGlobalZOrder();
            log ("zorder: %d", zorder);
            if (selected != nullptr ) {                
                if (zorder > selected->getGlobalZOrder()) {
                    selected = (Balloon*)child;
                    log("maior");
                    continue;
                }
            } else {
                selected = (Balloon*)child;
            }           
        }
    }
    
    if (selected != nullptr) {
        log("explode");
        selected->onHit();
    }    
}




void GameScene::addPoints(int p) {
    this->points = this->points + p;
    updateTxtPoints();
}


void GameScene::updateTxtPoints() {
    //txtPoints->setText(Language::msg(MSG_LEVEL) + Value(GameHelper::currentlevelnum).asString());
    txtPoints->setText(Value(this->points).asString());
}


int GameScene::getPoints() {
    return points;
}