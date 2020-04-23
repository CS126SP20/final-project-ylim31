//
// Created by Josh on 4/22/2020.
//

#include "engine.h"

namespace space_invader {
AlienWave Engine::GetAlienWave() const {
  return alien_wave;
}
void Engine::Step() {
  Alien alien = alien_wave.Tail();
  alien_wave.FillWave(alien);
}
}
