//
//  GameController.h
//  MVCEx
//
//  Created by 程祎 on 2017/6/21.
//
//

#ifndef GameController_h
#define GameController_h

#include <stdio.h>
#include "cocos2d.h"
#include "GameLayerViewDelegate.h"
using namespace cocos2d;

class GameLayerView;
class Player;

class GameController : public Scene, GameLayerViewDelegate{
public:
    GameController();
    ~GameController();
    
    virtual bool init();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
    
    CREATE_FUNC(GameController);
    
    void updateByModel(Ref* ref);
public:
    GameLayerView *_gameLayerView;
    Player *_player;
};

#endif /* GameController_h */
