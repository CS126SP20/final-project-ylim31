//
// Created by Josh on 4/22/2020.
//

#include "engine.h"

#include <iostream>
#include <vector>
#include <random>

#include "alien.h"
#include "direction.h"
#include "projectile.h"

namespace space_invader {
Engine::Engine():
player(Location(6,15)),
direction_{Direction::kStop},
direction_projectile{Direction::kStop},
direction_alien_projectile{Direction::kShoot}{
  //aliens = new Alien(alien_wave.Head().GetLocation());
  projectile = new Projectile(player.GetLocation());



}


AlienWave Engine::GetAlienWave() const {
  return alien_wave;
}
Player Engine::GetPlayer() const {
  return player;
}
Projectile* Engine::GetProjectile() const {
  return projectile;
}
Projectile* Engine::GetAlienProjectile() const {
  return alien_projectile;
}

void Engine::PlayerStep() {
  Location player_location = MovePlayer(direction_);
  Location new_player_loc =
      (player.GetLocation() + player_location) % Location(height, width);
  player.SetLocation(new_player_loc);
  if (direction_projectile != Direction::kShoot) {
    Location scaled(player.GetLocation().Row(), player.GetLocation().Col());
    projectile->SetLocation(scaled);
  }
}

//shoot method that sets the prokectile location. when space bar is press, call in myapp
void Engine::ProjectileStep() {
  if (direction_projectile == Direction::kShoot) {
    Location projectile_location = MoveProjectile();
    Location new_projectile_loc =
        (projectile->GetLocation() + projectile_location);
    projectile->SetLocation(new_projectile_loc);
    projectile_distance++;
    for (Alien& alien : alien_wave) {
      if (alien.GetLocation() == projectile->GetLocation() && alien.IsVisibile()) {
        delete projectile;
        alien.SetVisibility(false);
        Projectile* new_projectile = new Projectile(player.GetLocation());
        projectile = new_projectile;
        direction_projectile = Direction::kReload;
        projectile_distance = 0;
      }
    }
    if (projectile_distance == 16) {
      delete projectile;
      Projectile* new_projectile = new Projectile(player.GetLocation());
      projectile = new_projectile;
      direction_projectile = Direction::kReload;
      projectile_distance = 0;
    }
  }


  Location projectile_location = MoveAlienProjectile();
  Location new_projectile_loc =
      (alien_projectile->GetLocation() + projectile_location);
  alien_projectile->SetLocation(new_projectile_loc);

  alien_projectile_distance++;




  if (alien_projectile_distance == 16) {
    int random_int = std::rand()%6;
    int shoot_row = 2;
    //delete alien_projectile;
    for (int i = 0; i < 3; i++) {
      if (alien_wave.GetAlien(shoot_row, random_int).IsVisibile() == false) {
        shoot_row--;

      }
    }
    alien_projectile_distance = 12;
    if (shoot_row != -1) {
      delete alien_projectile;
      Projectile* new_alien_projectile = new Projectile(alien_wave.GetAlien(shoot_row, random_int).GetLocation());
      alien_projectile = new_alien_projectile;
      alien_projectile_distance = 0;
    }


    //direction_alien_projectile = Direction::kReload;


  }
  /*

  if (alien_projectile->GetLocation() == player.GetLocation()) {
    //delete alien_projectile;
    player.SetVisibility(false);
    //direction_alien_projectile = Direction::kReload;
  }
   */
  /*
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {

      //Location location(j * 2, i * 2);
      //aliens = new Alien(location);

      if (i == 2 && j == random_position) {

      }
    }

  }
   */

}

void Engine::Step() {
  //Location player_location(4, 4);
  //Location location(1, 1);
  //alien_wave.FillWave(Alien(location));
    //magic number
  if (isFirst == true) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 6; j++) {

        Location location(j * 2, i * 2);
        //aliens = new Alien(location);
        alien_wave.FillWave(Alien(location));

      }

    }


    alien_projectile = new Projectile(alien_wave.GetAlien(2, 1).GetLocation());
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
Location Engine::MoveProjectile() {
  if (direction_projectile == Direction::kShoot) {
    return {0, -1};
  }
  return {0, 0};
}

Location Engine::MoveAlienProjectile() {
    return {0, +1};
}



Location Engine::MovePlayer(const Direction direction) {
  if (direction == Direction::kRight) {
    return {+1, 0};
  } else if (direction == Direction::kLeft) {
    return {-1, 0};
  }
  return {0,0};
}
void Engine::SetDirection(const space_invader::Direction direction) {
  direction_ = direction;
}

void Engine::SetProjectileDirection(const space_invader::Direction direction) {
  direction_projectile = direction;
}

}
