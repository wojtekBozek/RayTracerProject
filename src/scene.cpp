/**
 * @file scene.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of scene containing and managing 3D objects in 3D space
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "scene.hpp"

#define MAX_T 1000.0f

Scene::Scene(std::shared_ptr<PhongMaterial> _sky)
{
   sky = _sky; 
   world_color = Pixel(_sky->getAmbient()*_sky->getEmissive()); 
   brightness = _sky->getEmissive();
}

hitRecord Scene::intersect(const Ray &ray) const
{
    hitRecord hit_record = {false, MAX_T, {0,0,0}, {0,0,0}, sky, 0.0f, 0.0f};
    hitRecord current_hit = {false, MAX_T, {0,0,0}, {0,0,0}, sky, 0.0f, 0.0f};

    for (auto& shape : hittable_shapes)
    {
        current_hit = shape->intersect(ray);
        if(current_hit.hasHit)
            if(current_hit.t < hit_record.t)
                hit_record = current_hit;
    }
    return hit_record;
}

bool Scene::inLight(std::shared_ptr<Light> light, const hitRecord& record) const
{
    Vector3f dir = light->getDirection(record.intersection_point);
    Ray lightRay(record.intersection_point + record.normal*bias, dir);
    hitRecord obj_in_path;
    for (auto& shape : hittable_shapes)
    {
        obj_in_path = shape->intersect(lightRay);
        if(obj_in_path.hasHit && obj_in_path.t != 0)
            return false;
    }
    return true;
}

void Scene::add(std::shared_ptr<Shape> shape)
{
    hittable_shapes.push_back(shape);
}

void Scene::remove(const uint32_t id)
{
    hittable_shapes.erase(hittable_shapes.begin() + id);
}

const float Scene::getBias() const
{
    return bias;
}

const Pixel& Scene::getColor() const
{
    return world_color;
}

const Vector3f& Scene::getBrightness() const
{
    return brightness;
}

std::shared_ptr<Material> Scene::getMaterial() const
{
    return sky;
}


