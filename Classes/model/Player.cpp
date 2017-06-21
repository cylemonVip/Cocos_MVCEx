//
//  Player.cpp
//  MVCEx
//
//  Created by 程祎 on 2017/6/21.
//
//

#include "Player.h"
#include "cocos2d.h"
using namespace cocos2d;

Player::Player()
:_age(0)
,_delegate(nullptr)
{
    
}

Player::Player(PlayerDelegate *delegate)
:_age(0)
,_delegate(nullptr)
{
    _delegate = delegate;
}

Player::~Player()
{
    
}

void Player::setDelegate(PlayerDelegate *delegate)
{
    _delegate = delegate;
}

void Player::setAge(int age)
{
    if(-1 == age)
    {
        ++_age;
    }else if(_age != age)
    {
        _age = age;
    }
    _delegate->updateAge();
}

int Player::getAge()
{
    return _age;
}
