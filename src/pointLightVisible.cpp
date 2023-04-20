/**
 * @file pointLightVisible.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of visible point light, which is a groundwork for future add-ons, like visible flash of light
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pointLightVisible.hpp"

PointLightVisible::PointLightVisible(Matrix4x4f<float>& l2w, const Vector3f& _color,
                                     const float _intensity) : PointLight(l2w, _color)
{ 
    pos = l2w*Vector3f(1.0f); 
    intensity = _intensity; 
    range = 1.0f;
}

PointLightVisible::~PointLightVisible()
{}

const Vector3f PointLightVisible::computeColor(std::shared_ptr<Light> light, const Vector3f& viewer,
                                               const Vector3f& normal, const Vector3f& intersection_point)
{
    return this->getColor();
}

hitRecord PointLightVisible::intersect(const Ray& ray) const
{
    Vector3f pos_to_center = this->pos-ray.getOrigin();
    Vector3f direction = ray.getDirection();
    Vector3f distance = pos_to_center;
    pos_to_center.makeVectorUnitFast();
    std::shared_ptr<PointLightVisible> ptr = std::make_shared<PointLightVisible>(*this);
    if(abs((pos_to_center-ray.getDirection()).length()) < 0.01f/(distance.length()))
        return {true, 0, pos_to_center, -direction, ptr};
    return {false, 0, {0.0f, 0.0f, 0.0f}, {0.0f,0.0f,0.0f}, nullptr};
}

std::shared_ptr<PointLightVisible> PointLightVisible::getPtr()
{
    return shared_from_this();
}

std::shared_ptr<Material> PointLightVisible::getMaterial() const
{
    std::shared_ptr<PointLightVisible> ptr = std::make_shared<PointLightVisible>(*this);
    return ptr;
}

const Vector3f& PointLightVisible::getAmbient()
{
    return this->getColor();
}
