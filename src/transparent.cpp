/**
 * @file transparent.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Declaration of class which implements refractive/transparent properties on object
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "transparent.hpp"

Transparent::Transparent(std::shared_ptr<Shape> _shape, float refraction_index, float reflective_strenght)
{
    shape = _shape;
    n = refraction_index;
    reflectivness = reflective_strenght;
}

Transparent::~Transparent()
{}

hitRecord Transparent::intersect(const Ray& ray) const 
{
    hitRecord record = shape->intersect(ray);
    Vector3f vector= record.normal.crossProduct(ray.getDirection());
    record.refraction_index = n;
    record.ref_strenght = reflectivness;
    return record;
}

std::shared_ptr<Material> Transparent::getMaterial() const 
{
    return shape->getMaterial();
}
