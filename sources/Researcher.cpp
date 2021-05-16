
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
  Researcher::Researcher(Board &b, City c) : Player(b, c) {}

  Player &Researcher::discover_cure(Color c)
  {
    if (board.get_cure(c))
    {
      // cout << "already cured" << endl;
      return *this;
    }

    if (color_cards[c].size() >= board.size_card_to_drup)
    {
      // cout << "\ncolor_cards[c].size() >= 5" << endl;
      int i = 0;
      set<City> to_delete;
      for (auto card_delete : color_cards[c])
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

    return *this;
  }
  std::string Researcher::role() { return "Researcher"; }

}