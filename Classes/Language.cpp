/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Language.cpp
 * Author: guilherme
 * 
 * Created on 6 de Abril de 2017, 19:48
 */

#include "Language.h"


LanguageType Language::lang;

Language::Language() {
}

Language::Language(const Language& orig) {
}

Language::~Language() {
}


void Language::initialize()  {
    Language::lang = Application::getInstance()->getCurrentLanguage();
    //Language::lang = LanguageType::ARABIC;
}


char* Language::msg(int msgcode) {
    if (Language::lang == LanguageType::PORTUGUESE) {
        switch (msgcode) {
            case MSG_SHARE_GAMEOVER: return "! Minha pontuação em #Tap2Pop ";
            case MSG_SHARE_GAMEOVER_RECORD: return "! Meu novo record em #Tap2Pop ";
            case MSG_BEST: return "Máximo: ";
            case MSG_START: return "Estoure Para Começar!";
        }
    }    
    else {
         switch (msgcode) {
            case MSG_SHARE_GAMEOVER: return "! My score in #Tap2Pop ";
            case MSG_SHARE_GAMEOVER_RECORD: return "! My new record in #Tap2Pop ";
            case MSG_BEST: return "Best: ";
            case MSG_START: return "Pop to Start!";
        }
    }
    
    return "";
}


LanguageType Language::getLanguage()  {
   return Application::getInstance()->getCurrentLanguage();
   // return LanguageType::ARABIC;
}
