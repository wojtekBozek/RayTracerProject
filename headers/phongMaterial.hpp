/**
 * @file phongMaterial.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of Phong illumination model https://en.wikipedia.org/wiki/Phong_reflection_model
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "Material.hpp"

class PhongMaterial : public Material
{
    private:
        Vector3f ambient;
        Vector3f emissive;
        Vector3f specular;
        Vector3f diffuse;
        float n;
    public:
        PhongMaterial(const Vector3f& _ambient, const Vector3f& _emissive, const Vector3f& _specular, const Vector3f& _diffuse, const float _n);
        PhongMaterial(PhongMaterial& mat);
        PhongMaterial& operator =(const PhongMaterial& mat);
        const Vector3f computeColor(std::shared_ptr<Light> light, const Vector3f& viewer,
                                            const Vector3f& normal, const Vector3f& intersection_point) override;
        const Vector3f& getAmbient() override;
        const Vector3f& getEmissive();
        const Vector3f& getSpecular();
        const Vector3f& getDiffuse();
};