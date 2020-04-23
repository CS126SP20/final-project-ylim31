//
// Created by Josh on 4/22/2020.
//

#include "engine.h"
#include "alien.h"

namespace space_invader {
AlienWave Engine::GetAlienWave() const {
  return alien_wave;
}
void Engine::Step() {
  int new_row = 0;
  int new_col = 0;
  //Location location(1, 1);
 // alien_wave.FillWave(Alien(location));

  for (int i = 0; i < width - 5; i++) {
      if (i % 2 == 0) {
          new_col = i;
          Location location(i, 1);
          alien_wave.FillWave(Alien(location));
      }
  }


}
}
