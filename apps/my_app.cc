// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include "../src/alien.h"
#include <cinder/app/App.h>
#include "ciWMFVideoPlayer.h"

namespace myapp {
using cinder::Rectf;
using cinder::app::KeyEvent;

MyApp::MyApp()
//: engine(10, 10),
: alien_size(50){ }

void MyApp::setup() {
  engine.Step();
}

void MyApp::update() {

}

void MyApp::draw() {
  DrawAlienWave();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::DrawAlienWave() const{
  for (const space_invader::Alien& alien : engine.GetAlienWave()) {
    space_invader::Location loc = alien.GetLocation();
    cinder::gl::drawSolidRect(Rectf(alien_size * loc.Row(),
                                    alien_size * loc.Col(),
                                    alien_size * loc.Row() + alien_size,
                                    alien_size * loc.Col() + alien_size));
  }
}

}  // namespace myapp
