/**
 * @file main.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Program that defines and renders a scene into the ppm file of given parameters passed as input arguments
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "RenderSaver.hpp"
#include "renderer.hpp"
#include "pointLightVisible.hpp"
#include "simpleCamera.hpp"
#include "pointLight.hpp"
#include "distantLight.hpp"
#include "timer.hpp"
#include "phongMaterial.hpp"
#include "reflective.hpp"
#include "transparent.hpp"
#include <memory>  
#include <string>

#ifndef NDEBUG
    #define time(x){ Timer *timer1 = new Timer(); x; delete(timer1);}
#else
    #define time(x) x
#endif

void checkDimension(uint32_t &dim)
{
    if(dim > 1920 || dim <= 0)
    {
        dim = 240;
    }
}

int main(int argc, char* argv[])
{
        uint32_t heigth = 80;
        uint32_t width = 100;
        float dist_z = 10.0f;
        std::string dist = "10";
    if(argc >= 3)
    {
        heigth = static_cast<uint32_t>(atoi(argv[1]));
        width = static_cast<uint32_t>(atoi(argv[2]));
        if(argc > 3)
        {
            dist_z = static_cast<float>(atof(argv[3]));
            dist = argv[3];
        }
    }

    checkDimension(heigth);
    checkDimension(width);

    auto Material1 = std::make_shared<PhongMaterial>(Vector3f(0.0f, 1.0f, 1.0f),  
                                                     Vector3f(1.0f, 1.0f, 1.0f),  
                                                     Vector3f(0.0f, 0.0f, 0.0f),  
                                                     Vector3f(0.4f, 0.4f, 0.4f),0.0f);

    auto Material2 = std::make_shared<PhongMaterial>(Vector3f(0.1f, 0.1f, 0.1f),
                                                     Vector3f(0.0f, 0.0f, 0.0f),
                                                     Vector3f(0.4f, 0.4f, 0.4f),
                                                     Vector3f(0.6f, 0.6f, 0.6f),float(50.0f));

    auto Material3 = std::make_shared<PhongMaterial>(Vector3f(0.0f, 0.1f, 0.1f),
                                                     Vector3f(0.0f, 0.0f, 0.0f),
                                                     Vector3f(0.0f, 0.0f, 0.0f),
                                                     Vector3f(0.0f, 0.0f, 0.6f),0.0f);
    Matrix4x4f<float> matrix(1.0f, 10.0f, 10.0f);
    DistantLight light(matrix,Vector3f(1.0f),1.0f);
    Matrix4x4f<float> matrix2(0.0f, 0.8f, 2.0f);
    PointLightVisible lightP(matrix2, Vector3f(1.0f), 1.0f);
    Matrix4x4f<float> matrix3(0.0f, 0.5f, 1.5f);
    PointLight lightP1(matrix3, Vector3f(1.0f), 1.0f);

    auto light1 = std::make_shared<DistantLight>(light);
    auto light2 = std::make_shared<PointLightVisible>(lightP);
    auto light3 = std::make_shared<PointLight>(lightP1);
    auto sfera1 = std::make_shared<Sphere>(Sphere(0.5f, {-1.5f, 1.0f, 0.0f}, Material2));
    auto sfera3 = std::make_shared<Sphere>(Sphere(0.5f, {0.0f, 1.4f, -1.0f}, Material3));
    auto sfera2 = std::make_shared<Sphere>(Sphere(25.0f, {0.0f, -25.5f, 0.0f}, Material3));
    auto sfera4 = std::make_shared<Sphere>(Sphere(0.6f, {-0.3f, -0.2f, 4.0f}, Material3));
    auto sfera5 = std::make_shared<Sphere>(Sphere(0.5f, {1.0f, 0.0f, 1.0f}, Material2));
    
    auto trans = std::make_shared<Transparent>(Transparent(sfera4, 1.5f, 0.8f));
    auto refl2 = std::make_shared<Reflective>(Reflective(sfera3, 0.4f));

    Scene world_scene(Material1);
    world_scene.add(sfera1);
    world_scene.add(trans);
    world_scene.add(sfera2);
    world_scene.add(sfera5);
    world_scene.add(refl2);
    world_scene.add(light2);
    RenderedScene *scene = new RenderedScene(width, heigth);
    
    float AspectRatio = heigth/static_cast<float>(width);
    float cameraWidth = 4.0f;
    
    SimpleCamera camera({-cameraWidth/2.0f, -AspectRatio*cameraWidth/2.0f, -10.0f}, 
    {cameraWidth,0.0f,0.0f}, {0.0f,AspectRatio*cameraWidth,0.0f}, {0.0f,0.0f, dist_z});

    std::shared_ptr<SimpleCamera> cam = std::make_shared<SimpleCamera>(camera);
    
    Renderer renderer(10);
    renderer.appendLight(light1);
    //renderer.appendLight(light2);
    //renderer.appendLight(light3);

    time(renderer.renderThreads(*scene, world_scene, static_cast<uint8_t>(5), cam));
    std::string name = "h_"+ std::to_string(heigth) + "_w_" + std::to_string(width) + "_z_" + dist + ".ppm";
    RenderSaver *saver3 = new RenderSaver(name);
    time(saver3->save(*scene));
    delete(saver3);
    
    delete(scene);

    return 0;
}
