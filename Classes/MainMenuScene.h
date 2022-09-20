#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainMenu);

    void GoToGameScene(Ref* pSender);
    void menuCloseCallback(cocos2d::Ref* pSender);
};

#endif 
