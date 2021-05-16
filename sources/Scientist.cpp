
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Scientist.hpp"
using namespace pandemic;
using namespace std;

namespace pandemic
{

    Scientist::Scientist(Board &b, City c, int num) : Player(b, c)
    {
        this->n = num;
    };
    Player &Scientist::discover_cure(Color c)
    {
        if (board.get_cure(c))
        {
            return *this;
        }
        if (board.get_research_station(city))
        {
            if ((color_cards[c].size() >= board.size_card_to_drup) || color_cards[c].size() >= n)
            {
                int i = 0;
                set<City> to_delete;
                for (auto card_delete : color_cards[c])
                {
                    if (i == board.size_card_to_drup || i == n)
                    {
                        break;
                    }
                    to_delete.insert(card_delete);
                    i++;
                }
                for (auto card_delete : to_delete)
                {
                    delete_card(c, card_delete);
                }
                board.set_cure(c);
            }
            else
            {
                throw invalid_argument("'discover_cure' not enough cards with this color");
            }
        }
        else
        {
            throw invalid_argument("'discover_cure' there is no research_station");
        }
        return *this;
    }
    std::string Scientist::role() { return "Scientist"; }

}