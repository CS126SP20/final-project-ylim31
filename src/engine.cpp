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
  bool toRight = true;

  for (Alien& alien : alien_wave) {
    //alien_wave.ClearWave();
    //alien.SetVisibility(0);
    Location d_loc = MoveAlienWave(toRight);
    Location new_alien_loc = (alien.GetLocation() + d_loc);
    alien.SetLocation(new_alien_loc);
  }

}
Location Engine::MoveAlienWave(bool toRight) {
  if (toRight == true) {
    return {+1, 0};
  }
  return {-1, 0};
}
}
