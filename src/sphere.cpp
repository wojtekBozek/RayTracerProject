/**
 * @file sphere.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of class representing geometrical sphere in 3D space
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "sphere.hpp"
#include "isBehind.hpp"
#include "myMath.hpp"
Sphere::Sphere(float _radius, Vector3f _center, std::shared_ptr<Material> material)
{
    radius = _radius;
    center = _center;
    assigned_material = material;
}
std::shared_ptr<Material> Sphere::getMaterial() const
{
    return assigned_material;
}
hitRecord Sphere::intersect(const Ray &ray) const
{
    Vector3f origin_to_center = ray.getOrigin() - this->center;
    Vector3f direciton = ray.getDirection();
    float a = direciton.dotProduct(direciton);
    float b = 2*direciton.dotProduct(origin_to_center);
    float c = origin_to_center.dotProduct(origin_to_center) - radius*radius;
    float d = myMath::computeDiscriminant(a,b,c);

    if(d > 0)
    {
        float T = myMath::quadraticSolution(b, d, a, myMath::SIGN::MINUS);
        if(!isBehind(T))
        {
            Vector3f computed_intersection_point = ray.PointAtParameter(T); 
            return {true, T, computed_intersection_point, (computed_intersection_point - this->center)/radius, assigned_material, 0.0f, 0.0f};
        }        
        T = myMath::quadraticSolution(b, d, a, myMath::SIGN::PLUS);
        if(!isBehind(T))
        {
            Vector3f computed_intersection_point = ray.PointAtParameter(T); 
            return {true, T, computed_intersection_point, (computed_intersection_point - this->center)/radius, assigned_material, 0.0f, 0.0f};
        }   
    }
    return {false, -1.0f,{0,0,0}, {0,0,0}, nullptr, 0.0f, 0.0f};
}