/**
 * @file ScenePixels.hpp
 * @author Wojtek B (wboojztee@gmail.com)
 * @brief Implementation of a holder for rendered scene (raw pixels)
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "pixel.hpp"
#include <vector> 

class RenderedScene
{
    private:
        uint32_t width, height;
        std::vector<std::vector<Pixel>> pixels;
    public:
        RenderedScene();
        RenderedScene(const uint32_t _width, const uint32_t _height);

        void fillPixel(const uint32_t& pos_y, const uint32_t& pos_x, const Pixel& _computedPixel);
        const Pixel& getPixel(const uint32_t& pos_y, const uint32_t& pos_x) const;

        const float& getPixel_rValue(const uint32_t pos_y, const uint32_t pos_x) const;
        const float& getPixel_gValue(const uint32_t pos_y, const uint32_t pos_x) const;
        const float& getPixel_bValue(const uint32_t pos_y, const uint32_t pos_x) const;

        const uint32_t& getHeight() const;
        const uint32_t& getWidth() const;       
        ~RenderedScene();
};