// Copyright (c) 2020 CS126SP20. All rights reserved.
//move header files to include
#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_


#include <cinder/Tween.h>
#include <cinder/app/App.h>
#include <poSpritesheet/poSpritesheet.h>
#include <poSpritesheet/poSpritesheetAnimation.h>
#include <cinder/audio/audio.h>

#include "../src/engine.h"
#include "ciWMFVideoPlayer.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/params/Params.h"

namespace myapp {
enum class GameState {
  kStartScreen,
  kPlaying,
  kGameOver,
};

class MyApp : public cinder::app::App {
 public:
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void keyUp(cinder::app::KeyEvent) override;

 private:
  void SetGame();
  void SetWaveAnimation(int wave_number);
  void DrawAlienWave();
  void DrawPlayer();
  void DrawPlayerProjectile();
  void DrawAlienProjectile();
  void DrawNyanCat();
  void DrawStartScreen();
  void DrawGameOver();
  void DrawScore();
  void MyApp::ResetGame();
  void MyApp::NextWave();
  bool MyApp::IsWaveClear();

  const size_t kTileSize = 50/3;
  const int kMaxWave = 3;
  const int kAlienMaxSpeed = 60;

  int alien_speed = 300;
  int nyan_cat_speed = 60;
  int player_speed = 25;
  int projectile_speed = 8;
  int alien_projectile_speed = 14;

  space_invader::Engine engine;
  GameState state;
  std::chrono::time_point<std::chrono::system_clock> last_time_alien;
  std::chrono::time_point<std::chrono::system_clock> last_time_nyan_cat;
  std::chrono::time_point<std::chrono::system_clock> last_time_player;
  std::chrono::time_point<std::chrono::system_clock> last_time_projectile;
  std::chrono::time_point<std::chrono::system_clock> last_time_alien_projectile;

  po::SpritesheetRef mSpritesheet_gameover;
  po::SpritesheetAnimationRef mSpritesheetAnimation_gameover;
  po::SpritesheetRef mSpritesheet_nyan_cat;
  po::SpritesheetAnimationRef mSpritesheetAnimation_nyan_cat;
  ci::Anim<cinder::vec2> mPos;
  std::vector<po::SpritesheetAnimationRef> alien_spritesheetanim_vector;

  int alien_count = 0;
  int wave_count = 1;
  bool did_start = false;
  bool did_gameover_start = false;
  bool is_r_pressed = false;
  ci::gl::TextureRef texture_player;
  ci::gl::TextureRef texture_alien_bullet;
  ci::gl::TextureRef texture_player_bullet;
  ciWMFVideoPlayer mVideo1;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
