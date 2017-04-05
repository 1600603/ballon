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
}


void GeneralHelper::showLeaderboard() {
   
}

void GeneralHelper::share() {
   
}


