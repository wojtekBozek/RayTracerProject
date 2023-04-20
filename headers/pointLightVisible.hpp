/**
 * @file pointLightVisible.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of visible point light, which is a groundwork for future add-ons, like visible flash of light
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <cmath>
#include <stdlib.h>
#include "Material.hpp"
#include "pointLight.hpp"
#include "shape.hpp"

class PointLightVisible : public PointLight, public Material, public Shape, public std::enable_shared_from_this<PointLightVisible>
{
    private:
        Vector3f pos;
        float intensity;
        float range;
    public:
        PointLightVisible(Matrix4x4f<float>& l2w, const Vector3f& _color = {1.0f, 1.0f, 1.0f}, const float _intensity = 1.0f);
        ~PointLightVisible();

        const Vector3f computeColor(std::shared_ptr<Light> light, const Vector3f& viewer, 
                                    const Vector3f& normal, const Vector3f& intersection_point) override;
        hitRecord intersect(const Ray& ray) const override;

        std::shared_ptr<PointLightVisible> getPtr();
        std::shared_ptr<Material> getMaterial() const override;
        const Vector3f& getAmbient() override;    
};