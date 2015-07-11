//
//  ofxEventAction.cpp
//  example
//
//  Created by hiz on 2015/07/04.
//
//

#include "ofxEventAction.h"

void ofxEventAction::fireEvent(int type) {
    events[type] = 1;
}

void ofxEventAction::repeatEvent(int type, int num) {
    events[type] = num;
}

void ofxEventAction::stopEvent(int type) {
    events[type] = 0;
}

void ofxEventAction::updateEvent() {
    using namespace std;
    eventState.clear();
    // イベントの開始時・ループ時処理
    for(map<int, int>::iterator ite=events.begin();ite!=events.end();ite++) {
        if(ite->second == 0) continue;
        if(preEvents.find(ite->first) != preEvents.end()) {
            // 二回目以降の処理
            loopEvent(ite->first);
            eventState[ite->first] = LOOP;
        } else {
            // 初回処理
            startEvent(ite->first);
            eventState[ite->first] = START;
        }
    }
    // イベント終了時の処理
    for(set<int>::iterator ite=preEvents.begin();ite!=preEvents.end();ite++) {
        map<int,int>::iterator fite = events.find(*ite);
        if(fite == events.end() || fite->second == 0) {
            // 終了時の処理
            endEvent(*ite);
            eventState[*ite] = END;
        }
    }
    
    // 前回イベントにコピー・イベントの更新
    preEvents.clear();
    for(map<int, int>::iterator ite=events.begin();ite!=events.end();ite++) {
        if(ite->second != 0) {
            preEvents.insert(ite->first);
        }
        if(ite->second == 0) {
            events.erase(ite);
        } else {
            preEvents.insert(ite->first);
            if(ite->second > 0) {
                events[ite->first] --;
            }

        }
    }
}

int ofxEventAction::getEventState(int type) {
    if(eventState.count(type) == 0) return NONE;
    return eventState[type];
}