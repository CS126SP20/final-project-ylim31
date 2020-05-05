//
// Created by Josh on 5/4/2020.
//

#ifndef FINALPROJECT_NYAN_CAT_H
#define FINALPROJECT_NYAN_CAT_H

#include "location.h"
#include "nyan_cat.h"
namespace space_invader {
class NyanCat {
 public:
  explicit NyanCat(const Location& location);
  Location GetLocation() const;
  Location SetLocation(const Location&);
  void SetVisibility(bool visible);
  bool IsVisibile() const;
 private:
  Location location_;
  bool visible_;
};
}


#endif  // FINALPROJECT_NYAN_CAT_H
