/**
 * @file renderer.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of rendering pipeline
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "camera.hpp"
#include "RenderedScene.hpp"
#include "scene.hpp"
#include <cstdlib>
#include "light.hpp"

class Renderer
{
    private:
        std::vector<std::shared_ptr<Light>> lights;
        int stop_max;
        
        void renderPart(RenderedScene &scene, Scene& world_scene, const uint8_t samples, 
                        std::shared_ptr<Camera> camera, uint32_t y_start, uint32_t y_end,
                        uint32_t x_start, uint32_t x_end);
        
        void getPartDim(RenderedScene &scene, uint32_t& y_start, uint32_t& y_end, 
                        uint32_t& x_start, uint32_t& x_end, const int num);

        Pixel color(const Ray& ray, const hitRecord& record, std::shared_ptr<Light> lights) const;
        
        Pixel checkLight(const hitRecord& record,const Ray& ray, Scene world_scene, int stop); 
        
        void checkReflective(const hitRecord& record,const Ray& ray, Scene world_scene, int stop, Pixel& pixel, float& str);

        Vector3f reflect(const Vector3f &I, const Vector3f &N);

        void checkRefractive(const hitRecord& record,const Ray& ray, Scene world_scene, int stop, Pixel& pixel, float& refracted);

        Vector3f refract(const Vector3f &I, const Vector3f &N, float n);

        Vector3f RefractInverse(const Vector3f &I, const Vector3f &N, float n);

        void truncate(Pixel& pixel);

    public:
        Renderer(int recursions);

        void renderThreads(RenderedScene &scene, Scene& world_scene, 
                           const uint8_t samples, std::shared_ptr<Camera> camera);
        
        void appendLight(std::shared_ptr<Light> light);

        void render(RenderedScene &scene, Scene& world_scene,
                    const uint8_t samples, std::shared_ptr<Camera> camera);
};