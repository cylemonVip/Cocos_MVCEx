//
//  GameLayerView.cpp
//  MVCEx
//
//  Created by 程祎 on 2017/6/21.
//
//

#include "GameLayerView.h"

GameLayerView::GameLayerView()
:_delegate(nullptr)
,_touchEventListener(nullptr)
{
    
}

GameLayerView::~GameLayerView()
{
    
}

GameLayerView* GameLayerView::createWithDelegateAndPlayer(GameLayerViewDelegate *delegate, Player *player)
{
    GameLayerView *pRet = new(std::nothrow) GameLayerView();
    if (pRet && pRet->initWithDelegateAndPlayer(delegate, player))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool GameLayerView::initWithDelegateAndPlayer(GameLayerViewDelegate *delegate, Player *player)
{
    if(!Layer::init())
    {
        return false;
    }
    
    _player = player;
    _delegate = delegate;
    initTouchEvent();
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    _ageLabel = Label::createWithTTF("1", "fonts/Marker Felt.ttf", 24);
    _ageLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - _ageLabel->getContentSize().height));
    this->addChild(_ageLabel, 1);
    
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);

    return true;
}

void GameLayerView::onEnter()
{
    Layer::onEnter();
}

void GameLayerView::onExit()
{
    Layer::onExit();
    _eventDispatcher->removeEventListener(_touchEventListener);
}

void GameLayerView::updateAge()
{
    char buf[20];
    sprintf(buf, "%d", _player->getAge());
    _ageLabel->setString(buf);
}

void GameLayerView::initTouchEvent()
{
    _touchEventListener = EventListenerTouchOneByOne::create();
    
    _touchEventListener->onTouchBegan = CC_CALLBACK_2(GameLayerView::onTouchBegan, this);
    _touchEventListener->onTouchMoved = CC_CALLBACK_2(GameLayerView::onTouchMoved, this);
    _touchEventListener->onTouchEnded = CC_CALLBACK_2(GameLayerView::onTouchEnded, this);
    _touchEventListener->onTouchCancelled = CC_CALLBACK_2(GameLayerView::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchEventListener, this);
}

bool GameLayerView::onTouchBegan(Touch *touch, Event *unused_event)
{
    return _delegate->onTouchBegan(touch, unused_event);
}

void GameLayerView::onTouchMoved(Touch *touch, Event *unused_event)
{
    _delegate->onTouchMoved(touch, unused_event);
}

void GameLayerView::onTouchEnded(Touch *touch, Event *unused_event)
{
    _delegate->onTouchEnded(touch, unused_event);
}

void GameLayerView::onTouchCancelled(Touch *touch, Event *unused_event)
{
    _delegate->onTouchCancelled(touch, unused_event);
}
