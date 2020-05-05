//
// Created by Josh on 4/21/2020.
//

#ifndef FINALPROJECT_LOCATION_H
#define FINALPROJECT_LOCATION_H

#include <iosfwd>
namespace space_invader {

// Represents a location on the board.
class Location {
 public:
  Location(double row, double col);

  // Comparison operators.
  bool operator()(const Location& lhs, const Location& rhs) const;
  bool operator==(const Location& rhs) const;
  bool operator!=(const Location& rhs) const;
  bool operator<(const Location& rhs) const;
  bool operator<=(const Location& rhs) const;
  bool operator>(const Location& rhs) const;
  bool operator>=(const Location& rhs) const;

  // Vector operators.
  Location operator+(const Location& rhs) const;
  // Note: Always returns positive coordinates.
  Location operator%(const Location& rhs) const;
  Location operator-(const Location& rhs) const;
  Location& operator+=(const Location& rhs);
  Location operator-() const;


  // Accessors.
  double Row() const;
  double Col() const;

 private:
  double row_;
  double col_;
};

}

#endif  // FINALPROJECT_LOCATION_H
