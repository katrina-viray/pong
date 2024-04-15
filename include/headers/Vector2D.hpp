#pragma once
#include <iostream>
#include <ostream>

class Vector2D{
public:
  float x;
  float y;

  Vector2D();
  Vector2D(float x, float y);

  // functions will return a reference to the newly made vector.
  // uses const and & in param because we only want to read off the vector input
  Vector2D& Add(const Vector2D& vec);
  Vector2D& Subtract(const Vector2D& vec);
  Vector2D& Multiply(const Vector2D& vec);
  Vector2D& Divide(const Vector2D& vec);

  // operator overloads; friend functions aren't members of a class but
  // have access to private/protected members of the class
  friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

  Vector2D& operator+=(const Vector2D& vec);
  Vector2D& operator-=(const Vector2D& vec);
  Vector2D& operator*=(const Vector2D& vec);
  Vector2D& operator/=(const Vector2D& vec);

  Vector2D& operator*(const int& i);
  Vector2D& Zero();

  friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};