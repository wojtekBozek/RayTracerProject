/**
 * @file vector3f.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief 3D space coordinate vector implementation based on "Ray Tracing in One Weekend" by Peter Shirley
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stdlib.h>
#include <iostream>

class Vector3f 
{
    private:
        float x;
        float y;
        float z;
        //float fi;
        //float theta;
    public:
        Vector3f(){}
        Vector3f(const float& _x, const float& _y, const float& _z);
        Vector3f(const Vector3f& Vector);
        Vector3f(const float& value);

        const float& X() const {return x;}
        const float& Y() const {return y;}
        const float& Z() const {return z;}

        friend std::istream& operator>>(std::istream& inStream, Vector3f& Vec); 
        friend std::ostream& operator<<(std::ostream& outStream, const Vector3f& Vec); 
        friend bool operator==(const Vector3f& Vec1, const Vector3f& Vec2);

        const Vector3f& operator_() const;
        //Vector3f& operator-();
        Vector3f operator-() const;
        Vector3f& operator =(const Vector3f& Vec2);
        Vector3f& operator +=(const Vector3f& Vec2);
        Vector3f& operator -=(const Vector3f& Vec2);
        Vector3f& operator *=(const Vector3f& Vec2);
        Vector3f& operator /=(const Vector3f& Vec2);
        Vector3f& operator *=(const float& proportion);
        Vector3f& operator /=(const float& proportion);
    
        friend Vector3f operator+(const Vector3f& Vec1, const Vector3f& Vec2);
        friend Vector3f operator-(const Vector3f& Vec1, const Vector3f& Vec2);
        friend Vector3f operator*(const Vector3f& Vec1, const Vector3f& Vec2);
        friend Vector3f operator/(const Vector3f& Vec1, const Vector3f& Vec2);
        friend Vector3f operator*(const Vector3f& Vec1, const float& proportion);
        friend Vector3f operator/(const Vector3f& Vec1, const float& proportion);
        friend Vector3f operator*(const float& proportion, const Vector3f& Vec1);
        friend Vector3f operator/(const float& proportion, const Vector3f& Vec1);

        float dotProduct(const Vector3f& Vec2) const;
        Vector3f crossProduct(const Vector3f& Vec2) const;

        //these are commented out because they are repetition (or wrappers) for already implemented methods 
        //
        //static const Vector3f normalize(const Vector3f& vec)
        //{
        //    Vector3f vector = vec;
        //    vector.make_vector_unit_fast();
        //    return vector;
        //}

        //static const Vector3f cross(const Vector3f& vec1, const Vector3f& vec2)
        //{
        //    Vector3f vector = vec1.cross_product(vec2);
        //    return vector;
        //}

        //static const float dot(const Vector3f& vec1, const Vector3f& vec2)
        //{
        //    return vec1.dot_product(vec2);
        //}

        float length() const;
        float squaredLength() const;

        Vector3f makeVectorUnit();
        Vector3f makeVectorUnitFast();

        ~Vector3f(){}
};