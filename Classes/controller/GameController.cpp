//
//  GameController.cpp
//  MVCEx
//
//  Created by 程祎 on 2017/6/21.
//
//

#include "GameController.h"
#include "GameLayerView.h"
#include "Player.h"

GameController::GameController()
:_player(nullptr)
{
    
}

GameController::~GameController()
{
    CC_SAFE_DELETE(_player);
}

bool GameController::init()
{
    if(!Node::init())
    {
        return false;
    }
    
    _player = new Player();
    _gameLayerView = GameLayerView::createWithDelegateAndPlayer(this, _player);
    this->addChild(_gameLayerView);
    _player->setDelegate((PlayerDelegate *)_gameLayerView);
    
    
    return true;
}

bool GameController::onTouchBegan(Touch *touch, Event *unused_event)
{
    _player->setAge();
    return true;
}

void GameController::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void GameController::onTouchEnded(Touch *touch, Event *unused_event)
{

}

void GameController::onTouchCancelled(Touch *touch, Event *unused_event)
{

}
