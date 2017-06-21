//
//  GameLayerViewdelegate.h
//  MVCEx
//
//  Created by 程祎 on 2017/6/21.
//
//

#ifndef GameLayerViewdelegate_h
#define GameLayerViewdelegate_h

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class GameLayerViewDelegate {
public:
    /** Callback function for touch began.
     *
     * @param touch Touch information.
     * @param unused_event Event information.
     * @return if return false, onTouchMoved, onTouchEnded, onTouchCancelled will never called.
     * @js NA
     */
    virtual bool onTouchBegan(Touch *touch, Event *unused_event) = 0;
    /** Callback function for touch moved.
     *
     * @param touch Touch information.
     * @param unused_event Event information.
     * @js NA
     */
    virtual void onTouchMoved(Touch *touch, Event *unused_event) = 0;
    /** Callback function for touch ended.
     *
     * @param touch Touch information.
     * @param unused_event Event information.
     * @js NA
     */
    virtual void onTouchEnded(Touch *touch, Event *unused_event) = 0;
    /** Callback function for touch cancelled.
     *
     * @param touch Touch information.
     * @param unused_event Event information.
     * @js NA
     */
    virtual void onTouchCancelled(Touch *touch, Event *unused_event) = 0;

};

#endif /* GameLayerViewdelegate_h */
