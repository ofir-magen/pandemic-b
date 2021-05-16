#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic
{
    class Board
    {
    private:
        struct Node
        {
            std::string name_city;
            std::set<City> neighbors_citys;
            int diseas_val;
            bool research_station;
            Color color;
            bool medicine;
        };
        std::map<City, Node> NodeData;

    public:
            const int size_card_to_drup = 5;

        Board();
        ~Board() {}

        int &operator[](const City &c);

        bool is_clean();
        void remove_cures();
        void remove_stations();
        void graf();
        bool is_neighbor(City &source, City &dest);
        bool get_research_station(City &current);
        void set_research_station(City &current);
        void set_cure(Color &color);
        bool get_cure(Color &color);
        void set_treat(City &current);
        int get_val_diseas(City &current);
        std::set<City> &get_neighbors(City &current);

        Color &get_city_color(City &current);
        std::string get_city_name(City &city);

        friend std::ostream &operator<<(std::ostream &out, Board &board);
    };

}