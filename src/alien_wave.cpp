//
// Created by Josh on 4/22/2020.
//
#include <algorithm>
#include <deque>
#include "alien_wave.h"
namespace space_invader {

void AlienWave::FillWave(const space_invader::Alien& alien) {
  wave.push_back(alien);

}
Alien AlienWave::GetAlien(int n) {
  return wave.at(n);
}
std::deque<Alien>::iterator AlienWave::begin() { return wave.begin(); }
std::deque<Alien>::iterator AlienWave::end() { return wave.end(); }

//std::deque<Alien>::iterator AlienWave::* { return wave.end(); }


void AlienWave::ClearWave() {
    for (Alien& alien : wave) {
      alien.SetVisibility(0);
    }
  }
}