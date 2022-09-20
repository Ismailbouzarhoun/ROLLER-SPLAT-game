#include "GameScene.h"
#include "PauseScene.h"
#include "NextLevel.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScreen::create();
    scene->addChild(layer);
    return scene;
}

bool GameScreen::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //---------Menu-------------
    //Pause
    auto pauseItem = MenuItemImage::create("Pause_Button.png","Pause_Button.png",CC_CALLBACK_1(GameScreen::GoToPauseScene, this));
    pauseItem->setScale(0.07);
    pauseItem->setPosition(Vec2(17, visibleSize.height  + origin.y - 25));
    //le niveau prochaine
    auto nextItem = MenuItemImage::create("next.png","next.png", CC_CALLBACK_1(GameScreen::GoToNextLevel, this));
    nextItem->setScale(0.5);
    nextItem->setPosition(Vec2(280, visibleSize.height + origin.y - 30));
    
    auto menu = Menu::create(pauseItem,nextItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    //Background
    auto sprite = Sprite::create("bg.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    sprite->setScale(0.37);
    this->addChild(sprite, -1);

    //ball
    auto my_sprite = Sprite::create("ball.png");
    my_sprite->setPosition(Vec2(286, 95));
    my_sprite->setScale(0.18);
    this->addChild(my_sprite, 20);

    auto eventListener = EventListenerKeyboard::create();
    
    eventListener->onKeyPressed = CC_CALLBACK_2(GameScreen::Mouvement,this);
   my_sprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, my_sprite);

    return true;
}

void GameScreen::Mouvement(EventKeyboard::KeyCode keyCode, Event* event) {
    int i;
    drawNode = DrawNode::create();
    Vec2 loc = event->getCurrentTarget()->getPosition();
    
    if (loc == Vec2(286, 95))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            auto move = MoveTo::create(0.08, Vec2(loc.x - 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            for ( i = 0; i <= 250; i++)
            {
                    drawNode->drawPoint(Vec2(286 - i, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");

            break;
        }
    }

    if (loc == Vec2(36, 95))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.08, Vec2(loc.x + 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");

            break;
        }
    }

    if (loc == Vec2(36, 95))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            auto move = MoveTo::create(0.08, Vec2(loc.x, 267 + loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i < 270; i++)
            {
                drawNode->drawPoint(Vec2(loc.x, i + loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }


    if (loc == Vec2(36, 362))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.08, Vec2(loc.x, loc.y - 267));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(36, 362))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.08, Vec2(loc.x + 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 250; i++)
            {
                drawNode->drawPoint(Vec2(loc.x + i, loc.y+2), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(286, 362))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            auto move = MoveTo::create(0.08, Vec2(loc.x - 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(286, 362))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.08, Vec2(loc.x, loc.y - 200));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 200; i++)
            {
                drawNode->drawPoint(Vec2(loc.x , loc.y - i), 50.0f, Color4F::RED);
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            this->addChild(drawNode);
            auto scene = NextLevel::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
            break;
        }
    }
}

void GameScreen::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();
    Director::getInstance()->pushScene(scene);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
}

void GameScreen::GoToNextLevel(cocos2d::Ref* pSender) {
    auto scene = NextLevel::createScene();
    Director::getInstance()->replaceScene(scene);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");

}