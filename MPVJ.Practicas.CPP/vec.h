#pragma once

#include <iostream>

struct Vec2 {
  float x = 0.f;
  float y = 0.f;

  Vec2(const float &x = 0.f, const float &y = 0.f);
  Vec2(Vec2 &_rhs);
  Vec2(const Vec2 &_rhs);
  Vec2(Vec2 &&_rhs) noexcept;

  float Magnitude() const;
  float MagnitudeSq() const;
  Vec2 Normalized() const;
  float AngleDeg() const;
  float AngleRad() const;

  Vec2 operator+(const Vec2 &_rhs) const;
  Vec2 operator-(const Vec2 &_rhs) const;
  Vec2 operator*(const float &_rhs) const;
  float operator*(const Vec2 &_rhs) const;
  Vec2 operator/(const float &_rhs) const;

  Vec2 &operator=(const Vec2 &_rhs);

  Vec2 &operator+=(const Vec2 &_rhs);
  Vec2 &operator-=(const Vec2 &_rhs);
  Vec2 &operator*=(const float &_rhs);
  Vec2 &operator/=(const float &_rhs);

  bool operator==(const Vec2 &_rhs) const;
  bool operator!=(const Vec2 &_rhs) const;

  static float Determinant(const Vec2 &a, const Vec2 &b);
  static float Dot(const Vec2 &a, const Vec2 &b);
  static Vec2 Hadamard(const Vec2 &a, const Vec2 &b);
  static float Angle(const Vec2 &a, const Vec2 &b);
  static float Distance(const Vec2 &a, const Vec2 &b);
  static Vec2 RotateAround(const float &angle, const Vec2 &a,
                           const Vec2 &axis = Vec2::Zero());

  static const Vec2 &Up();
  static const Vec2 &Down();
  static const Vec2 &Right();
  static const Vec2 &Left();
  static const Vec2 &Zero();
  static const Vec2 &One();

  friend std::ostream &operator<<(std::ostream &os, const Vec2 &a) {
    return os << '(' << a.x << ',' << a.y << ')';
  }
};

// struct vec3
//{
//     float x = 0;
//     float y = 0;
//     float z = 0;
//     vec3(const float &x = 0, const float &y = 0, const float &z = 0);
//     float magnitude() const;
//     vec3 normalized() const;
//     vec3 operator+(const vec3 &_rhs) const;
//     vec3 operator-(const vec3 &_rhs) const;
//     vec3 operator*(const float &_rhs) const;
//     vec3 operator/(const float &_rhs) const;
//     bool operator==(const vec3 &_rhs) const;
//     bool operator!=(const vec3 &_rhs) const;
//     friend std::ostream &operator<<(std::ostream &os, const vec3 &_rhs)
//     {
//         return os << '(' << _rhs.x << ',' << _rhs.y << ',' << _rhs.z << ')';
//     }
// };

struct Vec2i {
  int x = 0.f;
  int y = 0.f;

  Vec2i(const int &x = 0, const int &y = 0);
  Vec2i(Vec2i &_rhs);
  Vec2i(const Vec2i &_rhs);
  Vec2i(Vec2i &&_rhs) noexcept;

  Vec2i operator+(const Vec2i &_rhs) const;
  Vec2i operator-(const Vec2i &_rhs) const;
  Vec2i operator*(const int &_rhs) const;

  Vec2i &operator=(const Vec2i &_rhs);

  Vec2i &operator+=(const Vec2i &_rhs);
  Vec2i &operator-=(const Vec2i &_rhs);
  Vec2i &operator*=(const float &_rhs);

  bool operator==(const Vec2i &_rhs) const;
  bool operator!=(const Vec2i &_rhs) const;

  static Vec2i Hadamard(const Vec2i &a, const Vec2i &b);

  static const Vec2i &Up();
  static const Vec2i &Down();
  static const Vec2i &Right();
  static const Vec2i &Left();
  static const Vec2i &Zero();
  static const Vec2i &One();

  friend std::ostream &operator<<(std::ostream &os, const Vec2i &a) {
    return os << '(' << a.x << ',' << a.y << ')';
  }
};

// struct vec3i
//{
//     int x = 0;
//     int y = 0;
//     int z = 0;
//     vec3i(const int &x = 0, const int &y = 0, const int &z = 0);
//     float magnitude() const;
//     vec3 normalized() const;
//     vec3i operator+(const vec3i &_rhs) const;
//     vec3i operator-(const vec3i &_rhs) const;
//     vec3i operator*(const int &_rhs) const;
//     vec3 operator/(const int &_rhs) const;
//     vec3 operator*(const float &_rhs) const;
//     vec3 operator/(const float &_rhs) const;
//     bool operator==(const vec3i &_rhs) const;
//     bool operator!=(const vec3i &_rhs) const;
//     friend std::ostream &operator<<(std::ostream &os, const vec3i &_rhs)
//     {
//         return os << '(' << _rhs.x << ',' << _rhs.y << ',' << _rhs.z << ')';
//     }
// };
