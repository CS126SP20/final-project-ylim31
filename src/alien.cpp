//
// Created by Josh on 4/21/2020.
//

#include "alien.h"

namespace space_invader {
Segment::Segment(const Location& location)
    : location_(location), visible_{true} {}

Location Segment::GetLocation() const { return location_; }

Location Segment::SetLocation(const Location& location) {
  location_ = location;
  return location_;
}

void Segment::SetVisibility(bool visible) { visible_ = visible; }

bool Segment::IsVisibile() const { return visible_; }
}
