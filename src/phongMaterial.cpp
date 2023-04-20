/**
 * @file phongMaterial.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of Phong illumination model https://en.wikipedia.org/wiki/Phong_reflection_model
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "phongMaterial.hpp"

PhongMaterial::PhongMaterial(const Vector3f& _ambient, const Vector3f& _emissive, const Vector3f& _specular, const Vector3f& _diffuse, const float _n)
{
    ambient = _ambient;
    emissive = _emissive;
    specular = _specular;
    diffuse = _diffuse;
    n = _n;
}

PhongMaterial::PhongMaterial(PhongMaterial &mat) 
{
    ambient = mat.ambient;
    specular = mat.specular;
    emissive = mat.emissive;
    diffuse = mat.diffuse;
}

PhongMaterial &PhongMaterial::operator=(const PhongMaterial &mat)
{
    ambient = mat.ambient;
    specular = mat.specular;
    emissive = mat.emissive;
    diffuse = mat.diffuse;
    return *this;
}

/*
*As proposed solution to lighting recuires multiple light sources and interactions with them
*ambient color is to be added after computing simulations with all light sources separately
*/
const Vector3f PhongMaterial::computeColor(std::shared_ptr<Light> light, const Vector3f& viewer, 
                                           const Vector3f& normal, const Vector3f& intersection_point)
{
    float inter = std::max(0.0f, light->dirInteraction(normal, intersection_point));
    Vector3f Lm = light->getDirection(intersection_point);
    Vector3f R = (Lm-2*(normal.dotProduct(Lm)*normal)).makeVectorUnitFast();
    float cos_alpha = std::max(0.0f,R.dotProduct(viewer));
    float intensity = light->getIntensity(intersection_point);
    
    return diffuse*intensity*light->getColor()*inter
           + specular*intensity*powf(cos_alpha, n)*light->getColor()*inter;
}

const Vector3f &PhongMaterial::getAmbient()
{
    return ambient;
}

const Vector3f &PhongMaterial::getDiffuse()
{
    return diffuse;
}

const Vector3f &PhongMaterial::getSpecular()
{
    return specular;
}

const Vector3f &PhongMaterial::getEmissive()
{
    return emissive;
}
