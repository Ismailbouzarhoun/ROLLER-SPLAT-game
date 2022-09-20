#include "PauseScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseMenu::create();
    scene->addChild(layer);
    return scene;
}

bool PauseMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Resume
    auto resumeItem =MenuItemImage::create("Resume_Button.png","Resume_Button.png",CC_CALLBACK_1(PauseMenu::Resume, this));
    resumeItem->setScale(0.9);
    
    //Rejouer
    auto retryItem = MenuItemImage::create("Retry_Button.png","Retry_Button.png",CC_CALLBACK_1(PauseMenu::Retry, this));
    retryItem->setScale(0.9);

    //HOME
    auto mainMenuItem =MenuItemImage::create("Menu_Button.png","Menu_Button.png",CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
    mainMenuItem->setScale(0.9);

    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto backgroundSprite = Sprite::create
    ("MainMenuScreen_Background.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
    backgroundSprite->setScale(0.55);
    this->addChild(backgroundSprite, -1);

    return true;
}

void PauseMenu::Resume(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    Director::getInstance()->popScene();
}
void PauseMenu::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = MainMenu::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
void PauseMenu::Retry(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = GameScreen::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}