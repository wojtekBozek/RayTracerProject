/**
 * @file pointLight.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of point light with intensity based 
 *        on inversed square root of distant to hit point
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pointLight.hpp"

PointLight::PointLight(Matrix4x4f<float>& l2w, const Vector3f& _color,
                       const float _intensity) 
                        : Light(l2w, _color)
{ 
    pos = l2w*Vector3f(1.0f); 
    intensity = _intensity; 
    range = 1.0f;
}

PointLight::~PointLight(){}

const float PointLight::getIntensity(const Vector3f& hit_position) 
{
    Vector3f dist = pos - hit_position;
    if(dist.length() < 1.0f)
        return intensity;
    
    float intens = intensity*inverseSquareRoot(dist.squaredLength());
    return intens;
}

const float PointLight::dirInteraction(const Vector3f& normal, const Vector3f& hit_position) 
{
    Vector3f dist = pos - hit_position;
    dist.makeVectorUnitFast();
    return dist.dotProduct(normal);
}

const Vector3f PointLight::getDirection(const Vector3f& hit_position)
{
    Vector3f dist =pos - hit_position;
    dist.makeVectorUnitFast();
    return dist;
}
