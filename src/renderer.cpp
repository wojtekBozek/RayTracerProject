/**
 * @file renderer.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Definition of class methods that implement rendering processes
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "renderer.hpp"
#include <thread>
#include <random>
unsigned int threadsMax = std::thread::hardware_concurrency();
unsigned int threadsHalf = threadsMax/2;

Renderer::Renderer(int recursions)
{
    stop_max = recursions;
    if(recursions > 10 || recursions < 1)
    {
        stop_max = 5;
    }
}

void Renderer::appendLight(std::shared_ptr<Light> light)
{
    lights.push_back(light);
}

void Renderer::render(RenderedScene &scene, Scene& world_scene,
                      const uint8_t samples, std::shared_ptr<Camera> camera)
{
    Pixel pixel;
    float x_coor;            
    float y_coor;
    Ray ray;
    hitRecord record;
    for (uint32_t y = 0; y < scene.getHeight(); y++)
    {
        for(uint32_t x = 0; x < scene.getWidth(); x++)
        {
            pixel = {0.0f, 0.0f, 0.0f};
            for(uint8_t i = 0; i< samples; i++)
            {
                x_coor = static_cast<float>(x + static_cast<float>(rand()) 
                             / static_cast<float>(RAND_MAX)) / static_cast<float>(scene.getWidth());
                             
                y_coor = static_cast<float>(y + static_cast<float>(rand()) 
                             / static_cast<float>(RAND_MAX)) / static_cast<float>(scene.getHeight());

                ray = camera->getRay(x_coor, y_coor);
                record = world_scene.intersect(ray);
                if(record.hasHit!=true)
                {
                    if(i!=0)
                        pixel += world_scene.getColor();
                    else
                    {
                        pixel = samples*world_scene.getColor();;
                        break;
                    }
                }
                else 
                {
                    pixel += checkLight(record, ray, world_scene, 0);
                }
            }
            pixel /= static_cast<float>(samples);
            scene.fillPixel(y ,x, pixel);
        }
    }
}

void Renderer::renderThreads(RenderedScene &scene, Scene& world_scene,
                            const uint8_t samples, std::shared_ptr<Camera> camera)
{
    std::vector<std::thread> threads;
    std::cout <<"Rendering started\n";
    for(unsigned int thread = 0; thread < threadsMax; thread++)
    {
        threads.emplace_back([this, thread, &scene, &world_scene, &camera, samples] 
                             {uint32_t y_start; uint32_t y_end; uint32_t x_start; uint32_t x_end; 
                             this->getPartDim(scene, y_start, y_end, x_start, x_end, thread); 
                             this->renderPart(scene, world_scene, samples, camera, y_start, y_end, x_start, x_end);});
    }
    for (auto& thread: threads) thread.join();
    std::cout <<"Rendering finished\n";
}

void Renderer::getPartDim(RenderedScene &scene, uint32_t& y_start, uint32_t& y_end,
                          uint32_t& x_start, uint32_t& x_end, const int num)
{
    x_start = ((num/threadsHalf) * scene.getWidth())/(threadsMax/threadsHalf);
    x_end = ((num/threadsHalf+1) * scene.getWidth())/(threadsMax/threadsHalf);
    y_start = ((num%threadsHalf) * scene.getHeight())/threadsHalf;
    y_end = ((num%threadsHalf+1) * scene.getHeight())/threadsHalf;
}

void Renderer::renderPart(RenderedScene &scene, Scene& world_scene, const uint8_t samples, 
                          std::shared_ptr<Camera> camera, uint32_t y_start, uint32_t y_end, 
                          uint32_t x_start, uint32_t x_end)
{
    hitRecord record;
    Ray ray;
    float x_coor;
    float y_coor;
    Pixel pixel;
    for (uint32_t y = y_start; y < y_end; y++)
    {
        for(uint32_t x = x_start; x < x_end; x++)
        {
            pixel = {0.0f, 0.0f, 0.0f};
            for(uint8_t i = 0; i< samples; i++)
            {
                x_coor = static_cast<float>(x + static_cast<float>(rand())
                        / static_cast<float>(RAND_MAX)) / static_cast<float>(scene.getWidth());
                        
                y_coor = static_cast<float>(y + static_cast<float>(rand())
                        / static_cast<float>(RAND_MAX)) / static_cast<float>(scene.getHeight());

                ray = camera->getRay(x_coor, y_coor);
                record = world_scene.intersect(ray);
                if(record.hasHit!=true)
                {
                    if(i!=0)
                        pixel += world_scene.getColor();
                    else
                    {
                        pixel = samples*world_scene.getColor();;
                        break;
                    }
                }
                else 
                {
                    pixel += checkLight(record, ray, world_scene, 0);
                }
            }
            pixel /= static_cast<float>(samples);
            scene.fillPixel(y ,x, pixel);
        }
    }
}

Pixel Renderer::checkLight(const hitRecord& record,const Ray& ray, Scene world_scene, int stop)
{
    Pixel pixel = {0.0f, 0.0f, 0.0f};
    if(lights.size()==0 || stop == stop_max)
    {
        if(record.ref_strenght > 0.0f)
        {
            return pixel += record.ref_strenght * Pixel(record.Material_ptr->getAmbient());
        }
        else 
            return pixel += record.ref_strenght * world_scene.getColor();
    }
    else
    {   
        float refracted = 0.0f;
        if(record.refraction_index>=1.0f)
        {
            checkRefractive(record, ray, world_scene, stop, pixel, refracted);
        }
        float str = record.ref_strenght - refracted;
        if(str > 0.0f)
        {
            checkReflective(record, ray, world_scene, stop, pixel, str);
        }
         
        str = 1.0f-record.ref_strenght;
        for(const auto& light : lights)
        {
        if(world_scene.inLight(light, record))
            {
                pixel += str*color(ray, record, light);
            }
        }
        pixel += str*Pixel(record.Material_ptr->getAmbient()*world_scene.getBrightness());
    }
    truncate(pixel);
    return pixel;
}

Vector3f getRandomDirection()
{
float x = myMath::getRandomFloatInRange(-1.0f, 1.0f);
float y = myMath::getRandomFloatInRange(-1.0f, 1.0f);
float z = myMath::getRandomFloatInRange(-1.0f, 1.0f);
return Vector3f(x,y,z);
}

void Renderer::checkReflective(const hitRecord& record,const Ray& ray, Scene world_scene, int stop, Pixel& pixel, float& str)
{
    Ray t_ray(record.intersection_point + record.normal*world_scene.getBias(), 
                      (reflect(ray.getDirection(), record.normal)).makeVectorUnitFast());
    hitRecord t_record = world_scene.intersect(t_ray);
    if(t_record.hasHit!=true)
    {
       pixel += str* world_scene.getColor();    
    }
    else 
    {
        pixel += str * checkLight(t_record, t_ray, world_scene, stop + 1);
    }
}

Vector3f Renderer::reflect(const Vector3f &I, const Vector3f &N) 
{ 
    return I - 2 * I.dotProduct(N) * N; 
}

void Renderer::checkRefractive(const hitRecord& record,const Ray& ray, Scene world_scene, int stop, Pixel& pixel, float& refracted)
{
    float cos_theta = ray.getDirection().dotProduct(record.normal);
    float offset  = 1.0f;
    refracted = (1 - std::abs(cos_theta))*record.ref_strenght;
    if(cos_theta < 0.0f)
    {
        offset  = -1.0f;
    }
    Ray t_ray(record.intersection_point + offset*record.normal*world_scene.getBias(), 
              refract(ray.getDirection(), record.normal, record.refraction_index));
    hitRecord t_record = world_scene.intersect(t_ray);
    if(t_record.hasHit!=true)
    {
       pixel += refracted* world_scene.getColor();    
    }
    else 
    {
        pixel += refracted * checkLight(t_record, t_ray, world_scene, stop+1);
    }
}

Vector3f Renderer::refract(const Vector3f &I, const Vector3f &N, float n)
{
    float cos_theta = I.dotProduct(N);
    Vector3f normal = N;
    float eta = 1/n;
    if(cos_theta < 0.0f)
    {
        cos_theta = -cos_theta;
        normal = -normal;
    }
    else
    {
        eta = 1/eta;
    }
    float sin_theta = sqrtf(1-cos_theta*cos_theta);
    float sin_theta2 = eta*sin_theta;
    sin_theta2 = std::min(1.0f, sin_theta2);
    float cos_theta2 = sqrtf(1.0f-sin_theta2*sin_theta2);
    Vector3f tilted_ray = ((I+cos_theta*normal)/sin_theta)*sin_theta2 + normal*cos_theta2;
    return tilted_ray;
}

Vector3f Renderer::RefractInverse(const Vector3f &I, const Vector3f &N, float n)
{
    float cos_theta = I.dotProduct(N);
    Vector3f normal = N;
    float eta = n;
    if(cos_theta < 0.0f)
    {
        cos_theta = -cos_theta;
    }
    else
    {
        normal = -normal;
        eta = 1/eta;
    }
    float sin_theta = sqrtf(1-cos_theta*cos_theta);
    float sin_theta2 = eta*sin_theta;
    sin_theta2 = std::min(1.0f, sin_theta2);
    float cos_theta2 = sqrtf(1.0f-sin_theta2*sin_theta2);
    Vector3f tilted_ray = ((I+cos_theta*normal)/sin_theta)*sin_theta2 - normal*cos_theta2;
    return tilted_ray;
}

Pixel Renderer::color(const Ray& ray, const hitRecord& record, std::shared_ptr<Light> lights) const
{
    return Pixel(record.Material_ptr->computeColor(lights, ray.getDirection(), record.normal, record.intersection_point));
}

void Renderer::truncate(Pixel& pixel)
{
    if(pixel.R() > 1.0f)
        {
            pixel = {1.0f, pixel.G(), pixel.B()};
        }
        if(pixel.G() > 1.0f)
        {
            pixel = {pixel.R(), 1.0f, pixel.B()};
        }
        if(pixel.B() > 1.0f)
        {
           pixel = {pixel.R(), pixel.G(), 1.0f};
        }
}
