//
// Created by Josh on 4/22/2020.
//

#ifndef FINALPROJECT_ALIEN_WAVE_H
#define FINALPROJECT_ALIEN_WAVE_H

#include <deque>
#include "alien.h"
namespace space_invader {
  class AlienWave {

   public:
    void AlienWave::FillWave(const space_invader::Alien& alien);
    Alien AlienWave::GetAlien(int row, int col);
    std::deque<Alien>::iterator begin();
    std::deque<Alien>::iterator end();
    Alien AlienWave::GetAlienth(int index);
    int AlienWave::getSize();

    Alien* Tail() const;
    Alien* Head() const;
    void AlienWave::ClearWave();
   private:
    std::deque<Alien> wave;
    Alien* aliens;
  };
}


#endif  // FINALPROJECT_ALIEN_WAVE_H
