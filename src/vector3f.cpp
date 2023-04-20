/**
 * @file vector3f.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief 3D space coordinate vector implementation based on "Ray Tracing in One Weekend" by Peter Shirley
 * @version 0.1
 * @date 2023-04-17
 *
 * 
 * 
 */

#include "vector3f.hpp"
#include "inverseSquareRoot.hpp"
#include <cmath>

#define EPSILON 0.0000001f

 Vector3f &Vector3f::operator+=(const Vector3f &Vec2)
{
    x += Vec2.X();
    y += Vec2.Y();
    z += Vec2.Z();
    return *this;
}

 Vector3f &Vector3f::operator-=(const Vector3f &Vec2)
{
    x -= Vec2.X();
    y -= Vec2.Y();
    z -= Vec2.Z();
    return *this;
}

 Vector3f &Vector3f::operator*=(const Vector3f &Vec2)
{
    x *= Vec2.X();
    y *= Vec2.Y();
    z *= Vec2.Z();
    return *this;
}

 Vector3f &Vector3f::operator/=(const Vector3f &Vec2)
{
    x /= Vec2.X();
    y /= Vec2.Y();
    z /= Vec2.Z();
    return *this;
}

 Vector3f& Vector3f::operator*=(const float& proportion)
{
    x *= proportion;
    y *= proportion;
    z *= proportion;
    return *this;
}

 Vector3f& Vector3f::operator/=(const float& proportion)
{
    x *= 1/proportion;
    y *= 1/proportion;
    z *= 1/proportion;
    return *this;
}

Vector3f operator+(const Vector3f& Vec1, const Vector3f &Vec2)
{
    Vector3f temp;
    temp.x = Vec1.x + Vec2.x;
    temp.y = Vec1.y + Vec2.y;
    temp.z = Vec1.z + Vec2.z;
    return temp;
}

 Vector3f operator-(const Vector3f& Vec1, const Vector3f &Vec2)
{
    Vector3f temp;
    temp.x = Vec1.x - Vec2.x;
    temp.y = Vec1.y - Vec2.y;
    temp.z = Vec1.z - Vec2.z;
    return temp;
}

 Vector3f operator*(const Vector3f& Vec1, const Vector3f &Vec2)
{
    Vector3f temp;
    temp.x = Vec1.x * Vec2.x;
    temp.y = Vec1.y * Vec2.y;
    temp.z = Vec1.z * Vec2.z;
    return temp;
}

 Vector3f operator/(const Vector3f& Vec1, const Vector3f &Vec2)
{
    Vector3f temp;
    temp.x = Vec1.x / Vec2.x;
    temp.y = Vec1.y / Vec2.y;
    temp.z = Vec1.z / Vec2.z;
    return temp;
}

 Vector3f operator*(const Vector3f& Vec1, const float &proportion)
{
    Vector3f temp;
    temp.x = Vec1.x * proportion;
    temp.y = Vec1.y * proportion;
    temp.z = Vec1.z * proportion;
    return temp;
}

 Vector3f operator/(const Vector3f& Vec1, const float &proportion)
{
    Vector3f temp;
    temp.x = Vec1.x / proportion;
    temp.y = Vec1.y / proportion;
    temp.z = Vec1.z / proportion;
    return temp;
}

 Vector3f operator*(const float &proportion, const Vector3f& Vec1)
{
    Vector3f temp;
    temp.x = Vec1.x * proportion;
    temp.y = Vec1.y * proportion;
    temp.z = Vec1.z * proportion;
    return temp;
}

 Vector3f operator/(const float &proportion, const Vector3f& Vec1)
{
    Vector3f temp;
    temp.x = Vec1.x / proportion;
    temp.y = Vec1.y / proportion;
    temp.z = Vec1.z / proportion;
    return temp;
}

 float Vector3f::dotProduct(const Vector3f &Vec2) const
{
    return x*Vec2.x + y*Vec2.y + z*Vec2.z;
}

 Vector3f Vector3f::crossProduct(const Vector3f &Vec2) const
{
    float _x = y*Vec2.z - Vec2.y*z;
    float _y = x*Vec2.z - Vec2.x*z;
    float _z = x*Vec2.y - Vec2.x*y; 
    return Vector3f(_x,-_y,_z);
}

Vector3f::Vector3f(const float &_x, const float &_y, const float &_z)
{
    x = _x;
    y = _y;
    z = _z;
}

Vector3f::Vector3f(const float& value)
{
    x = value;
    y = value;
    z = value;
}

Vector3f::Vector3f(const Vector3f &Vector)
{
    x = Vector.x; 
    y = Vector.y; 
    z = Vector.z;
}

 const Vector3f &Vector3f::operator_() const
{
    return *this;
}

Vector3f Vector3f::operator-() const
{
    return Vector3f(-x, -y, -z);
}

Vector3f &Vector3f::operator=(const Vector3f &Vec2)
{
    x = Vec2.x;
    y = Vec2.y;
    z = Vec2.z;
    return *this;
}

 float Vector3f::length() const
{
    return sqrtf(x*x+y*y+z*z);
}

 float Vector3f::squaredLength() const
{
    return x*x+y*y+z*z;
}

 Vector3f Vector3f::makeVectorUnit()
{
    if(this->length()!=0)
        *this /= this->length();
    return *this;
}
 Vector3f Vector3f::makeVectorUnitFast()
{
    *this *= inverseSquareRoot(squaredLength());
    return *this;
}

 std::istream &operator>>(std::istream &inStream, Vector3f &Vec)
{
    inStream >> Vec.x >> Vec.y >> Vec.z;
    return inStream;
}

 std::ostream &operator<<(std::ostream &outStream, const Vector3f &Vec)
{
    outStream << Vec.x << " " << Vec.y << " " << Vec.z;
    return outStream;
}

bool operator==(const Vector3f &Vec1, const Vector3f &Vec2)
{
    if(abs(Vec1.X() - Vec2.X()) <= EPSILON && abs(Vec1.Y() - Vec2.Y()) <= EPSILON && abs(Vec1.Z() - Vec2.Z()) <= EPSILON)
        return true;
    else
        return false;
}