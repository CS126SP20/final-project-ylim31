//
// Created by Josh on 4/22/2020.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <vector>

#include "alien_wave.h"
#include "direction.h"
#include "nyan_cat.h"
#include "player.h"
#include "projectile.h"
namespace space_invader {
class Engine {
 public:
  Engine::Engine();
  AlienWave GetAlienWave() const;
  Player Engine::GetPlayer() const;
  Projectile* Engine::GetProjectile() const;
  Projectile* Engine::GetAlienProjectile() const;
  NyanCat Engine::GetNyanCat() const;



  Location Engine::MoveAlienWave(bool toRight, int count);
  Location Engine::MovePlayer(const Direction direction);
  Location Engine::MoveProjectile();
  Location Engine::MoveAlienProjectile();
  Location Engine::MoveNyanCat(const Direction direction);

  void Step();
  void PlayerStep();
  void ProjectileStep();
  void Engine::SetUpWave();
  void NyanCatStep();

  // Changes the direction of the player for the next time step.
  void SetDirection(Direction);
  void Engine::SetProjectileDirection(const space_invader::Direction direction);

 private:
  AlienWave alien_wave;
  int height = 16;
  int width = 16;
  Direction direction_;
  Direction direction_projectile;
  Direction direction_alien_projectile;
  Direction direction_nyan_cat;
  Player player;
  NyanCat nyan_cat;
  Projectile* projectile;
  Projectile* alien_projectile;
  int count = 0;
  int projectile_distance = 0;
  int alien_projectile_distance = 0;
  bool toRight = true;
  int show_nyan = 0;





};
}


#endif  // FINALPROJECT_ENGINE_H
