// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include "../src/alien.h"
#include <cinder/app/App.h>
#include "ciWMFVideoPlayer.h"
#include "cinder/gl/gl.h"
#include "poScene/SpriteView.h"


namespace myapp {
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::app::KeyEvent;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

void MyApp::setup() {
  std::string videoPath = getAssetPath( "space.mp4" ).string();
  mVideo1.loadMovie( videoPath, "Headphones (High Definition Audio Device)" );
  mVideo1.play();
  mVideo1.setLoop(true);
  mParams = ci::params::InterfaceGl::create( "Params", ci::ivec2( 0, 0 ) );
  mParams->addParam<float>( "FPS", &mFps, true );



  engine.SetUpWave();
  for (const space_invader::Alien& alien : engine.GetAlienWave()) {
    ci::gl::TextureRef texture = ci::gl::Texture::create(loadImage(loadAsset("alien.png")));
    cinder::JsonTree json = cinder::JsonTree(loadAsset("alien.json"));
    po::SpritesheetRef mSpritesheet = po::Spritesheet::create(texture, json);
    po::SpritesheetAnimationRef mSpritesheetAnimation = po::SpritesheetAnimation::create(mSpritesheet);
    alien_spritesheetanim_vector.push_back(mSpritesheetAnimation);

    mSpritesheetAnimation->play();
    mSpritesheetAnimation->setIsLoopingEnabled(true);
    mSpritesheetAnimation->setFrameRate(4);
  }

  ci::gl::TextureRef texture_bullet = ci::gl::Texture::create(loadImage(loadAsset("playerbullet.png")));
  cinder::JsonTree json_bullet = cinder::JsonTree(loadAsset("playerbullet.json"));
  mSpritesheet_bullet = po::Spritesheet::create(texture_bullet, json_bullet);
  mSpritesheetAnimation_bullet = po::SpritesheetAnimation::create(mSpritesheet_bullet);
  mSpritesheetAnimation_bullet->play();
  mSpritesheetAnimation_bullet->setIsLoopingEnabled(true);
  mSpritesheetAnimation_bullet->setFrameRate(4);

  ci::gl::TextureRef texture_nyan_cat = ci::gl::Texture::create(loadImage(loadAsset("nyan_cat.png")));
  cinder::JsonTree json_nyan_cat = cinder::JsonTree(loadAsset("nyan_cat.json"));
  mSpritesheet_nyan_cat = po::Spritesheet::create(texture_nyan_cat, json_nyan_cat);
  mSpritesheetAnimation_nyan_cat = po::SpritesheetAnimation::create(mSpritesheet_nyan_cat);
  mSpritesheetAnimation_nyan_cat->play();
  mSpritesheetAnimation_nyan_cat->setIsLoopingEnabled(true);
  mSpritesheetAnimation_nyan_cat->setFrameRate(4);

  texture_player = ci::gl::Texture::create(loadImage(loadAsset("player.png")));
  texture_alien_bullet = ci::gl::Texture::create(loadImage(loadAsset("alien_bullet.png")));
}

void MyApp::update() {
  mFps = getAverageFps();
  mVideo1.update();

  const auto time = system_clock::now();
  if (time - last_time_alien > std::chrono::milliseconds(alien_speed)) {
    engine.AlienStep();
    last_time_alien = time;
  }
  if (time - last_time_nyan_cat > std::chrono::milliseconds(nyan_cat_speed)) {
    engine.NyanCatStep();
    last_time_nyan_cat = time;
  }
  if (time - last_time_player > std::chrono::milliseconds(player_speed)) {
    engine.PlayerStep();
    last_time_player = time;
  }
  if (time - last_time_projectile > std::chrono::milliseconds(projectile_speed)) {
    engine.PlayerProjectileStep();
    engine.AlienProjectileStep();
    last_time_projectile = time;
  }

  for (po::SpritesheetAnimationRef alien_anim : alien_spritesheetanim_vector) {
    alien_anim->update();
  }
  mSpritesheetAnimation_bullet->update();
  mSpritesheetAnimation_nyan_cat->update();
}

void MyApp::draw() {
  cinder::gl::clear();
  //mVideo1.draw( 0, 0, 800, 800 );
  //mParams->draw();
  DrawPlayer();
  DrawPlayerProjectile();
  DrawAlienWave();
  DrawAlienProjectile();
  DrawNyanCat();
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_LEFT: {
      engine.SetDirection(space_invader::Action::kLeft);
      break;
    }
    case KeyEvent::KEY_RIGHT: {
      engine.SetDirection(space_invader::Action::kRight);
      break;
    }
    case KeyEvent::KEY_SPACE: {
      engine.SetProjectileDirection(space_invader::Action::kShoot);
      break;
    }
  }
}

