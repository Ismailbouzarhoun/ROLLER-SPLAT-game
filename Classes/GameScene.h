#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
class  GameScreen : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScreen);

    void GoToPauseScene(Ref* pSender);
    void GoToNextLevel(Ref* pSender);
    void Mouvement(EventKeyboard::KeyCode keyCode, Event* event);

    cocos2d::DrawNode* drawNode;
    cocos2d::Sprite* my_sprite;
};

#endif
