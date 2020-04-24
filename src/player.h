//
// Created by Josh on 4/23/2020.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include "location.h"
namespace space_invader {
  class Player {
   public:
    explicit Player(const Location& location);
    Location GetLocation() const;
    Location SetLocation(const Location&);
    void SetVisibility(bool visible);
    bool IsVisibile() const;
   private:
    Location location_;
    bool visible_;
  };
}

#endif  // FINALPROJECT_PLAYER_H
