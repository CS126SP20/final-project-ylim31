//
// Created by Josh on 4/22/2020.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <vector>

#include "alien_wave.h"
#include "direction.h"
#include "player.h"
#include "projectile.h"
namespace space_invader {
class Engine {
 public:
  Engine::Engine();
  AlienWave GetAlienWave() const;
  Player Engine::GetPlayer() const;
  Projectile* Engine::GetProjectile() const;


  Location Engine::MoveAlienWave(bool toRight, int count);
  Location Engine::MovePlayer(const Direction direction);
  Location Engine::MoveProjectile();
  void Engine::ReloadProjectile();



  void Step();
  void PlayerStep();
  void ProjectileStep();



  // Changes the direction of the player for the next time step.
  void SetDirection(Direction);
  void Engine::SetProjectileDirection(const space_invader::Direction direction);



 private:
  AlienWave alien_wave;
  int height = 16;
  int width = 16;
  Direction direction_;
  Direction direction_projectile;
  Player player;
  Projectile* projectile;
  bool isFirst = true;
  int count = 0;
  int projectile_distance = 0;
  int first_shot = 0;
  bool toRight = true;

  Projectile copy_projectile;

  bool isShot = false;

};
}


#endif  // FINALPROJECT_ENGINE_H
