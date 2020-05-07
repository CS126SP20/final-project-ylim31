//
// Created by Josh on 4/22/2020.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <vector>

#include "Action.h"
#include "alien_wave.h"
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
  int Engine::GetScore() const;
  int Engine::GetHighScore() const;

  void AlienStep();
  void PlayerStep();
  void PlayerProjectileStep();
  void AlienProjectileStep();
  void NyanCatStep();

  void Engine::SetUpWave();
  void SetDirection(const Action);
  void Engine::SetProjectileDirection(const Action);

  Location Engine::MoveAlienWave(bool toRight, int count_to_border);
  Location Engine::MovePlayer();
  Location Engine::MoveProjectile();
  Location Engine::MoveAlienProjectile();
  Location Engine::MoveNyanCat();

  void Engine::ResetGame();
  void Engine::NextWave();
  Location Engine::GetInitialAlienPosition(int n);
 private:
  AlienWave alien_wave;
  Player player;
  NyanCat nyan_cat;
  Projectile* player_projectile;
  Projectile* alien_projectile;


  Action action_player;
  Action action_player_projectile;
  Action action_alien_projectile;
  Action action_nyan_cat;

  int count_to_border = 0;
  int projectile_distance = 0;
  int alien_projectile_distance = 0;
  int nyan_cat_distance = 0;
  int score = 0;
  int high_score = 0;
  int spawn_nyan_cat = 0;
  int random_nyan_spawn = std::rand() % 40 + 18;
  bool toRight = true;

  int kDistanceToOppositeBorder = 16;
  int kDimension = 48;
  int kNumberOfRows = 3;
  int kNumberOfCols = 6;
};
}


#endif  // FINALPROJECT_ENGINE_H
