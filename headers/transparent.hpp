/**
 * @file transparent.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Declaration of class which implements refractive/transparent properties on object
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "shape.hpp"

class Transparent : public Shape
{
    private:
        std::shared_ptr<Shape> shape;
        float n;
        float reflectivness;
    public:
        Transparent(std::shared_ptr<Shape> _shape, float refraction_index, float reflective_strenght);
        ~Transparent();
        hitRecord intersect(const Ray& ray) const override;
        std::shared_ptr<Material> getMaterial() const override;
};
