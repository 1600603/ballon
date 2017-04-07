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
#include "LostLayer.h"

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
    if (this->gamestate != GAME_STATE_PLAYING) return;
    //this->checkGameOver();
    timer_balloons += dt;
    if (timer_balloons > when_next_balloon) {
        //addballon;
        timer_balloons=0.0f;
        when_next_balloon = RandomHelper::random_real(INTERVAL_BALLOONS_MIN, INTERVAL_BALLOONS_MAX);
        int next_balloon = TYPE_BALLOON_RANDOM;
        float chance = RandomHelper::random_real(0.0f,1.0f);
        if (chance<=chance_balloon_gameover) next_balloon = TYPE_BALLOON_SKULL;
        else if (chance<=chance_balloon_lost_life) next_balloon = TYPE_BALLOON_MINUS_LIFE;
        else if (chance<=chance_balloon_lost_score) next_balloon = TYPE_BALLOON_MINUS_SCORE;
        else if (chance<=chance_balloon_plus_life) next_balloon = TYPE_BALLOON_PLUS_LIFE;

        auto balao = Balloon::createSprite(this, balloon_count, next_balloon);
        balloon_count++;
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
    if (this->lifes<=0) doGameOver();
}

void GameScene::doGameOver() {
    this->gamestate = GAME_STATE_GAME_OVER;
    auto points = this->txtPoints;
    auto setinvisible = CallFunc::create([points]() {
        points->setVisible(false);
    });

    FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
    txtPoints->runAction(Sequence::create(fadeOut, setinvisible, nullptr));
    AssetsHelper::pauseMusic();
    if (this->points > GeneralHelper::points_record) {
        GeneralHelper::points_record = this->points;
        GeneralHelper::newRecord(this->points);
        this->addChild(LostLayer::createLayer(this, true), 5);
        AssetsHelper::playEffect(SND_RECORD);
    } else {
        this->addChild(LostLayer::createLayer(this), 5);
        AssetsHelper::playEffect(SND_GAMEOVER);
    }
    
}

GameState GameScene::getGameState() {
    return gamestate;
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
        life4 = (Sprite*)status->getChildByName("life_4");
        life5 = (Sprite*)status->getChildByName("life_5");
        txtPoints = (ui::Text*) status->getChildByName("txtPoints");
        this->addChild(status,10);
        lifes=3;
        life4->setVisible(false);
        life5->setVisible(false);
        points=0;
        updateTxtPoints();
        chance_balloon_gameover= 0.05f;
        chance_balloon_lost_life= 0.10f;
        chance_balloon_lost_score= 0.15f;
        chance_balloon_plus_life= 0.20f;
        when_next_balloon = RandomHelper::random_real(INTERVAL_BALLOONS_MIN, INTERVAL_BALLOONS_MAX);
        timer_balloons = when_next_balloon + 1.0f;
        gamestate = GAME_STATE_PLAYING;
        balloon_count=0;
        this->scheduleUpdate();
        AssetsHelper::resumeMusic();
}

void GameScene::cleanLevel() {

	this->removeAllChildrenWithCleanup(true);
	this->cleanup();
}


void GameScene::removeLife() {
    Sprite* life_icon;
    if (lifes<=0) return;
    if (lifes==1) life_icon = life1;
    if (lifes==2) life_icon = life2;
    if (lifes==3) life_icon = life3;
    if (lifes==4) life_icon = life4;
    if (lifes==5) life_icon = life5;
    auto setinvisible = CallFunc::create([life_icon]() {
        life_icon->setVisible(false);
    });
    std::string file_name_icon = PNG_STATUS_BAR_LIFE;
    //life_icon->setTexture(file_name_icon + "_pop.png");
    life_icon->setSpriteFrame(file_name_icon + "_pop.png");

    FadeOut* fadeOut = FadeOut::create(TIMER_DIE);
    //life_icon->runAction(fadeOut);
    life_icon->runAction(Sequence::create(fadeOut, setinvisible, nullptr));
    lifes--;
    checkGameOver();
}



void GameScene::removeAllLifes() {
    while(lifes>0) removeLife();
}


void GameScene::addLife() {
    Sprite* life_icon;
    lifes++;
    if (lifes>5)  {
        lifes = 5;
        return;
    }
    if (lifes==1) life_icon = life1;
    if (lifes==2) life_icon = life2;
    if (lifes==3) life_icon = life3;
    if (lifes==4) life_icon = life4;
    if (lifes==5) life_icon = life5;
    life_icon->stopAllActions();    
    std::string file_name_icon = PNG_STATUS_BAR_LIFE;
    //life_icon->setTexture(file_name_icon + ".png");
    life_icon->setSpriteFrame(file_name_icon + ".png");
    life_icon->setVisible(true);
    FadeIn* fadeIn = FadeIn::create(TIMER_DIE);
    life_icon->runAction(fadeIn);

}


void GameScene::drawBackground() {

     std::string pngfile = PNG_BACKGROUND_REPEAT;
	int num=1;
	if (BACKGROUND_MAX_PATTERNS > 1) {
		num = RandomHelper::random_int(1, BACKGROUND_MAX_PATTERNS);
		//if (num > 0) {
			pngfile = pngfile + "_" + Value(num).asString() + ".png";
		//}
	}

        Color4B color_back;
        if (num==1) color_back = Color4B(190,255,190,255);
        if (num==2) color_back = Color4B(220,190,255,255);
        if (num==3) color_back = Color4B(190,190,255,255);
        if (num==4) color_back = Color4B(255,255,220,255);
        if (num==5) color_back = Color4B(255,255,180,255);
        if (num==6) color_back = Color4B(210,190,255,255);

      //  log(pngfile.c_str());


	LayerColor *layer = LayerColor::create(color_back);
	//Sprite *sprite = Sprite::create(pngfile);
        Sprite *sprite = Sprite::createWithSpriteFrameName(pngfile);
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
			//auto tile = Sprite::create(pngfile);
                        auto tile = Sprite::createWithSpriteFrameName(pngfile);
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

            //auto zorder = child->getGlobalZOrder();
            auto zorder = ((Balloon*)child)->balloon_number;
            log ("zorder: %d", zorder);
            if (selected != nullptr ) {
                //if (zorder > selected->getGlobalZOrder()) {
                if (zorder > ((Balloon*)selected)->balloon_number) {
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

void GameScene::removePoints(int p) {
    this->points = this->points - p;
    this->points = this->points<0?0:this->points;
    updateTxtPoints();
}


void GameScene::updateTxtPoints() {
    //txtPoints->setText(Language::msg(MSG_LEVEL) + Value(GameHelper::currentlevelnum).asString());
    txtPoints->setText(Value(this->points).asString());
}


int GameScene::getPoints() {
    return points;
}
