
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "OperationsExpert.hpp"
#include "stdio.h"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    OperationsExpert::OperationsExpert(Board &b, City c) : Player(b, c) {}
    Player &OperationsExpert::build()
    {
        if (!(board.get_research_station(city)))
        {
            board.set_research_station(city);
        }
        return *this;
    }
    std::string OperationsExpert::role() { return "OperationsExpert"; }
}