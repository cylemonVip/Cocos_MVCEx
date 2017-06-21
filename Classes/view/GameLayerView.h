//
//  GameLayerView.h
//  MVCEx
//
//  Created by 程祎 on 2017/6/21.
//
//

#ifndef GameLayerView_h
#define GameLayerView_h

#include <stdio.h>
#include "cocos2d.h"
#include "GameLayerViewDelegate.h"
#include "Player.h"
using namespace cocos2d;

class GameLayerView : public Layer , PlayerDelegate{
public:
    GameLayerView();
    ~GameLayerView();
    
    static GameLayerView* createWithDelegateAndPlayer(GameLayerViewDelegate *delegate, Player *player);
    
    virtual bool initWithDelegateAndPlayer(GameLayerViewDelegate *delegate, Player *player);
    
    virtual void updateAge();
    
    virtual void onEnter();
    virtual void onExit();
    
    CC_SYNTHESIZE(Player*, _player, Player);
    
protected:
    void initTouchEvent();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
    
    void updatePlayerAge(Ref* ref);
private:
    GameLayerViewDelegate *_delegate;
    EventListenerTouchOneByOne *_touchEventListener;
    Label *_ageLabel;
};

#endif /* GameLayerView_h */
