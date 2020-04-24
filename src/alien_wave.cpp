//
// Created by Josh on 4/22/2020.
//
#include <algorithm>
#include "alien_wave.h"
namespace space_invader {

  void AlienWave::FillWave(const space_invader::Alien& alien) {
    wave.push_back(alien);
  }
std::deque<Alien>::iterator AlienWave::begin() { return wave.begin(); }
std::deque<Alien>::iterator AlienWave::end() { return wave.end(); }
Alien AlienWave::Tail() const { return wave.back(); }
void AlienWave::ClearWave() {
    for (Alien& alien : wave) {
      alien.SetVisibility(0);
    }
  }
}