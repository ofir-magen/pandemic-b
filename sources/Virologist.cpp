
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{

  Virologist::Virologist(Board &b, City c) : Player(b, c) {}

  Player &Virologist::treat(City c)
  {
    if (cards.count(c) != 0 || city == c)
    {

      if (board.get_val_diseas(c) != 0)
      {
        this->board.set_treat(c);
      }
      else
      {
        throw invalid_argument("'treat' there is no diseas in the city");
      }
    }
    else
    {
      throw invalid_argument("'treat' dont have the card of the city");
    }
    return *this;
  }
  std::string Virologist::role() { return "Virologist"; }

}