void MyApp::keyUp(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_LEFT: {
      engine.SetDirection(space_invader::Action::kStop);
      break;
    }
    case KeyEvent::KEY_RIGHT: {
      engine.SetDirection(space_invader::Action::kStop);
      break;
    }
    case KeyEvent::KEY_SPACE: {
      engine.SetProjectileDirection(space_invader::Action::kShoot);
      break;
    }
  }
}

void MyApp::DrawNyanCat() {
  space_invader::Location nyan_loc = engine.GetNyanCat().GetLocation();
  int x = nyan_loc.Row();
  int y = nyan_loc.Col();
  mPos = ci::vec2(x * kTileSize, y * kTileSize);
  ci::gl::pushModelView();
  ci::vec2 val = mPos.value();
  ci::gl::translate(val.x, val.y);
  mSpritesheetAnimation_nyan_cat -> draw();
  ci::gl::popModelView();
}


void MyApp::DrawPlayerProjectile() {
  if (engine.GetProjectile()->IsVisibile() == false) {
    return;
  }
  space_invader::Location player_projectile_loc = engine.GetProjectile()->GetLocation();
  int x = player_projectile_loc.Row();
  int y = player_projectile_loc.Col();
  mPos = ci::vec2(x * kTileSize, y * kTileSize);
  ci::gl::pushModelView();
  ci::vec2 val = mPos.value();
  ci::gl::translate(val.x, val.y);
  mSpritesheetAnimation_bullet -> draw();
  ci::gl::popModelView();
}

void MyApp::DrawPlayer() {
  if (engine.GetPlayer().IsVisibile() == false) {
    return;
  }
  space_invader::Location player_loc = engine.GetPlayer().GetLocation();
  cinder::vec2 player_location = cinder::vec2(player_loc.Row() * kTileSize, player_loc.Col() * kTileSize);
  ci::gl::draw(texture_player, player_location);
}

void MyApp::DrawAlienProjectile() {
  space_invader::Location alien_projectile_loc = engine.GetAlienProjectile()->GetLocation();
  cinder::vec2 alien_projectile_location = cinder::vec2(alien_projectile_loc.Row() * kTileSize, alien_projectile_loc.Col() * kTileSize);
  ci::gl::draw(texture_alien_bullet, alien_projectile_location);
}


void MyApp::DrawAlienWave(){
  for (po::SpritesheetAnimationRef alien_anim : alien_spritesheetanim_vector) {
    space_invader::Location alien_loc = engine.GetAlienWave().GetAlienth(alien_count).GetLocation();
    int x = alien_loc.Row();
    int y = alien_loc.Col();
    mPos = ci::vec2(x * kTileSize, y * kTileSize);
    ci::gl::pushModelView();
    ci::vec2 val = mPos.value();
    ci::gl::translate(val.x, val.y);
    if (engine.GetAlienWave().GetAlienth(alien_count).IsVisibile() == true) {
      alien_anim->draw();
    }
    alien_count++;
    ci::gl::popModelView();
    if (alien_count == alien_spritesheetanim_vector.size()) {
      alien_count = 0;
    }
  }
}
}  // namespace myapp
