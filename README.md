# SoundFade class for cocos2d-x

Usage:
  auto background = Sprite::create("background.png");

     ...

  auto soundFadeout = SoundFadeOut::create(0.5);
  background->runAction(soundFadeout);
