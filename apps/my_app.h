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
#include "cinder/params/Params.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void keyUp(cinder::app::KeyEvent) override;

 private:
  void DrawAlienWave();
  void DrawPlayer();
  void DrawPlayerProjectile();
  void DrawAlienProjectile();
  void DrawNyanCat();

  const size_t kTileSize = 50/3;
  int alien_speed = 200;
  int nyan_cat_speed = 100;
  int player_speed = 40;
  int projectile_speed = 12;

  space_invader::Engine engine;
  std::chrono::time_point<std::chrono::system_clock> last_time_alien;
  std::chrono::time_point<std::chrono::system_clock> last_time_nyan_cat;
  std::chrono::time_point<std::chrono::system_clock> last_time_player;
  std::chrono::time_point<std::chrono::system_clock> last_time_projectile;

  po::SpritesheetRef mSpritesheet_bullet;
  po::SpritesheetAnimationRef mSpritesheetAnimation_bullet;
  po::SpritesheetRef mSpritesheet_alien_bullet;
  po::SpritesheetAnimationRef mSpritesheetAnimation_alien_bullet;
  po::SpritesheetRef mSpritesheet_nyan_cat;
  po::SpritesheetAnimationRef mSpritesheetAnimation_nyan_cat;

  ci::Anim<cinder::vec2> mPos;
  std::vector<po::SpritesheetAnimationRef> alien_spritesheetanim_vector;
  int alien_count = 0;

  bool mVideoSetup;
  ciWMFVideoPlayer mVideo1;
  ci::params::InterfaceGlRef mParams;
  float	mFps;

  ci::gl::TextureRef texture_player;
  ci::gl::TextureRef texture_alien_bullet;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
