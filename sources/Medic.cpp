
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Medic.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{

    Medic::Medic(Board &b, City c) : Player(b, c) {}
    Player &Medic::treat(City c)
    {

        if (this->city == c)
        {

            if (board.get_val_diseas(c) != 0)
            {
                while (board.get_val_diseas(c) > 0)
                {
                    this->board.set_treat(c);
                }
            }
            else
            {
                throw invalid_argument("'treat' there is no diseas in the city");
            }
        }
        else
        {
            throw invalid_argument("'treat' not the same city");
        }
        return *this;
    }
    std::string Medic::role() { return "Medic"; }

}