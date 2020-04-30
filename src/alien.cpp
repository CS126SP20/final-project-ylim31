//
// Created by Josh on 4/21/2020.
//

#include "alien.h"
#include "location.h"

namespace space_invader {
Alien::Alien(const Location& location)
    : location_(location), visible_{true} {}

//copy constructor
Location Alien::GetLocation() const { return location_; }

Location Alien::SetLocation(const Location& location) {
  location_ = location;
  return location_;
}

void Alien::SetVisibility(bool visible) { visible_ = visible; }

bool Alien::IsVisibile() const { return visible_; }

void Alien::Clear() {
  delete this;
}




}
