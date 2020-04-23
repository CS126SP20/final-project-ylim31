//
// Created by Josh on 4/21/2020.
//

#ifndef FINALPROJECT_ALIEN_H
#define FINALPROJECT_ALIEN_H

#include "location.h"
namespace space_invader {
// Represents an alien
class Alien {
 public:
  explicit Alien(const Location& location);
  Location GetLocation() const;
  Location SetLocation(const Location&);
  void SetVisibility(bool visible);
  bool IsVisibile() const;

  constexpr static float WIDTH = 48;
  constexpr static float HEIGHT = 32;
 private:
  Location location_;
  bool visible_;
};
}



#endif  // FINALPROJECT_ALIEN_H
