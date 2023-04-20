/**
 * @file Material.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Declaration of virtual class Material
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "light.hpp"
#include "vector3f.hpp"
#include <memory>

class Material
{
    public:
        virtual const Vector3f computeColor(std::shared_ptr<Light> light, const Vector3f& viewer,
                                            const Vector3f& normal, const Vector3f& intersection_point) = 0;
        virtual const Vector3f& getAmbient() = 0;
};
