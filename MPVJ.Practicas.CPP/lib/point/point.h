#pragma once

#include <iostream>

struct point
{
    float x = 0;
    float y = 0;
    point(const float &x = 0, const float &y = 0);
    float magnitude() const;
    point normalized() const;
    point operator+(const point &b) const;
    point operator-(const point &b) const;
    point operator*(const float &b) const;
    point operator/(const float &b) const;
    bool operator==(const point &b) const;
    bool operator!=(const point &b) const;
    friend std::ostream &operator<<(std::ostream &os, const point &b)
    {
        return os << '(' << b.x << ',' << b.y << ')';
    }
};

struct point3d
{
    float x = 0;
    float y = 0;
    float z = 0;
    point3d(const float &x = 0, const float &y = 0, const float &z = 0);
    float magnitude() const;
    point3d normalized() const;
    point3d operator+(const point3d &b) const;
    point3d operator-(const point3d &b) const;
    point3d operator*(const float &b) const;
    point3d operator/(const float &b) const;
    bool operator==(const point3d &b) const;
    bool operator!=(const point3d &b) const;
    friend std::ostream &operator<<(std::ostream &os, const point3d &b)
    {
        return os << '(' << b.x << ',' << b.y << ',' << b.z << ')';
    }
};

struct point_i
{
    int x = 0;
    int y = 0;
    point_i(const int &x = 0, const int &y = 0);
    float magnitude() const;
    point normalized() const;
    point_i operator+(const point_i &b) const;
    point_i operator-(const point_i &b) const;
    point_i operator*(const int &b) const;
    point operator/(const int &b) const;
    point operator*(const float &b) const;
    point operator/(const float &b) const;
    bool operator==(const point_i &b) const;
    bool operator!=(const point_i &b) const;
    friend std::ostream &operator<<(std::ostream &os, const point_i &b)
    {
        return os << '(' << b.x << ',' << b.y << ')';
    }
};

struct point3d_i
{
    int x = 0;
    int y = 0;
    int z = 0;
    point3d_i(const int &x = 0, const int &y = 0, const int &z = 0);
    float magnitude() const;
    point3d normalized() const;
    point3d_i operator+(const point3d_i &b) const;
    point3d_i operator-(const point3d_i &b) const;
    point3d_i operator*(const int &b) const;
    point3d operator/(const int &b) const;
    point3d operator*(const float &b) const;
    point3d operator/(const float &b) const;
    bool operator==(const point3d_i &b) const;
    bool operator!=(const point3d_i &b) const;
    friend std::ostream &operator<<(std::ostream &os, const point3d_i &b)
    {
        return os << '(' << b.x << ',' << b.y << ',' << b.z << ')';
    }
};
