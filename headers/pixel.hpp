/**
 * @file pixel.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief implementation of pixel with color value represented by floating point value
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "vector3f.hpp"

class Pixel : public Vector3f
{
    public:
        Pixel();
        Pixel(const float& r, const float& g, const float& b);
        Pixel(const Vector3f& _rgb);
        Pixel(const Pixel& pixel);

        Pixel& operator =(const Pixel& pixel);
        friend bool operator==(const Pixel& pixel1, const Pixel& pixel2);

        const float& R() const;
        const float& G() const;
        const float& B() const;
        
        ~Pixel();
};