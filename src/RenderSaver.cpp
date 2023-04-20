/**
 * @file RenderSaver.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of class saving given rendered scene (raw pixels) into ppm file
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "RenderSaver.hpp"
#include <thread>

unsigned int threadsMaxHere = std::thread::hardware_concurrency();

RenderSaver::RenderSaver(std::string _filename)
{
    filename = _filename;
}

void RenderSaver::changePPMfileName(std::string _filename)
{
    filename = _filename;
}

int convertRGBtoPPMFormat(const float value)
{
    return static_cast<int>(255.99f*value);
}

void RenderSaver::save(const RenderedScene& scene) const
{
    int ny = scene.getHeight();
    int nx = scene.getWidth();
    std::ofstream renderOutcome;
    renderOutcome.open(filename);
    renderOutcome << "P3\n" << nx  << " " << ny << "\n255\n";
    for(int j = ny-1; j >= 0; j--)
    {
        
        for(int i = 0; i< nx; i++)
        {
            renderOutcome 
            << convertRGBtoPPMFormat(scene.getPixel_rValue(j,i)) << " " 
            << convertRGBtoPPMFormat(scene.getPixel_gValue(j,i)) << " " 
            << convertRGBtoPPMFormat(scene.getPixel_bValue(j,i)) << "\n"; 
        }
    }
    renderOutcome.close();
}
