//
// Created by Josh on 4/22/2020.
//
#include <algorithm>
#include "alien_wave.h"
namespace space_invader {

  void AlienWave::FillWave(const space_invader::Alien& alien) {
    /*
    const int GAP = 10;
    for (int y = 0; y < 3; y++) {
      for (int x = 0; x < 5; x++) {
        // calcuate position for invader
        float invaderX = x * Alien::WIDTH + (GAP * x * 3) + Alien::WIDTH;
        float invaderY = y * Alien::HEIGHT + (GAP * y) + Alien::HEIGHT * 4;
        wave.push_back(alien);
      }
    }
     */
    /*
    for (int i = 0; i < 5; i++) {
      wave.push_back(alien);
    }
     */
    wave.push_back(alien);

  }
std::deque<Alien>::iterator AlienWave::begin() { return wave.begin(); }
std::deque<Alien>::iterator AlienWave::end() { return wave.end(); }
Alien AlienWave::Tail() const { return wave.back(); }
}