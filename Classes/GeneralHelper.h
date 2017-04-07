/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneralHelper.h
 * Author: guilherme
 *
 * Created on 21 de Março de 2017, 23:49
 */

#ifndef GENERALHELPER_H
#define GENERALHELPER_H

#include "cocos2d.h"

#ifdef SDKBOX_ENABLED
#include "pluginsdkboxplay/PluginSdkboxPlay.h"
#endif
#ifdef SDKBOX_ENABLED
// #include "pluginshare/PluginShare.h"
#endif
#ifdef SDKBOX_ENABLED
#include "pluginadmob/PluginAdMob.h"
#endif
#ifdef SDKBOX_ENABLED
#include "plugingoogleanalytics/PluginGoogleAnalytics.h"
#endif



using namespace cocos2d;

class GeneralHelper {
public:
    GeneralHelper();
    GeneralHelper(const GeneralHelper& orig);
    virtual ~GeneralHelper();
    static void loadConfig();
    static void showLeaderboard();
    static void share();
    static void newRecord(int points);
    static void sendScoreLeaderboard(int points);
    static void logEvent(const std::string & eventCategory ,
                       const std::string & eventAction ,
                       const std::string & eventLabel ,
                       int value );
    static void showAd();
    static void hideAd();
    static int points_record;
    static Size size;
    
private:

};

#endif /* GENERALHELPER_H */
