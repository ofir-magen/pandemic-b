
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <set>

using namespace pandemic;
using namespace std;

namespace pandemic

{
    Player::Player(Board &b, City c) : board(b), city(c) {}

    Player &Player::drive(City c)
    {

        if (this->city != c)
        {

            if ((board.is_neighbor(this->city, c)))
            {

                this->city = c;
                if (role() == "Medic" && this->board.get_cure(this->board.get_city_color(city)))
                {
                    this->board.set_treat(city);
                }
            }
            else
            {
                throw invalid_argument("the dest city is not neighbor! [from , to]" + board.get_city_name(city) + ", " + board.get_city_name(c));
            }
        }
        else
        {
            throw invalid_argument("its the same city!");
        }
        return *this;
    }

    Player &Player::fly_direct(City c)
    {
        if (this->city == c)
        {
            throw invalid_argument("its the same city!");
        }
        if (cards.find(c) != cards.end())
        {
            city = c;
            delete_card(board.get_city_color(c), c);
            if (role() == "Medic" && this->board.get_cure(this->board.get_city_color(city)))
            {
                this->board.set_treat(city);
            }
        }
        else
        {
            throw invalid_argument("'fly_direct' no card direct");
        }
        return *this;
    }

    Player &Player::fly_charter(City c)
    {
        if (this->city == c)
        {
            throw invalid_argument("its the same city!");
        }
        if (this->cards.find(city) != this->cards.end())
        {
            delete_card(board.get_city_color(city), city);
            this->city = c;
            if (role() == "Medic" && this->board.get_cure(this->board.get_city_color(city)))
            {
                this->board.set_treat(city);
            }
        }
        else
        {
            throw invalid_argument("Cannot 'fly_charter' Because there is no current city card!\n");
        }
        return *this;
    }

    Player &Player::fly_shuttle(City c)
    {
        if (this->city == c)
        {
            throw invalid_argument("its the same city!");
        }
        if (board.get_research_station(city))
        {
            if (board.get_research_station(c))
            {
                this->city = c;
                if (role() == "Medic" && this->board.get_cure(this->board.get_city_color(city)))
                {
                    this->board.set_treat(city);
                }
            }
            else
            {
                throw invalid_argument("'fly_shuttle' There is no research station in the dest city\n");
            }
        }
        else
        {
            throw invalid_argument("'fly_shuttle' there is no research station in the current city\n");
        }
        return *this;
    }

    Player &Player::build()
    {
        if (cards.count(city) == 1)
        {
            if (!(board.get_research_station(city)))
            {
                board.set_research_station(city);
                delete_card(board.get_city_color(city), city);
            }
            else
            {
                board.set_research_station(city);
            }
        }
        else
        {
            throw invalid_argument("'build' there is no card city to build a research station in the current city\n");
        }
        return *this;
    }

    Player &Player::discover_cure(Color c)
    {
        if (board.get_cure(c))
        {
            return *this;
        }
        if (board.get_research_station(city))
        {
            if (color_cards[c].size() >= board.size_card_to_drup)
            {
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
        }
        else
        {
            throw invalid_argument("'discover_cure' there is no research_station");
        }
        return *this;
    }

    Player &Player::treat(City c)
    {
        if (this->city != c)
        {
            throw invalid_argument("'treat' not the same city");
        }
        if (board.get_val_diseas(c) != 0)
        {
            this->board.set_treat(c);
        }
        else
        {
            throw invalid_argument("'treat' there is no diseas in the city");
        }
        return *this;
    }

    Player &Player::take_card(City c)
    {
        color_cards[board.get_city_color(c)].insert(c);
        cards.insert(c);
        return *this;
    }

    void Player::remove_cards()
    {
        this->cards.erase(this->cards.begin(), this->cards.end());
    }

    Player &Player::delete_card(Color color, City c)
    {
        cards.erase(c);
        color_cards[color].erase(c);
        return *this;
    }

}