//
//  Player.h
//  MVCEx
//
//  Created by 程祎 on 2017/6/21.
//
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include "PlayerDelegate.h"

class Player {
public:
    Player();
    Player(PlayerDelegate *delegate);
    ~Player();
    
    void setAge(int value = -1);
    int getAge();
    void setDelegate(PlayerDelegate *delegate);
protected:
    int _age;
    PlayerDelegate *_delegate;
};

#endif /* Player_h */
