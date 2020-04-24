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

}

void MyApp::update() {
  const auto time = system_clock::now();
  if (time - last_time > std::chrono::milliseconds(speed)) {
    engine.Step();
    last_time = time;
    engine.GetAlienWave().ClearWave();
  }


}

void MyApp::draw() {
  DrawAlienWave();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::DrawAlienWave() const{
  for (const space_invader::Alien& alien : engine.GetAlienWave()) {
    space_invader::Location loc = alien.GetLocation();
    if (alien.IsVisibile()) {

    } else {
      cinder::gl::color(Color(0, 0, 0));
    }
    cinder::gl::drawSolidRect(Rectf(alien_size * loc.Row(),
                                    alien_size * loc.Col(),
                                    alien_size * loc.Row() + alien_size,
                                    alien_size * loc.Col() + alien_size));
  }
}

}  // namespace myapp
