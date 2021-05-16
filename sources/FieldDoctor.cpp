
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "FieldDoctor.hpp"
#include <iostream>
#include <fstream>
using namespace std;
using namespace pandemic;

namespace pandemic
{
       FieldDoctor::FieldDoctor(Board &b, City c) : Player(b, c) {}
       Player &FieldDoctor::treat(City c)
       {
              if (c == city)
              {
                     return Player::treat(city);
              }
              for (const auto &neighbor : board.get_neighbors(city))
              {
                     if (neighbor == c)
                     {
                            City temp_city = city;
                            city = c;
                            Player::treat(city);
                            city = temp_city;
                            return *this;
                     }
              }
              throw invalid_argument("not the current city or neighbor of him");
       }
       std::string FieldDoctor::role() { return "FieldDoctor"; }

}