//
// Created by Josh on 4/22/2020.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include "alien_wave.h"
namespace space_invader {
class Engine {
 public:
  AlienWave GetAlienWave() const;
  //Engine(int width, int height);
  void Step();
 private:
  AlienWave alien_wave;

};
}


#endif  // FINALPROJECT_ENGINE_H
