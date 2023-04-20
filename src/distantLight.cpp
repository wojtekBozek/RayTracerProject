/**
 * @file distantLight.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of distant (constant direction and intesity) light in 3D space
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "distantLight.hpp"

DistantLight::DistantLight(Matrix4x4f<float>& l2w, const Vector3f& _color, 
                           const float _intensity) 
                           : Light(l2w, _color)
{
    Vector3f temp = l2w*Vector3f(1.0f, 1.0f, 1.0f);
    temp.makeVectorUnitFast(); 
    dir = temp;
    intensity = _intensity;   
}

const float DistantLight::dirInteraction(const Vector3f& normal, const Vector3f& hit_position) 
{
    return dir.dotProduct(normal);
}

const float DistantLight::getIntensity(const Vector3f& hit_position) 
{
    return intensity;
}

const Vector3f DistantLight::getDirection(const Vector3f& hit_position)
{
    return dir;
}

DistantLight::~DistantLight(){}
