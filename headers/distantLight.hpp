/**
 * @file distantLight.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of distant light of constant intensity
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "light.hpp"

class DistantLight : public Light
{
    private:
        Vector3f dir;
        float intensity;
    public:
        DistantLight(Matrix4x4f<float>& l2w, const Vector3f& _color = {1.0f, 1.0f, 1.0f}, const float _intensity = 1.0f);

        const float dirInteraction(const Vector3f& normal, const Vector3f& hit_position) override;

        const float getIntensity(const Vector3f& hit_position) override;
        const Vector3f getDirection(const Vector3f& hit_position) override;

        ~DistantLight();
};