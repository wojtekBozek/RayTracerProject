/**
 * @file shape.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of virtual class representing geometrical shape
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "ray.hpp"
#include "hit_record.hpp"

class Shape
{
    public:
        virtual std::shared_ptr<Material> getMaterial() const = 0;
        virtual hitRecord intersect(const Ray& ray) const = 0;
};