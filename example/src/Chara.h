//
//  Chara.h
//  example
//
//  Created by hiz on 2015/07/04.
//
//

#ifndef __example__Chara__
#define __example__Chara__

#include <ofMain.h>
#include "ofxEventAction.h"

class Chara : public ofNode, public ofxEventAction {
public:
    Chara():ofNode(),ofxEventAction() {
        setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    }
    virtual void customDraw() {
        ofSetColor(255);
        ofCircle(0, 0, 20);
    }
protected:
    // 連続で同じイベントが起動された場合に初回のみ実行される処理
    virtual void startEvent(int type) {
        ofLog() << "start" << endl;
    }
    // 連続で同じイベントが起動された場合に二回目以降に実行される処理
    virtual void loopEvent(int type) {
        switch(type) {
            case 'a':
                move(-2, 0, 0);
                break;
            case 'd':
                move( 2, 0, 0);
                break;
            case 'w':
                move( 0,-2, 0);
                break;
            case 's':
                move( 0, 2, 0);
                break;
        }
    }
    // 連続で同じイベントが起動された場合に最後に実行される処理
    // ※ 厳密にはイベントが最後に起動された次のフレームに実行される
    virtual void endEvent(int type) {
        ofLog() << "end" << endl;
    }

};

#endif /* defined(__example__Chara__) */
