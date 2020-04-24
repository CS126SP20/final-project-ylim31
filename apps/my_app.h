// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include "../src/engine.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  void DrawAlienWave() const;
  void DrawPlayer() const;
  space_invader::Engine engine;
  const size_t alien_size = 50;
  const size_t speed = 1000;
  std::chrono::time_point<std::chrono::system_clock> last_time;


};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
