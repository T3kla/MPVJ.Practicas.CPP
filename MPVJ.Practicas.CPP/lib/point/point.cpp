#include "point.h"

point::point(const float &x, const float &y) : x(x), y(y)
{
}
float point::magnitude() const
{
    return sqrt(x * x + y * y);
}
point point::normalized() const
{
    return *this / this->magnitude();
}
point point::operator+(const point &b) const
{
    return point(this->x + b.x, this->y + b.y);
}
point point::operator-(const point &b) const
{
    return point(this->x - b.x, this->y - b.y);
}
point point::operator*(const float &b) const
{
    return point(this->x * b, this->y * b);
}
point point::operator/(const float &b) const
{
    return point(this->x / b, this->y / b);
}
bool point::operator==(const point &b) const
{
    return (this->x == b.x) && (this->y == b.y);
}
bool point::operator!=(const point &b) const
{
    return (this->x != b.x) || (this->y != b.y);
}

point3d::point3d(const float &x, const float &y, const float &z) : x(x), y(y), z(z)
{
}
float point3d::magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}
point3d point3d::normalized() const
{
    return *this / this->magnitude();
}
point3d point3d::operator+(const point3d &b) const
{
    return point3d(this->x + b.x, this->y + b.y, this->z + b.z);
}
point3d point3d::operator-(const point3d &b) const
{
    return point3d(this->x - b.x, this->y - b.y, this->z - b.z);
}
point3d point3d::operator*(const float &b) const
{
    return point3d(this->x * b, this->y * b, this->z * b);
}
point3d point3d::operator/(const float &b) const
{
    return point3d(this->x / b, this->y / b, this->z / b);
}
bool point3d::operator==(const point3d &b) const
{
    return (this->x == b.x) && (this->y == b.y) && (this->z == b.z);
}
bool point3d::operator!=(const point3d &b) const
{
    return (this->x != b.x) || (this->y != b.y) || (this->z != b.z);
}

point_i::point_i(const int &x, const int &y) : x(x), y(y)
{
}
float point_i::magnitude() const
{
    return sqrt(x * x + y * y);
}
point point_i::normalized() const
{
    return *this / this->magnitude();
}
point_i point_i::operator+(const point_i &b) const
{
    return point_i(this->x + b.x, this->y + b.y);
}
point_i point_i::operator-(const point_i &b) const
{
    return point_i(this->x - b.x, this->y - b.y);
}
point_i point_i::operator*(const int &b) const
{
    return point_i(this->x * b, this->y * b);
}
point point_i::operator/(const int &b) const
{
    return point(round(this->x / b), round(this->y / b));
}
point point_i::operator*(const float &b) const
{
    return point(round(this->x * b), round(this->y * b));
}
point point_i::operator/(const float &b) const
{
    return point(round(this->x / b), round(this->y / b));
}
bool point_i::operator==(const point_i &b) const
{
    return (this->x == b.x) && (this->y == b.y);
}
bool point_i::operator!=(const point_i &b) const
{
    return (this->x != b.x) || (this->y != b.y);
}

point3d_i::point3d_i(const int &x, const int &y, const int &z) : x(x), y(y), z(z)
{
}
float point3d_i::magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}
point3d point3d_i::normalized() const
{
    return *this / this->magnitude();
}
point3d_i point3d_i::operator+(const point3d_i &b) const
{
    return point3d_i(this->x + b.x, this->y + b.y, this->z + b.z);
}
point3d_i point3d_i::operator-(const point3d_i &b) const
{
    return point3d_i(this->x - b.x, this->y - b.y, this->z - b.z);
}
point3d_i point3d_i::operator*(const int &b) const
{
    return point3d_i(this->x * b, this->y * b, this->z * b);
}
point3d point3d_i::operator/(const int &b) const
{
    return point3d(round(this->x / b), round(this->y / b), round(this->z / b));
}
point3d point3d_i::operator*(const float &b) const
{
    return point3d(round(this->x * b), round(this->y * b), round(this->z * b));
}
point3d point3d_i::operator/(const float &b) const
{
    return point3d(round(this->x / b), round(this->y / b), round(this->z / b));
}
bool point3d_i::operator==(const point3d_i &b) const
{
    return (this->x == b.x) && (this->y == b.y) && (this->z == b.z);
}
bool point3d_i::operator!=(const point3d_i &b) const
{
    return (this->x != b.x) || (this->y != b.y) || (this->z != b.z);
}
