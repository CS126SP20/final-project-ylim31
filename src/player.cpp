//
// Created by Josh on 4/23/2020.
//

#include "player.h"

namespace space_invader {
Player::Player(const Location& location)
    : location_(location), visible_{true} {}

//copy constructor
Location Player::GetLocation() const { return location_; }
Location Player::SetLocation(const Location& location) {
  location_ = location;
  return location_;
}
void Player::SetVisibility(bool visible) { visible_ = visible; }

bool Player::IsVisibile() const { return visible_; }
}