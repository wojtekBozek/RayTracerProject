/**
 * @file RenderSaver.hpp
 * @author Wojtek B.(wboojztee@gmail.com)
 * @brief Implementation of class saving given rendered scene (raw pixels) into ppm file
 * @version 0.1
 * @date 2023-04-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <iostream>
#include <fstream>
#include "RenderedScene.hpp"

class RenderSaver
{
    private:
        std::string filename;
    public:
        RenderSaver(){}
        RenderSaver(std::string _filename);

        void changePPMfileName(std::string _filename);
        void save(const RenderedScene& scene) const;
        ~RenderSaver(){}
};

int convertRGBtoPPMFormat(const float value);