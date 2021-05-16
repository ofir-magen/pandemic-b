
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
  GeneSplicer::GeneSplicer(Board &b, City c) : Player(b, c) {}
  Player &GeneSplicer::discover_cure(Color c)
  {
    if (board.get_cure(c))
    {
      return *this;
    }
    if (board.get_research_station(city))
    {
      if (cards.size() >= board.size_card_to_drup)
      {
        int i = 0;
        set<City> to_delete;
        for (auto card_delete : cards)
        {
          if (i == board.size_card_to_drup)
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
  std::string GeneSplicer::role() { return "GeneSplicer"; }

}