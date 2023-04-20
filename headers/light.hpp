/**
 * @file light.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Declaration of virtual class Light
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "Matrix4x4.hpp"
#include "inverseSquareRoot.hpp"
#include <math.h>

class Light
{
    private:
        Matrix4x4f<float> lightToWorld;
        Vector3f color;
    public:
        Light(Matrix4x4f<float>& l2w, const Vector3f& _color = {1.0f, 1.0f, 1.0f}) 
        : lightToWorld(l2w), color(_color) {} 
        const Vector3f& getColor(){return color;}
        virtual const Vector3f getDirection(const Vector3f& hit_position) = 0;
        
        /** 
         * @brief returns how ray interacted based by the normal of the object hit in the hit position
         * 
         * @param normal 
         * @param hit_position 
         * @return const float 
         */
        virtual const float dirInteraction(const Vector3f& normal, const Vector3f& hit_position) = 0;

        /**
         * @brief Get the raw intensity of light based on the position where hit occured
         * 
         * @param hit_position 
         * @return const float 
         */
        virtual const float getIntensity(const Vector3f& hit_position) = 0;
};
