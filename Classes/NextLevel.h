#ifndef __NEXT_LEVEL_H__
#define __NEXT_LEVEL_H__

#include "cocos2d.h"
using namespace cocos2d;

class  NextLevel : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(NextLevel);

    void GoToPauseScene(Ref* pSender);
    void GoToLastLevel(Ref* pSender);
    void Mouvement(EventKeyboard::KeyCode keyCode, Event* event);
    cocos2d::DrawNode* drawNode;
    cocos2d::Sprite* my_sprite;
};

#endif
