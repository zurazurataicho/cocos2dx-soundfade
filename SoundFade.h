/**
 * SoundFade.h
 * sound fade-in/out for cocos2d-x
 */

#ifndef __SOUND_FADE_H__
#define __SOUND_FADE_H__

#include "cocos2d.h"
#include "2d/CCNode.h"
#include "2d/CCActionInterval.h"
#include "SimpleAudioEngine.h"

/**
 * @class SoundFade
 */
class SoundFade : public cocos2d::ActionInterval
{
private:
    /**
     * Disable copy constructors and operators.
     */
    CC_DISALLOW_COPY_AND_ASSIGN(SoundFade);
    SoundFade(const SoundFade&&) = delete;
    SoundFade operator=(const SoundFade&&) = delete;

    float _initialVolume;
    float _targetVolume;
    float _diffVolume;

public:
    static SoundFade* create(float duration, float lastVolume);

    // Overrides
    virtual SoundFade* clone() const override;
    virtual SoundFade* reverse() const override;
    virtual void startWithTarget(cocos2d::Node* target) override;
    virtual void stop() override;
    virtual void update(float dt) override;
    void run();

CC_CONSTRUCTOR_ACCESS:
    SoundFade();
    virtual ~SoundFade();

    bool initWithDuration(float duration, float targetVolume);
};


/**
 * @class SoundFadeIn
 */
class SoundFadeIn : public SoundFade
{
private:
    /**
     * Disable copy constructors and operators.
     */
    CC_DISALLOW_COPY_AND_ASSIGN(SoundFadeIn);
    SoundFadeIn(const SoundFadeIn&&) = delete;
    SoundFadeIn operator=(const SoundFadeIn&&) = delete;

    float _targetVolume;

public:
    static SoundFadeIn* create(float duration, float targetVolume);
    void startWithTarget(cocos2d::Node* target) override;

CC_CONSTRUCTOR_ACCESS:
    SoundFadeIn();
    virtual ~SoundFadeIn();

    bool initWithDuration(float duration, float targetVolume);
};


/**
 * @class SoundFadeOut
 */
class SoundFadeOut : public SoundFade
{
private:
    /**
     * Disable copy constructors and operators.
     */
    CC_DISALLOW_COPY_AND_ASSIGN(SoundFadeOut);
    SoundFadeOut(const SoundFadeOut&&) = delete;
    SoundFadeOut operator=(const SoundFadeOut&&) = delete;

public:
    static SoundFadeOut* create(float duration);
    void startWithTarget(cocos2d::Node* target) override;

CC_CONSTRUCTOR_ACCESS:
    SoundFadeOut();
    virtual ~SoundFadeOut();

    bool initWithDuration(float duration);
};

#endif /* __SOUND_FADE_H__ */
