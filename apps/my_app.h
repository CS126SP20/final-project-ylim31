// Copyright (c) 2020 CS126SP20. All rights reserved.
//move header files to include
#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/Tween.h>
#include <cinder/app/App.h>
#include <poSpritesheet/poSpritesheet.h>
#include <poSpritesheet/poSpritesheetAnimation.h>

#include "../src/engine.h"
#include "ciWMFVideoPlayer.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void keyUp(cinder::app::KeyEvent) override;

 private:
  void DrawAlienWave() const;
  void DrawPlayer() const;
  void DrawProjectile() const;
  space_invader::Engine engine;
  const size_t alien_size = 50;
  const size_t projectile_size = 50/3;
  const size_t speed = 1000;
  const size_t speed_player = 80;
  const size_t speed_projectile = 40;
  std::chrono::time_point<std::chrono::system_clock> last_time;
  std::chrono::time_point<std::chrono::system_clock> last_time_player;
  std::chrono::time_point<std::chrono::system_clock> last_time_projectile;
  bool isSpace = false;
  bool isFired = false;
  //ofstream::dog;
  bool isFirst = true;
  int count = 0;

  //cinder::gl::Texture player_bullet_image;

  //po::SpritesheetRef mSpritesheet;
  //po::SpritesheetAnimationRef mSpritesheetAnimation;

  ci::Anim<cinder::vec2> mPos;
  cinder::vec2 mEndPos;
  //ci::gl::TextureRef texture;
  //cinder::JsonTree json;
  std::vector<po::SpritesheetAnimationRef> alien_vector;
  std::vector<ci::Anim<cinder::vec2>> mPos_vector;


};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
