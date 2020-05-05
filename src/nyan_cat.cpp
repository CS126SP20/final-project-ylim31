//
// Created by Josh on 5/4/2020.
//

#include "nyan_cat.h"
#include "location.h"

namespace space_invader {
NyanCat::NyanCat(const Location& location) : location_(location), visible_(true) {}
Location NyanCat::GetLocation() const { return location_;
}
Location NyanCat::SetLocation(const Location& location) {
  location_ = location;
  return location_;
}
void NyanCat::SetVisibility(bool visible) { visible_ = visible; }

bool NyanCat::IsVisibile() const { return visible_; }
}
