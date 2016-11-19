/**
 * SoundFade.cpp
 * sound fade-in/out for cocos2d-x
 */

#include "SoundFade.h"

USING_NS_CC;
using namespace CocosDenshion;

/**
 * @class SoundFade
 */

/**
 * Constructor
 */
SoundFade::SoundFade()
:_targetVolume{0.0}
{
}

/**
 * Destructor
 */
SoundFade::~SoundFade()
{
}

/**
 * create instance
 */
SoundFade* SoundFade::create(float duration, float targetVolume)
{
    SoundFade* ret = new (std::nothrow) SoundFade();
    if (ret && ret->initWithDuration(duration, targetVolume)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

bool SoundFade::initWithDuration(float duration, float targetVolume)
{
    if (ActionInterval::initWithDuration(duration)) {
        this->_targetVolume = targetVolume;
        return true;
    }

    return false;
}

void SoundFade::update(float dt)
{
    float volume = this->_initialVolume + dt * this->_diffVolume;
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);
}

void SoundFade::startWithTarget(Node* target)
{
    ActionInterval::startWithTarget(target);
    this->_initialVolume = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
    this->_diffVolume = (this->_targetVolume - this->_initialVolume) / this->_duration;
}

void SoundFade::stop(void)
{
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    ActionInterval::stop();
}

SoundFade* SoundFade::clone() const
{
    return nullptr;
}

SoundFade* SoundFade::reverse() const
{
    return nullptr;
}

/**
 * @class SoundFadeIn
 */

/**
 * Constructor
 */
SoundFadeIn::SoundFadeIn()
{
}

/**
 * Destructor
 */
SoundFadeIn::~SoundFadeIn()
{
}

/**
 * create instance
 */
SoundFadeIn* SoundFadeIn::create(float duration, float targetVolume)
{
    SoundFadeIn* ret = new (std::nothrow) SoundFadeIn();
    if (ret && ret->initWithDuration(duration, targetVolume)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

bool SoundFadeIn::initWithDuration(float duration, float targetVolume)
{
    if (SoundFade::initWithDuration(duration, targetVolume)) {
        this->_targetVolume = targetVolume;
        return true;
    }

    return false;
}

void SoundFadeIn::startWithTarget(Node* target)
{
    SoundFade::startWithTarget(target);
}

/**
 * @class SoundFadeOut
 */

/**
 * Constructor
 */
SoundFadeOut::SoundFadeOut()
{
}

/**
 * Destructor
 */
SoundFadeOut::~SoundFadeOut()
{
}

/**
 * create instance
 */
SoundFadeOut* SoundFadeOut::create(float duration)
{
    SoundFadeOut* ret = new (std::nothrow) SoundFadeOut();
    if (ret && ret->initWithDuration(duration)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

bool SoundFadeOut::initWithDuration(float duration)
{
    return SoundFade::initWithDuration(duration, 0.0);
}

void SoundFadeOut::startWithTarget(Node* target)
{
    SoundFade::startWithTarget(target);
}
