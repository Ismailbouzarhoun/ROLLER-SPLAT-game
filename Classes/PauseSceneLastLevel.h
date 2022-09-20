#ifndef __PAUSEMENULASTLEVEL_SCENE_H__
#define __PAUSEMENULASTLEVEL_SCENE_H__

#include "cocos2d.h"

class  PauseMenuLastLevel : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
    CREATE_FUNC(PauseMenuLastLevel);

    void Resume(Ref* pSender);
    void GoToMainMenuScene(Ref* pSender);
    void Retry(Ref* pSender);
};
#endif