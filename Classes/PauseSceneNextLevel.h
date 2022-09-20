#ifndef __PAUSEMENUNEXTLEVEL_SCENE_H__
#define __PAUSEMENUNEXTLEVEL_SCENE_H__

#include "cocos2d.h"

class  PauseMenuNextLevel : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PauseMenuNextLevel);

    void Resume(Ref* pSender);
    void GoToMainMenuScene(Ref* pSender);
    void Retry(Ref* pSender);
};

#endif
