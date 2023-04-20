/**
 * @file camera.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief File containing declartion of virtual class Camera
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "ray.hpp"
#include "Matrix4x4.hpp"

class Camera
{
    public:
        virtual Ray getRay(const float& pos_x, const float& pos_y) = 0;
};
