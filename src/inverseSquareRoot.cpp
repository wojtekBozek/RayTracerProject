/**
 * @file inverseSquareRoot.cpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief implementation of Quake III fast inverse square root algorithm
 * @version 0.1
 * @date 2023-04-17
 */

#include "inverseSquareRoot.hpp"
#include <cstring>

#define MAGIC_NUMBER  0x5f3759df
#define THREEHALFS  1.5f
#define HALF 0.5f

float inverseSquareRoot(float number)
{
    int numberCastedToInt;
    float recastedValue;

    memcpy(&numberCastedToInt, &number,sizeof(number));
    numberCastedToInt = MAGIC_NUMBER-(numberCastedToInt >> 1);
    memcpy(&recastedValue, &numberCastedToInt, sizeof(numberCastedToInt));
    return recastedValue*(THREEHALFS-(number*HALF*recastedValue*recastedValue));
}