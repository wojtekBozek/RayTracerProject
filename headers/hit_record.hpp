/**
 * @file hit_record.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of structure representing properties of ray-object interaction
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "vector3f.hpp"
#include "Material.hpp"
#include <memory>


struct hitRecord
{
    bool hasHit;
    float t;
    Vector3f intersection_point;
    Vector3f normal;
    std::shared_ptr<Material> Material_ptr;
    float ref_strenght;
    float refraction_index;
};
