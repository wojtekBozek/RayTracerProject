/**
 * @file reflective.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Class implementing reflective properties on given object (shape)
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "shape.hpp"

class Reflective : public Shape 
{
    private:
        std::shared_ptr<Shape> shape;
        float str;
    public:
        Reflective(std::shared_ptr<Shape> _shape, float reflective_strenght);
        ~Reflective();
        std::shared_ptr<Material> getMaterial() const override;
        hitRecord intersect(const Ray& ray) const override;
};