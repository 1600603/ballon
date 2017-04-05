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


using namespace cocos2d;

class GeneralHelper {
public:
    GeneralHelper();
    GeneralHelper(const GeneralHelper& orig);
    virtual ~GeneralHelper();
    static void loadConfig();
    static void showLeaderboard();
    static void share();
    static int points_record;
    static Size size;
private:

};

#endif /* GENERALHELPER_H */
