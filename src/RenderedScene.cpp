/**
 * @file RenderedScene.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of a holder for rendered scene (raw pixels)
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "RenderedScene.hpp"

RenderedScene::RenderedScene(){}
RenderedScene::RenderedScene(const uint32_t _width, const uint32_t _height) : width(_width), height(_height) 
{
    pixels.resize(height);
    for(auto& row : pixels)
    {
        row.resize(width, Pixel(0.0f,0.0f,0.0f));
    }
}
void RenderedScene::fillPixel(const uint32_t& pos_y, const uint32_t& pos_x, const Pixel& _computedPixel) {pixels.at(pos_y).at(pos_x) = _computedPixel;}
const Pixel& RenderedScene::getPixel(const uint32_t& pos_y, const uint32_t& pos_x) const {return pixels.at(pos_y).at(pos_x);}
const float& RenderedScene::getPixel_rValue(const uint32_t pos_y, const uint32_t pos_x) const {return pixels.at(pos_y).at(pos_x).R();}
const float& RenderedScene::getPixel_gValue(const uint32_t pos_y, const uint32_t pos_x) const {return pixels.at(pos_y).at(pos_x).G();}
const float& RenderedScene::getPixel_bValue(const uint32_t pos_y, const uint32_t pos_x) const {return pixels.at(pos_y).at(pos_x).B();}
const uint32_t& RenderedScene::getHeight() const {return height;}
const uint32_t& RenderedScene::getWidth() const {return width;}
RenderedScene::~RenderedScene(){}