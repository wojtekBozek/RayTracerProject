/**
 * @file scene.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of scene containing and managing 3D objects in 3D space
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "sphere.hpp"
#include "light.hpp"
#include "pixel.hpp"
#include "phongMaterial.hpp"
#include <vector>

class Scene : public Shape
{
    private:
        std::vector<std::shared_ptr<Shape>> hittable_shapes;
        std::shared_ptr<Material> sky;
        Pixel world_color;
        Vector3f brightness;
        const float bias = 1.e-3f;
    public:
        void setSky(std::shared_ptr<PhongMaterial> _sky){sky = _sky; world_color = Pixel(_sky->getAmbient()*_sky->getEmissive());}
        Scene(std::shared_ptr<PhongMaterial> _sky);
        
        hitRecord intersect(const Ray& ray) const override;
        bool inLight(std::shared_ptr<Light> light, const hitRecord&) const;
        
        void add(std::shared_ptr<Shape> shape);
        void remove(const uint32_t id);
        
        const float getBias() const;
        const Pixel& getColor() const;
        const Vector3f& getBrightness() const;
        std::shared_ptr<Material> getMaterial() const override;
};