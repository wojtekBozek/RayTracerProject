/**
 * @file simpleCamera.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of simple camera based on simple camera proposed 
 *        in "Ray tracing in one Weekend" by Peter Shirley
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "camera.hpp"

class SimpleCamera : public Camera
{
    private:
        Matrix4x4f<float> Mat2 = Matrix4x4f<float>(0.5f, 0.5f, 1.0f);
        Vector3f left_lower_corner;
        Vector3f horizontal;
        Vector3f vertical;
        Vector3f origin;
        Matrix4x4f<float> transformation;
    public:
    SimpleCamera(const Vector3f& _left_lower_corner, const Vector3f& _horizontal,
                 const Vector3f& _vertical, const Vector3f& _origin);

    Ray getRay(const float& pos_x, const float& pos_y) override;
};
