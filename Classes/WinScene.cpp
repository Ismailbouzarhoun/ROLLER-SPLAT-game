#include "WinScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* Win::createScene()
{
    auto scene = Scene::create();
    auto layer = Win::create();
    scene->addChild(layer);
    return scene;
}

bool Win::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create("congrat.png","congrat.png");
    menuTitle->setScale(0.65);

    auto playItem = MenuItemImage::create("Home.png","Home.png",CC_CALLBACK_1(Win::GoToMainMenu, this));
    playItem->setScale(0.2);

    auto menu = Menu::create(menuTitle, playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto backgroundSprite = Sprite::create("MainMenuScreen_Background.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
    backgroundSprite->setScale(0.55);
    this->addChild(backgroundSprite, -1);

    return true;
}

void Win::GoToMainMenu(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
}
