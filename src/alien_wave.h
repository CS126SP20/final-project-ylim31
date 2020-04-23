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
    //AlienWave();
    //add alien to the wave
    void FillWave(const Alien&);
    std::deque<Alien>::iterator begin();
    std::deque<Alien>::iterator end();
    Alien Tail() const;
   private:
    std::deque<Alien> wave;
  };
}


#endif  // FINALPROJECT_ALIEN_WAVE_H
