/**
 * @file myMath.hpp
 * @author Wojtek B.(wboojztee@gmail.com)
 * @brief Additional custom functions for math operations
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <cmath>
#include <random>
namespace myMath
{
    enum SIGN : bool
    {
        PLUS = true,
        MINUS = false,
    };

    inline float computeDiscriminant(float a, float b, float c)
    {
        return b*b - 4*a*c;
    };

    
    inline float getRandomFloatInRange(float min, float max) 
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(min, max);
        return dis(gen);
    }
    inline float quadraticSolution(float b, float discriminant, float a, SIGN sign)
    {
        if(sign == MINUS)
            return ((-b - sqrtf(discriminant))/(2*a));
        else
            return ((-b + sqrtf(discriminant))/(2*a));
    }   

    template<class T> 
    T pointToRadConv(T angle)
    {
        return (T)(angle*M_PI/180.0f);
    }

    inline float clamp(float min, float max, float value)
    {
        return std::max(min, std::min(max, value));
    }
}