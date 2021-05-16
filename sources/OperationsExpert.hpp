#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "stdio.h"

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        OperationsExpert(Board &b, City c);
        Player &build();
        std::string role();
    };

}