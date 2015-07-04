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
    // イベントを一度だけ起動
    void fireEvent(int type);
    // イベントをnum回連続で起動
    void repeatEvent(int type, int num = -1);
    // イベントの起動を停止
    void stopEvent(int type);
    void updateEvent();
protected:
    // 連続で同じイベントが起動された場合に初回のみ実行される処理
    virtual void startEvent(int type) = 0;
    // 連続で同じイベントが起動された場合に二回目以降に実行される処理
    virtual void loopEvent(int type) = 0;
    // 連続で同じイベントが起動された場合に最後に実行される処理
    // ※ 厳密にはイベントが最後に起動された次のフレームに実行される
    virtual void endEvent(int type) = 0;
private:
    std::map<int, int> events;
    std::set<int> preEvents;
};

#endif /* defined(__example__ofxEventAction__) */
