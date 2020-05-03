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
  engine.SetUpWave();
  for (const space_invader::Alien& alien : engine.GetAlienWave()) {


    ci::gl::TextureRef texture = ci::gl::Texture::create(loadImage(loadAsset("alien.png")));
    cinder::JsonTree json = cinder::JsonTree(loadAsset("alien.json"));
    po::SpritesheetRef mSpritesheet = po::Spritesheet::create(texture, json);
    po::SpritesheetAnimationRef mSpritesheetAnimation = po::SpritesheetAnimation::create(mSpritesheet);
    alien_vector.push_back(mSpritesheetAnimation);



    mPos_vector.push_back(mPos);
    mEndPos_vector.push_back(mEndPos);





      mSpritesheetAnimation->play();
    mSpritesheetAnimation->setIsLoopingEnabled(true);
    mSpritesheetAnimation->setFrameRate(8);
    //timeline().apply(&mPos, mEndPos, 10.0f).loop();

  }
  /*
    space_invader::Location loc = alien.GetLocation();
    int x = loc.Row();
    int y = loc.Col();
    */


  std::cout<<alien_vector.size()<<std::endl;



    //mSpritesheetAnimation->setIsLoopingEnabled(true);











  /*
  ci::gl::TextureRef texture = ci::gl::Texture::create(loadImage(loadAsset("alien.png")));
  cinder::JsonTree json = cinder::JsonTree(loadAsset("alien.json"));
  mSpritesheet = po::Spritesheet::create(texture, json);

  std::cout<<mSpritesheet->getOriginalBounds().x1 << std::endl;
  std::cout<<mSpritesheet->getOriginalBounds().x2 << std::endl;
  std::cout<<mSpritesheet->getOriginalBounds().y1 << std::endl;
  std::cout<<mSpritesheet->getOriginalBounds().y2 << std::endl;

  mSpritesheetAnimation = po::SpritesheetAnimation::create(mSpritesheet);
  mSpritesheetAnimation->setIsLoopingEnabled(true);
  mSpritesheetAnimation->play();
   */


}

void MyApp::update() {
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
  //std::cout<<engine.GetAlienWave().getSize()<<std::endl;
  for (po::SpritesheetAnimationRef a : alien_vector) {
      a->update();

  }

}

void MyApp::draw() {
  cinder::gl::clear();
  DrawAlienWave();
  DrawPlayer();
  DrawProjectile();


  //int i = 0;

  for (po::SpritesheetAnimationRef a : alien_vector) {

    //space_invader::Location loc = engine.GetAlienWave().GetAlienth(i).GetLocation();
      space_invader::Location loc = engine.GetAlienWave().GetAlienth(index).GetLocation();


      int x = loc.Row();
      int y = loc.Col();
      mPos = ci::vec2(x * 50, y * 50);
      mEndPos = ci::vec2(x+50, y);


    ci::gl::pushModelView();

    ci::vec2 val = mPos.value();
    index++;

    ci::gl::translate(val.x, val.y);
    a->draw();

    ci::gl::popModelView();
    if (index == alien_vector.size()) {
        index = 0;
    }

  }


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
      break;
    }

  }
}
void MyApp::DrawProjectile() const {
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

void MyApp::DrawAlienWave() const{
  //ci::gl::clear(Color::gray(0.2));
  for (const space_invader::Alien& alien : engine.GetAlienWave()) {
    if (alien.IsVisibile() == false) {
      continue;
    }


    space_invader::Location loc = alien.GetLocation();

    /*
    ci::gl::pushModelView();
    std::cout << mPos.value() << std::endl;
    ci::vec2 val = mPos.value();

    ci::gl::translate(val.x, val.y);
    mSpritesheetAnimation->draw();
    ci::gl::popModelView();
     */



    //space_invader::Location loc = alien.GetLocation();
    cinder::gl::drawSolidRect(Rectf(alien_size * loc.Row(),
                                    alien_size * loc.Col(),
                                    alien_size * loc.Row() + alien_size,
                                    alien_size * loc.Col() + alien_size));
  }
  //std::cout<<engine.GetAlienWave().getSize()<<std::endl;
}

}  // namespace myapp
