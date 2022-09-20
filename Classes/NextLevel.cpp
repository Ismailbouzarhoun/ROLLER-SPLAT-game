#include "NextLevel.h"
#include "PauseSceneNextLevel.h"
#include "LastLevel.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* NextLevel::createScene()
{
    auto scene = Scene::create();
    auto layer = NextLevel::create();
    scene->addChild(layer);
    return scene;
}

bool NextLevel::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto pauseItem =MenuItemImage::create("Pause_Button.png","Pause_Button.png",CC_CALLBACK_1(NextLevel::GoToPauseScene, this));
    pauseItem->setScale(0.07);
    pauseItem->setPosition(Vec2(17, visibleSize.height  + origin.y - 25));
    

    auto nextItem =
    MenuItemImage::create("next.png","next.png", CC_CALLBACK_1(NextLevel::GoToLastLevel, this));
    nextItem->setScale(0.5);
    nextItem->setPosition(Vec2(280, visibleSize.height + origin.y - 30));

    auto menu = Menu::create(pauseItem, nextItem, NULL);

    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    //Background
    auto sprite = Sprite::create("bg1.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    sprite->setScale(0.3);
    this->addChild(sprite, -1);
    //ball
    auto my_sprite = Sprite::create("ball.png");
    my_sprite->setPosition(Vec2(286, 57));
    my_sprite->setScale(0.18);
    this->addChild(my_sprite, 2);

    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = CC_CALLBACK_2(NextLevel::Mouvement, this);
    my_sprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, my_sprite);
    return true;
}

void NextLevel::Mouvement(EventKeyboard::KeyCode keyCode, Event* event) {
    int i;
    drawNode = DrawNode::create();
    Vec2 loc = event->getCurrentTarget()->getPosition();
    if (loc == Vec2(286, 57))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            auto move = MoveTo::create(0.08, Vec2(loc.x - 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 250; i++)
            {
                drawNode->drawPoint(Vec2(loc.x - i, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(36, 57))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.05, Vec2(loc.x + 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }
    if (loc == Vec2(36, 57))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            auto move = MoveTo::create(0.08, Vec2(loc.x, 102 + loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 102; i++)
            {
                drawNode->drawPoint(Vec2(loc.x, i + loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(36, 159))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.05, Vec2(loc.x + 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 250; i++)
            {
                drawNode->drawPoint(Vec2(loc.x + i, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }
    if (loc == Vec2(36, 159))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.08, Vec2(loc.x, loc.y - 102));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(286, 159))
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

    if (loc == Vec2(286, 159))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            auto move = MoveTo::create(0.05, Vec2(loc.x, loc.y + 102));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 104; i++)
            {
                drawNode->drawPoint(Vec2(loc.x, loc.y + i), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(286, 261))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            auto move = MoveTo::create(0.08, Vec2(loc.x - 250, loc.y  ));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 250; i++)
            {
                drawNode->drawPoint(Vec2(loc.x - i, loc.y +2), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(286, 261))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.05, Vec2(loc.x, loc.y - 102));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(36, 261))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.08, Vec2(loc.x + 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 250; i++)
            {
                drawNode->drawPoint(Vec2(loc.x + i, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(36, 261))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            auto move = MoveTo::create(0.05, Vec2(loc.x, 102 + loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 100; i++)
            {
                drawNode->drawPoint(Vec2(loc.x, i + loc.y + 2), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(36, 363))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            auto move = MoveTo::create(0.08, Vec2(loc.x + 250, loc.y));
            event->getCurrentTarget()->runAction(move);
            for (i = 0; i <= 250; i++)
            {
                drawNode->drawPoint(Vec2(loc.x + i, loc.y), 50.0f, Color4F::RED);
            }
            this->addChild(drawNode);
            auto scene = LastLevel::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(2,scene));
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }

    if (loc == Vec2(36, 363))
    {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            auto move = MoveTo::create(0.05, Vec2(loc.x, loc.y - 102));
            event->getCurrentTarget()->runAction(move);
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/ball.wav");
            break;
        }
    }
}

void NextLevel::GoToPauseScene(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = PauseMenuNextLevel::createScene();
    Director::getInstance()->pushScene(scene);
}

void NextLevel::GoToLastLevel(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/click.wav");
    auto scene = LastLevel::createScene();
    Director::getInstance()->replaceScene(scene);
}