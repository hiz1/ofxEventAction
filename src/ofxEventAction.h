//
//  ofxEventAction.h
//  example
//
//  Created by hiz on 2015/07/04.
//
//

#ifndef __example__ofxEventAction__
#define __example__ofxEventAction__

#include <stdio.h>
#include <map>
#include <set>

class ofxEventAction {
public:
    static const int NONE  = 0;
    static const int START = 1;
    static const int LOOP  = 2;
    static const int END   = 3;
    // イベントを一度だけ起動
    void fireEvent(int type);
    // イベントをnum回連続で起動
    void repeatEvent(int type, int num = -1);
    // イベントの起動を停止
    void stopEvent(int type);
    void updateEvent();
    int  getEventState(int type);
protected:
    // 連続で同じイベントが起動された場合に初回のみ実行される処理
    virtual void startEvent(int type);
    // 連続で同じイベントが起動された場合に二回目以降に実行される処理
    virtual void loopEvent(int type);
    // 連続で同じイベントが起動された場合に最後に実行される処理
    // ※ 厳密にはイベントが最後に起動された次のフレームに実行される
    virtual void endEvent(int type);
private:
    std::map<int, int> events;
    std::map<int, int> eventState;
    std::set<int> preEvents;
};

#endif /* defined(__example__ofxEventAction__) */
