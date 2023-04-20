/**
 * @file pixel.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief implementation of pixel with color value represented by floating point value
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pixel.hpp"

Pixel::Pixel() : Vector3f(){}
Pixel::Pixel(const float& r, const float& g, const float& b) : Vector3f(r,g,b){}
Pixel::Pixel(const Vector3f& _rgb) : Vector3f(_rgb){}
Pixel::Pixel(const Pixel& pixel) : Vector3f(Vector3f(pixel)) {}
Pixel& Pixel::operator =(const Pixel& pixel)
{
    Vector3f::operator=(pixel); 
    return *this;
}

bool operator==(const Pixel& pixel1, const Pixel& pixel2)
{
    if(pixel1.R() == pixel2.R() && pixel1.G() == pixel2.G() &&pixel1.B() == pixel2.B()) 
        return true; 
    else 
        return false;
}

const float& Pixel::R() const {return X();}
const float& Pixel::G() const {return Y();}
const float& Pixel::B() const {return Z();}
        
Pixel::~Pixel(){}