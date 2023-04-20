/**
 * @file pointLight.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of point light with intensity based 
 *        on inversed square root of distant to hit point
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "light.hpp"


class PointLight : public Light
{
    private:
        Vector3f pos;
        float intensity;
        float range;
    public:
        PointLight(Matrix4x4f<float>& l2w, const Vector3f& _color = {1.0f, 1.0f, 1.0f}, const float _intensity = 1);
        ~PointLight();

        const float getIntensity(const Vector3f& hit_position) override;
        const float dirInteraction(const Vector3f& normal, const Vector3f& hit_position) override;

        const Vector3f getDirection(const Vector3f& hit_position) override;
};
