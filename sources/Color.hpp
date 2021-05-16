#pragma once
#include "City.hpp"
#include <iostream>
#include <type_traits>
#include <map>
#include <set>
namespace pandemic
{

    enum Color
    {
        Yellow,
        Red,
        Blue,
        Black
    };

    inline std::string Color_string(Color color)
    {
        if (color == Yellow)
        {
            return "Yellow";
        }
        if (color == Red)
        {
            return "Red";
        }
        if (color == Blue)
        {
            return "Blue";
        }
        if (color == Black)
        {
            return "Black";
        }
        else
        {
            return "no coure";
        }
    };

}
