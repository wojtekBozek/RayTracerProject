/**
 * @file ray.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of ray
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "vector3f.hpp"

class Ray
{
    private:
        Vector3f ray_origin;
        Vector3f ray_direction;
    public:
        Ray() {}
        Ray(const Vector3f& _orign, const Vector3f& _direction);

        const Vector3f& getOrigin() const;
        const Vector3f& getDirection() const;
        Vector3f PointAtParameter(const float& t) const;
};