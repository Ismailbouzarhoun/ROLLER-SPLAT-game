#include "PauseSceneLastLevel.h"
#include "LastLevel.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* PauseMenuLastLevel::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseMenuLastLevel::create();
    scene->addChild(layer);
    return scene;
}

bool PauseMenuLastLevel::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto resumeItem =MenuItemImage::create("Resume_Button.png","Resume_Button.png",CC_CALLBACK_1(PauseMenuLastLevel::Resume, this));
    resumeItem->setScale(0.9);

    auto retryItem = MenuItemImage::create("Retry_Button.png","Retry_Button.png",CC_CALLBACK_1(PauseMenuLastLevel::Retry, this));
    retryItem->setScale(0.9);

    auto mainMenuItem =MenuItemImage::create("Menu_Button.png","Menu_Button.png",CC_CALLBACK_1(PauseMenuLastLevel::GoToMainMenuScene, this));
    mainMenuItem->setScale(0.9);

    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto backgroundSprite = Sprite::create("MainMenuScreen_Background.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
    backgroundSprite->setScale(0.55);
    this->addChild(backgroundSprite, -1);

    return true;
}

void PauseMenuLastLevel::Resume(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    Director::getInstance()->popScene();
}
void PauseMenuLastLevel::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = MainMenu::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
void PauseMenuLastLevel::Retry(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = LastLevel::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}