// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include "../src/alien.h"
#include <cinder/app/App.h>
#include "ciWMFVideoPlayer.h"

namespace myapp {
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::app::KeyEvent;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

MyApp::MyApp()
//: engine(10, 10),
: alien_size(50){ }

void MyApp::setup() {
  //printf("first");
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


  //std::cout << "first" << std::endl;


}

void MyApp::draw() {
  cinder::gl::clear();
  DrawAlienWave();
  DrawPlayer();
  //DrawProjectile();
 // if (isSpace) {
    DrawProjectile();
    //DrawAnother();
    // = !isSpace;
 // }
  //glclear
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
      //isSpace = true;
      //isFired = true;
      //engine.SetIsFired(isFired);
      //std::cout << "first" << std::endl;
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
  //for (auto projectile : engine.GetVectorProjectile()) {
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


  //}



}
/*
void MyApp::DrawAnother() const {
  space_invader::Location locs = engine.GetCopyProjectile().GetLocation();
  cinder::gl::drawSolidRect(Rectf(alien_size * locs.Row(),
                                  alien_size * locs.Col(),
                                  alien_size * locs.Row() + alien_size,
                                  alien_size * locs.Col() + alien_size));
}
 */
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
  for (const space_invader::Alien& alien : engine.GetAlienWave()) {
    if (alien.IsVisibile() == false) {
      continue;
    }
    space_invader::Location loc = alien.GetLocation();
    /*
    if (alien.IsVisibile()) {

    } else {
      cinder::gl::color(Color(0, 0, 0));
    }
     */
    cinder::gl::drawSolidRect(Rectf(alien_size * loc.Row(),
                                    alien_size * loc.Col(),
                                    alien_size * loc.Row() + alien_size,
                                    alien_size * loc.Col() + alien_size));
  }
}

}  // namespace myapp
