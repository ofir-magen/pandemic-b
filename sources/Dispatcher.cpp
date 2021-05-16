
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic
{

    Dispatcher::Dispatcher(Board &b, City c) : Player(b, c) {}
    Player &Dispatcher::fly_direct(City c)
    {
         if (this->city == c)
        {
            throw invalid_argument("its the same city!");
        }
        if (board.get_research_station(city))
        {
            city = c;
        }
        else
        {
            return Player::fly_direct(c);
        }

        return *this;
    }
    std::string Dispatcher::role() { return "Dispatcher"; }

}