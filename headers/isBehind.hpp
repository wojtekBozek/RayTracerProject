/**
 * @file isBehind.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of simple checkout whether algebraic T parameter
 *        giving specific point on line given by directional vector is positive
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

inline bool isBehind(float t)
{
    if(t <= 0.0f)
    {
        return true;
    }
    return false;
}