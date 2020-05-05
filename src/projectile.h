//
// Created by Josh on 4/25/2020.
//

#ifndef FINALPROJECT_PROJECTILE_H
#define FINALPROJECT_PROJECTILE_H
#include "location.h"

namespace space_invader {
  class Projectile {
   public:
    explicit Projectile(const Location& location);
    Location GetLocation() const;
    Location SetLocation(const Location&);
    void SetVisibility(bool visible);
    bool IsVisibile() const;
   private:
    Location location_;
    bool visible_;
  };
}


#endif  // FINALPROJECT_PROJECTILE_H
