/**
 * @file reflective.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Class implementing reflective properties on given object (shape)
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "reflective.hpp"

Reflective::Reflective(std::shared_ptr<Shape> _shape, float reflective_strenght)
{
    shape = _shape; 
    str = reflective_strenght;
    if(str > 1.0f || str <0.0f)
    {
        str = 0.8f;
    }
}

Reflective::~Reflective(){}

hitRecord Reflective::intersect(const Ray& ray) const
{
    hitRecord record = shape->intersect(ray);
    record.ref_strenght=str;
    return record;
}

std::shared_ptr<Material> Reflective::getMaterial() const
{
    return shape->getMaterial();
}
