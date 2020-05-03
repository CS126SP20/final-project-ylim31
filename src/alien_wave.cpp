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
Alien AlienWave::GetAlien(int row, int col) {
  int n = (row * 6) + col;
  return wave.at(n);
}
Alien AlienWave::GetAlienth(int index) {
  return wave.at(index);
}
int AlienWave::getSize() {
  return wave.size();
}
std::deque<Alien>::iterator AlienWave::begin() { return wave.begin(); }
std::deque<Alien>::iterator AlienWave::end() { return wave.end(); }

void AlienWave::ClearWave() {
    for (Alien& alien : wave) {
      alien.SetVisibility(0);
    }
  }
}