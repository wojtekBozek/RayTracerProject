/**
 * @file ray.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of ray
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ray.hpp"

Ray::Ray(const Vector3f& _orign, const Vector3f& _direction)
{
    ray_direction = _direction;
    ray_origin = _orign;
    ray_direction.makeVectorUnitFast();
}

const Vector3f &Ray::getOrigin() const
{
    return ray_origin;
}

const Vector3f &Ray::getDirection() const
{
    return ray_direction;
}

Vector3f Ray::PointAtParameter(const float &t) const
{
    return ray_origin + ray_direction*t;
}
