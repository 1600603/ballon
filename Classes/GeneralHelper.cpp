/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneralHelper.cpp
 * Author: guilherme
 * 
 * Created on 21 de Março de 2017, 23:49
 */

#include "GeneralHelper.h"
#include "AssetsHelper.h"
#include "Language.h"

Size GeneralHelper::size;
int GeneralHelper::points_record=0;

GeneralHelper::GeneralHelper() {
}

GeneralHelper::GeneralHelper(const GeneralHelper& orig) {
}

GeneralHelper::~GeneralHelper() {
}

void GeneralHelper::loadConfig() {
    GeneralHelper::size= Director::getInstance()->getVisibleSize();
    GeneralHelper::points_record = UserDefault::sharedUserDefault()->getIntegerForKey("record", 0);
    AssetsHelper::preload();
    Language::initialize();
    
    
    #ifdef SDKBOX_ENABLED
    sdkbox::PluginSdkboxPlay::init();
    #endif
    #ifdef SDKBOX_ENABLED
    //sdkbox::PluginShare::init();
    #endif    
    #ifdef SDKBOX_ENABLED
    sdkbox::PluginGoogleAnalytics::init();
    #endif
    
    #ifdef SDKBOX_ENABLED
    sdkbox::PluginAdMob::init();
    sdkbox::PluginAdMob::setTestDevices("39545a171f3c5376,ad52654ca927ccd4");
    sdkbox::PluginAdMob::cache("ingame");
   // log("admob loaded");
    #endif
}


void GeneralHelper::showLeaderboard() {
   #ifdef SDKBOX_ENABLED
    sdkbox::PluginSdkboxPlay::showLeaderboard("rankingBest");
    #endif   
    
}

void GeneralHelper::share() {
   
}

void GeneralHelper::newRecord(int points) {   
    
    UserDefault::sharedUserDefault()->setIntegerForKey("record", points);
    GeneralHelper::logEvent("new record", "new record " + Value(points).asString(),"ingame",0);
    GeneralHelper::sendScoreLeaderboard(points);
    
}

void GeneralHelper::sendScoreLeaderboard(int points) {
     #ifdef SDKBOX_ENABLED
    sdkbox::PluginSdkboxPlay::submitScore("rankingBest", points);
    #endif 
}


void GeneralHelper::logEvent(const std::string & eventCategory ,
                       const std::string & eventAction ,
                       const std::string & eventLabel ,
                       int value ) {
    
#ifdef SDKBOX_ENABLED   
    sdkbox::PluginGoogleAnalytics::logEvent(eventCategory, eventAction, eventLabel, value);
#endif    
}


void GeneralHelper::showAd() {
    //if (GameHelper::no_ads) return;
    
    #ifdef SDKBOX_ENABLED
    if (sdkbox::PluginAdMob::isAvailable("ingame"))
       sdkbox::PluginAdMob::show("ingame");
    else
        sdkbox::PluginAdMob::cache("ingame");   
   
        
    #endif  
}


void GeneralHelper::hideAd() {
    #ifdef SDKBOX_ENABLED   
     sdkbox::PluginAdMob::hide("ingame");
    #endif  
}


