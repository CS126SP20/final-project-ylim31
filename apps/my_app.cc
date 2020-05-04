// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include "../src/alien.h"
#include <cinder/app/App.h>
#include "ciWMFVideoPlayer.h"
#include "cinder/gl/gl.h"
#include "poScene/SpriteView.h"
//#include "SpriteSheet.h"
//#include




namespace myapp {
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::app::KeyEvent;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

MyApp::MyApp()
: alien_size(50){ }

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
    alien_vector.push_back(mSpritesheetAnimation);

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
  mSpritesheetAnimation_bullet->setFrameRate(10);

  ci::gl::TextureRef texture_alien_bullet = ci::gl::Texture::create(loadImage(loadAsset("alienbullet.png")));
  cinder::JsonTree json_alien_bullet = cinder::JsonTree(loadAsset("alienbullet.json"));
  mSpritesheet_alien_bullet = po::Spritesheet::create(texture_alien_bullet, json_alien_bullet);
  mSpritesheetAnimation_alien_bullet = po::SpritesheetAnimation::create(mSpritesheet_alien_bullet);
  mSpritesheetAnimation_alien_bullet->play();
  mSpritesheetAnimation_alien_bullet->setIsLoopingEnabled(true);
  mSpritesheetAnimation_alien_bullet->setFrameRate(10);
}

void MyApp::update() {
  mFps = getAverageFps();
  mVideo1.update();
  const auto time = system_clock::now();
  if (time - last_time > std::chrono::milliseconds(speed)) {
    engine.Step();
    last_time = time;
  }
  if (time - last_time_player > std::chrono::milliseconds(speed_player)) {
    engine.PlayerStep();
    last_time_player = time;
  }
  if (time - last_time_projectile > std::chrono::milliseconds(speed_projectile)) {
    engine.ProjectileStep();
    last_time_projectile = time;

  }
  for (po::SpritesheetAnimationRef a : alien_vector) {
    a->update();
  }
  mSpritesheetAnimation_bullet->update();
  mSpritesheetAnimation_alien_bullet->update();

}

void MyApp::draw() {
  cinder::gl::clear();
   // mVideo1.draw( 0, 0, 800, 800 );
    //mParams->draw();
    //DrawAlienWave();
  DrawPlayer();
  DrawProjectile();
  DrawAlienWave();
  DrawAlienProjectile();


}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_LEFT: {
      engine.SetDirection(space_invader::Direction::kLeft);
      break;
    }
    case KeyEvent::KEY_RIGHT: {
      engine.SetDirection(space_invader::Direction::kRight);
      break;
    }
    case KeyEvent::KEY_SPACE: {
      engine.SetProjectileDirection(space_invader::Direction::kShoot);
      isSpace = true;
      break;
    }
  }
}
void MyApp::keyUp(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_LEFT: {
      engine.SetDirection(space_invader::Direction::kStop);
      break;
    }
    case KeyEvent::KEY_RIGHT: {
      engine.SetDirection(space_invader::Direction::kStop);
      break;
    }

    case KeyEvent::KEY_SPACE: {
      engine.SetProjectileDirection(space_invader::Direction::kShoot);
      //isSpace = false;
      break;
    }

  }
}
void MyApp::DrawAlienProjectile() {

  space_invader::Location loc = engine.GetAlienProjectile()->GetLocation();
  int x = loc.Row();
  int y = loc.Col();

  alien_bullet_mPos = ci::vec2((x * 50) +50/3, y * 50);
  alien_bullet_mEndPos = ci::vec2(x, y - 50);
  ci::gl::pushModelView();

  ci::vec2 val = alien_bullet_mPos.value();

  ci::gl::translate(val.x, val.y);


  mSpritesheetAnimation_alien_bullet -> draw();
  ci::gl::popModelView();

}
void MyApp::DrawProjectile() {
  if (engine.GetProjectile()->IsVisibile() == false) {
    return;
  }
  /*
  if (engine.GetPlayer().IsVisibile() == false) {
    return;
  }
    space_invader::Location loc = engine.GetProjectile()->GetLocation();
    cinder::gl::drawSolidRect(Rectf(alien_size * loc.Row() + projectile_size,
                                    alien_size * loc.Col(),
                                    alien_size * loc.Row() + alien_size - projectile_size,
                                    alien_size * loc.Col() + alien_size - (2 * projectile_size)));

    space_invader::Location alien_loc = engine.GetAlienProjectile()->GetLocation();
    cinder::gl::drawSolidRect(Rectf(alien_size * alien_loc.Row() + projectile_size,
                                  alien_size * alien_loc.Col() + (2 * projectile_size),
                                  alien_size * alien_loc.Row() + alien_size - projectile_size,
                                  alien_size * alien_loc.Col() + alien_size));
                                  */
  space_invader::Location loc = engine.GetProjectile()->GetLocation();
  int x = loc.Row();
  int y = loc.Col();

  mPos = ci::vec2((x * 50) +50/3, y * 50);
  mEndPos = ci::vec2(x, y + 50);
  ci::gl::pushModelView();

  ci::vec2 val = mPos.value();

  ci::gl::translate(val.x, val.y);


  mSpritesheetAnimation_bullet -> draw();
  ci::gl::popModelView();


}
void MyApp::DrawPlayer() const {
  if (engine.GetPlayer().IsVisibile() == false) {
    return;
  }
  space_invader::Location loc = engine.GetPlayer().GetLocation();
  cinder::gl::drawSolidRect(Rectf(alien_size * loc.Row(),
                                  alien_size * loc.Col(),
                                  alien_size * loc.Row() + alien_size,
                                  alien_size * loc.Col() + alien_size));
}

void MyApp::DrawAlienWave(){
  for (po::SpritesheetAnimationRef a : alien_vector) {

    space_invader::Location loc = engine.GetAlienWave().GetAlienth(index).GetLocation();

    int x = loc.Row();
    int y = loc.Col();
    mPos = ci::vec2(x * 50, y * 50);
    mEndPos = ci::vec2(x+50, y);

    ci::gl::pushModelView();

    ci::vec2 val = mPos.value();

    ci::gl::translate(val.x, val.y);
    if (engine.GetAlienWave().GetAlienth(index).IsVisibile() == true) {
      a->draw();
    }
    index++;
    ci::gl::popModelView();
    if (index == alien_vector.size()) {
      index = 0;
    }

  }

}

}  // namespace myapp
