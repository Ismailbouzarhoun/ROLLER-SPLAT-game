#include "LastLevel.h"
#include "PauseSceneLastLevel.h"
#include "WinScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* LastLevel::createScene()
{
    auto scene = Scene::create();
    auto layer = LastLevel::create();
    scene->addChild(layer);
    return scene;
}

bool LastLevel::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto pauseItem =MenuItemImage::create("Pause_Button.png","Pause_Button.png",CC_CALLBACK_1(LastLevel::GoToPauseScene, this));
    pauseItem->setScale(0.07);
    pauseItem->setPosition(Vec2(17, visibleSize.height  + origin.y - 25));

    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    //Background
    auto sprite = Sprite::create("bg2.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    sprite->setScale(0.3);
    this->addChild(sprite, -1);

    //ball
    auto my_sprite = Sprite::create("ball.png");
    my_sprite->setPosition(Vec2(286, 365));
    my_sprite->setScale(0.18);
    this->addChild(my_sprite, 2);
    
    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = CC_CALLBACK_2(LastLevel::Mouvement, this);
    my_sprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, my_sprite);

    return true;
}

void LastLevel::Mouvement(EventKeyboard::KeyCode keyCode, Event* event) {
    int i;
    drawNode = DrawNode::create();
    Vec2 loc = event->getCurrentTarget()->getPosition();
    if (loc == Vec2(286, 365))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            auto move = MoveTo::create(0.06, Vec2(loc.x - 253, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 253; i++)
            {
                drawNode->drawPoint(Vec2(loc.x - i, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(33, 365))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.06, Vec2(loc.x + 253, loc.y));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(33, 365))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.06, Vec2(loc.x, loc.y - 102));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 102; i++)
            {
                drawNode->drawPoint(Vec2(loc.x, loc.y - i), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");

        }
    }

    if (loc == Vec2(33, 263))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            auto move = MoveTo::create(0.06, Vec2(loc.x, loc.y + 102));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(33, 263))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.06, Vec2(142 + loc.x, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 142; i++)
            {
                drawNode->drawPoint(Vec2(i + loc.x, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(175, 263))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            auto move = MoveTo::create(0.06, Vec2(loc.x - 142, loc.y));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(175, 263))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.06, Vec2(loc.x, loc.y - 206));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i < 206; i++)
            {
                drawNode->drawPoint(Vec2(loc.x + 2, loc.y - i), 52.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(175, 57))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            auto move = MoveTo::create(0.06, Vec2(loc.x - 142, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 142; i++)
            {
                drawNode->drawPoint(Vec2(loc.x - i, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(175, 57))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            auto move = MoveTo::create(0.06, Vec2(loc.x, loc.y + 206));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(33, 57))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.06, Vec2(loc.x + 142, loc.y));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(33, 57))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            auto move = MoveTo::create(0.06, Vec2(loc.x, loc.y + 102));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 102; i++)
            {
                drawNode->drawPoint(Vec2(loc.x, loc.y + i), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(33, 159))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.06, Vec2(loc.x + 253, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 253; i++)
            {
                drawNode->drawPoint(Vec2(loc.x+ i, loc.y ), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            auto scene = Win::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(6,scene));
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Victory.wav");
            break;
        }
    }

    if (loc == Vec2(33, 159))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.06, Vec2(loc.x, loc.y - 102));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }
}

void LastLevel::GoToPauseScene(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = PauseMenuLastLevel::createScene();
    Director::getInstance()->pushScene(scene);
}

void LastLevel::GoToWinScene(cocos2d::Ref* pSender)
{
    auto scene = LastLevel::createScene();
    Director::getInstance()->replaceScene(scene);
}
