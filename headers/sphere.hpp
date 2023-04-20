/**
 * @file sphere.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of class representing sphere in 3D space
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "shape.hpp"
#include "Material.hpp"

class Sphere : public Shape
{
    private: 
        float radius;
        Vector3f center;
        std::shared_ptr<Material> assigned_material;
    public:
        Sphere(float _radius, Vector3f _center, std::shared_ptr<Material> material);
        std::shared_ptr<Material> getMaterial() const override;
        hitRecord intersect(const Ray& ray) const override;
};