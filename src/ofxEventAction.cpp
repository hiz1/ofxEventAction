//
//  ofxEventAction.cpp
//  example
//
//  Created by hiz on 2015/07/04.
//
//

#include "ofxEventAction.h"

void ofxEventAction::raiseEvent(int type) {
    events.insert(type);
}

void ofxEventAction::update() {
    using namespace std;
    // イベントの開始時・ループ時処理
    for(set<int>::iterator ite=events.begin();ite!=events.end();ite++) {
        if(preEvents.find(*ite) != preEvents.end()) {
            // 二回目以降の処理
            loopEvent(*ite);
        } else {
            // 初回処理
            startEvent(*ite);
        }
    }
    // イベント終了時の処理
    for(set<int>::iterator ite=preEvents.begin();ite!=preEvents.end();ite++) {
        if(events.find(*ite) == events.end()) {
            // 終了時の処理
            endEvent(*ite);
        }
    }
    
    // 前回イベントにコピー・イベントの初期化
    preEvents.clear();
    for(set<int>::iterator ite=events.begin();ite!=events.end();ite++) {
        preEvents.insert(*ite);
    }
    events.clear();
    
}