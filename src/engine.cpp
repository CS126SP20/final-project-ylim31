//
// Created by Josh on 4/22/2020.
//

#include "engine.h"
#include "alien.h"
#include "direction.h"

namespace space_invader {
Engine::Engine():
player(Location(6,15)),
direction_{Direction::kDown}{}
AlienWave Engine::GetAlienWave() const {
  return alien_wave;
}
Player Engine::GetPlayer() const {
  return player;
}
void Engine::PlayerStep() {
  Location player_location = MovePlayer(direction_);
  Location new_player_loc =
      (player.GetLocation() + player_location) % Location(height, width);;
  player.SetLocation(new_player_loc);
}
void Engine::Step() {
  //Location player_location(4, 4);


  //Location location(1, 1);
  //alien_wave.FillWave(Alien(location));
    //magic number
  if (isFirst == true) {
    for (int i = 0; i < width - 5; i++) {
      if (i % 2 == 0) {

        Location location(i, 0);
        alien_wave.FillWave(Alien(location));
      }
    }
    isFirst = false;
  }

 for (Alien& alien : alien_wave) {
   //alien_wave.ClearWave();
   //alien.SetVisibility(0);
   Location d_loc = MoveAlienWave(toRight, count);
   Location new_alien_loc = (alien.GetLocation() + d_loc);
   alien.SetLocation(new_alien_loc);
 }
  count++;
  if (count == 6) {
    toRight = !toRight;
    count = 0;
  }
}
Location Engine::MoveAlienWave(bool toRight, int count) {
  if (toRight == false && count == 0) {
    return {0, +1};
  } else if (toRight == true && count == 0) {
    return {0, +1};
  } else if (toRight == true) {
    return {+1, 0};
  }
  return {-1, 0};
}

Location Engine::MovePlayer(const Direction direction) {
  if (direction == Direction::kRight) {
    return {+1, 0};
  } else if (direction == Direction::kLeft) {
    return {-1, 0};
  } else if (direction == Direction::kDown) {
    return {0,0};
  }
  return {0,0};
}
void Engine::SetDirection(const space_invader::Direction direction) {
  direction_ = direction;
}
}
