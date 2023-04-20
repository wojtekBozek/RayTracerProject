/**
 * @file simpleCamera.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of simple camera based on simple camera proposed 
 *        in "Ray tracing in one Weekend" by Peter Shirley
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "simpleCamera.hpp"

SimpleCamera::SimpleCamera(const Vector3f &_left_lower_corner, const Vector3f &_horizontal,
                           const Vector3f &_vertical, const Vector3f &_origin)
{
    left_lower_corner = _left_lower_corner;
    horizontal = _horizontal;
    vertical = _vertical;
    origin = _origin;
    transformation = Matrix4x4f<float>(1.0f);
}

Ray SimpleCamera::getRay(const float &pos_x, const float &pos_y)
{
    return Ray(origin, left_lower_corner + pos_x*horizontal + pos_y*vertical);
}