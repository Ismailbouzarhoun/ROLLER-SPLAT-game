#include "MainMenuScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    return scene;
}

bool MainMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create("Game_Title.png","Game_Title.png");
    menuTitle->setScale(0.7);

    auto playItem = MenuItemImage::create("Play_Button.png","Play_Button.png",CC_CALLBACK_1(MainMenu::GoToGameScene, this));
    playItem->setScale(0.16);

    auto closeItem = MenuItemImage::create("exit.png","exit.png",CC_CALLBACK_1(MainMenu::menuCloseCallback, this));
    closeItem->setScale(0.75);


    auto menu = Menu::create(menuTitle, playItem, closeItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto backgroundSprite = Sprite::create("MainMenuScreen_Background.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +origin.x, (visibleSize.height / 2) + origin.y));
    backgroundSprite->setScale(0.55);
    this->addChild(backgroundSprite, -1);

    if (CocosDenshion::SimpleAudioEngine::getInstance()->
        isBackgroundMusicPlaying() == false)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Audio/Music.wav");
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/Music.wav", true);
    }
    return true;
}

void MainMenu::GoToGameScene(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = GameScreen::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInB::create(2, scene));
}

void MainMenu::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
