#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <stdio.h>

#include <set>

namespace pandemic
{

    class Player
    {

    protected:
        std::set<City> cards;
        std::map<Color, std::set<City>> color_cards;
        Board &board;
        City city;
        std::string type;

    public:
        Player(Board &b, City c);
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        Player &take_card(City c);
        virtual std::string role() = 0;
        void remove_cards();

        Player &delete_card(Color color, City c);
    };

}
