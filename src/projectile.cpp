//
// Created by Josh on 4/25/2020.
//

#include "projectile.h"

namespace space_invader {
Projectile::Projectile(const Location& location)
    : location_(location), visible_{false} {}

Location Projectile::GetLocation() const { return location_; }

Location Projectile::SetLocation(const Location& location) {
  location_ = location;
  return location_;
}

void Projectile::SetVisibility(bool visible) { visible_ = visible; }

bool Projectile::IsVisibile() const { return visible_; }
}
