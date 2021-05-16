
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>
#include <fstream>

using namespace pandemic;

using namespace std;

namespace pandemic
{
  Board::Board()
  {

    this->NodeData[Algiers].neighbors_citys = {Madrid, Paris, Istanbul, Cairo};
    this->NodeData[Algiers].name_city = "Algiers";
    this->NodeData[Algiers].diseas_val = 0;
    this->NodeData[Algiers].color = Black;

    this->NodeData[Atlanta].neighbors_citys = {Chicago, Miami, Washington};
    this->NodeData[Atlanta].name_city = "Atlanta";
    this->NodeData[Atlanta].diseas_val = 0;
    this->NodeData[Atlanta].color = Blue;

    this->NodeData[Baghdad].neighbors_citys = {Tehran, Istanbul, Cairo, Riyadh, Karachi};
    this->NodeData[Baghdad].name_city = "Baghdad";
    this->NodeData[Baghdad].diseas_val = 0;
    this->NodeData[Baghdad].color = Black;

    this->NodeData[Bangkok].neighbors_citys = {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong};
    this->NodeData[Bangkok].name_city = "Bangkok";
    this->NodeData[Bangkok].diseas_val = 0;
    this->NodeData[Bangkok].color = Red;

    this->NodeData[Beijing].neighbors_citys = {Shanghai, Seoul};
    this->NodeData[Beijing].name_city = "Beijing";
    this->NodeData[Beijing].diseas_val = 0;
    this->NodeData[Beijing].color = Red;

    this->NodeData[Bogota].neighbors_citys = {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires};
    this->NodeData[Bogota].name_city = "Bogota";
    this->NodeData[Bogota].diseas_val = 0;
    this->NodeData[Bogota].color = Yellow;

    this->NodeData[BuenosAires].neighbors_citys = {Bogota, SaoPaulo};
    this->NodeData[BuenosAires].name_city = "BuenosAires";
    this->NodeData[BuenosAires].diseas_val = 0;
    this->NodeData[BuenosAires].color = Yellow;

    this->NodeData[Cairo].neighbors_citys = {Algiers, Istanbul, Baghdad, Khartoum, Riyadh};
    this->NodeData[Cairo].name_city = "Cairo";
    this->NodeData[Cairo].diseas_val = 0;
    this->NodeData[Cairo].color = Black;

    this->NodeData[Chennai].neighbors_citys = {Mumbai, Delhi, Kolkata, Bangkok, Jakarta};
    this->NodeData[Chennai].name_city = "Chennai";
    this->NodeData[Chennai].diseas_val = 0;
    this->NodeData[Chennai].color = Black;

    this->NodeData[Chicago].neighbors_citys = {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal};
    this->NodeData[Chicago].name_city = "Chicago";
    this->NodeData[Chicago].diseas_val = 0;
    this->NodeData[Chicago].color = Blue;

    this->NodeData[Delhi].neighbors_citys = {Tehran, Karachi, Mumbai, Chennai, Kolkata};
    this->NodeData[Delhi].name_city = "Delhi";
    this->NodeData[Delhi].diseas_val = 0;
    this->NodeData[Delhi].color = Black;

    this->NodeData[Essen].neighbors_citys = {London, Paris, Milan, StPetersburg};
    this->NodeData[Essen].name_city = "Essen";
    this->NodeData[Essen].diseas_val = 0;
    this->NodeData[Essen].color = Blue;

    this->NodeData[HoChiMinhCity].neighbors_citys = {Jakarta, Bangkok, HongKong, Manila};
    this->NodeData[HoChiMinhCity].name_city = "HoChiMinhCity";
    this->NodeData[HoChiMinhCity].diseas_val = 0;
    this->NodeData[HoChiMinhCity].color = Red;

    this->NodeData[HongKong].neighbors_citys = {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei};
    this->NodeData[HongKong].name_city = "HongKong";
    this->NodeData[HongKong].diseas_val = 0;
    this->NodeData[HongKong].color = Red;

    this->NodeData[Istanbul].neighbors_citys = {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow};
    this->NodeData[Istanbul].name_city = "Istanbul";
    this->NodeData[Istanbul].diseas_val = 0;
    this->NodeData[Istanbul].color = Black;

    this->NodeData[Jakarta].neighbors_citys = {Chennai, Bangkok, HoChiMinhCity, Sydney};
    this->NodeData[Jakarta].name_city = "Jakarta";
    this->NodeData[Jakarta].diseas_val = 0;
    this->NodeData[Jakarta].color = Red;

    this->NodeData[Johannesburg].neighbors_citys = {Kinshasa, Khartoum};
    this->NodeData[Johannesburg].name_city = "Johannesburg";
    this->NodeData[Johannesburg].diseas_val = 0;
    this->NodeData[Johannesburg].color = Yellow;

    this->NodeData[Karachi].neighbors_citys = {Tehran, Baghdad, Riyadh, Mumbai, Delhi};
    this->NodeData[Karachi].name_city = "Karachi";
    this->NodeData[Karachi].diseas_val = 0;
    this->NodeData[Karachi].color = Black;

    this->NodeData[Khartoum].neighbors_citys = {Cairo, Lagos, Kinshasa, Johannesburg};
    this->NodeData[Khartoum].name_city = "Khartoum";
    this->NodeData[Khartoum].diseas_val = 0;
    this->NodeData[Khartoum].color = Yellow;

    this->NodeData[Kinshasa].neighbors_citys = {Lagos, Khartoum, Johannesburg};
    this->NodeData[Kinshasa].name_city = "Kinshasa";
    this->NodeData[Kinshasa].diseas_val = 0;
    this->NodeData[Kinshasa].color = Yellow;

    this->NodeData[Kolkata].neighbors_citys = {Delhi, Chennai, Bangkok, HongKong};
    this->NodeData[Kolkata].name_city = "Kolkata";
    this->NodeData[Kolkata].diseas_val = 0;
    this->NodeData[Kolkata].color = Black;

    this->NodeData[Lagos].neighbors_citys = {SaoPaulo, Khartoum, Kinshasa};
    this->NodeData[Lagos].name_city = "Lagos";
    this->NodeData[Lagos].diseas_val = 0;
    this->NodeData[Lagos].color = Yellow;

    this->NodeData[Lima].neighbors_citys = {MexicoCity, Bogota, Santiago};
    this->NodeData[Lima].name_city = "Lima";
    this->NodeData[Lima].diseas_val = 0;
    this->NodeData[Lima].color = Yellow;

    this->NodeData[London].neighbors_citys = {NewYork, Madrid, Essen, Paris};
    this->NodeData[London].name_city = "London";
    this->NodeData[London].diseas_val = 0;
    this->NodeData[London].color = Blue;

    this->NodeData[LosAngeles].neighbors_citys = {SanFrancisco, Chicago, MexicoCity, Sydney};
    this->NodeData[LosAngeles].name_city = "LosAngeles";
    this->NodeData[LosAngeles].diseas_val = 0;
    this->NodeData[LosAngeles].color = Yellow;

    this->NodeData[Madrid].neighbors_citys = {London, NewYork, Paris, SaoPaulo, Algiers};
    this->NodeData[Madrid].name_city = "Madrid";
    this->NodeData[Madrid].diseas_val = 0;
    this->NodeData[Madrid].color = Blue;

    this->NodeData[Manila].neighbors_citys = {Taipei, SanFrancisco, HoChiMinhCity, Sydney,HongKong};
    this->NodeData[Manila].name_city = "Manila";
    this->NodeData[Manila].diseas_val = 0;
    this->NodeData[Manila].color = Red;

    this->NodeData[MexicoCity].neighbors_citys = {LosAngeles, Chicago, Miami, Lima, Bogota};
    this->NodeData[MexicoCity].name_city = "MexicoCity";
    this->NodeData[MexicoCity].diseas_val = 0;
    this->NodeData[MexicoCity].color = Yellow;

    this->NodeData[Miami].neighbors_citys = {Atlanta, MexicoCity, Washington, Bogota};
    this->NodeData[Miami].name_city = "Miami";
    this->NodeData[Miami].diseas_val = 0;
    this->NodeData[Miami].color = Yellow;

    this->NodeData[Milan].neighbors_citys = {Essen, Paris, Istanbul};
    this->NodeData[Milan].name_city = "Milan";
    this->NodeData[Milan].diseas_val = 0;
    this->NodeData[Milan].color = Blue;

    this->NodeData[Montreal].neighbors_citys = {Chicago, Washington, NewYork};
    this->NodeData[Montreal].name_city = "Montreal";
    this->NodeData[Montreal].diseas_val = 0;
    this->NodeData[Montreal].color = Blue;

    this->NodeData[Moscow].neighbors_citys = {StPetersburg, Istanbul, Tehran};
    this->NodeData[Moscow].name_city = "Moscow";
    this->NodeData[Moscow].diseas_val = 0;
    this->NodeData[Moscow].color = Black;

    this->NodeData[Mumbai].neighbors_citys = {Karachi, Delhi, Chennai};
    this->NodeData[Mumbai].name_city = "Mumbai";
    this->NodeData[Mumbai].diseas_val = 0;
    this->NodeData[Mumbai].color = Black;

    this->NodeData[NewYork].neighbors_citys = {Montreal, Washington, London, Madrid};
    this->NodeData[NewYork].name_city = "NewYork";
    this->NodeData[NewYork].diseas_val = 0;
    this->NodeData[NewYork].color = Blue;

    this->NodeData[Osaka].neighbors_citys = {Taipei, Tokyo};
    this->NodeData[Osaka].name_city = "Osaka";
    this->NodeData[Osaka].diseas_val = 0;
    this->NodeData[Osaka].color = Red;

    this->NodeData[Paris].neighbors_citys = {Algiers, Essen, Madrid, Milan, London};
    this->NodeData[Paris].name_city = "Paris";
    this->NodeData[Paris].diseas_val = 0;
    this->NodeData[Paris].color = Blue;

    this->NodeData[Riyadh].neighbors_citys = {Baghdad, Cairo, Karachi};
    this->NodeData[Riyadh].name_city = "Riyadh";
    this->NodeData[Riyadh].diseas_val = 0;
    this->NodeData[Riyadh].color = Black;

    this->NodeData[SanFrancisco].neighbors_citys = {LosAngeles, Chicago, Tokyo, Manila};
    this->NodeData[SanFrancisco].name_city = "SanFrancisco";
    this->NodeData[SanFrancisco].diseas_val = 0;
    this->NodeData[SanFrancisco].color = Blue;

    this->NodeData[Santiago].neighbors_citys = {Lima};
    this->NodeData[Santiago].name_city = "Santiago";
    this->NodeData[Santiago].diseas_val = 0;
    this->NodeData[Santiago].color = Yellow;

    this->NodeData[SaoPaulo].neighbors_citys = {Bogota, BuenosAires, Lagos, Madrid};
    this->NodeData[SaoPaulo].name_city = "SaoPaulo";
    this->NodeData[SaoPaulo].diseas_val = 0;
    this->NodeData[SaoPaulo].color = Yellow;

    this->NodeData[Seoul].neighbors_citys = {Beijing, Shanghai, Tokyo};
    this->NodeData[Seoul].name_city = "Seoul";
    this->NodeData[Seoul].diseas_val = 0;
    this->NodeData[Seoul].color = Red;

    this->NodeData[Shanghai].neighbors_citys = {Beijing, HongKong, Taipei, Seoul, Tokyo};
    this->NodeData[Shanghai].name_city = "Shanghai";
    this->NodeData[Shanghai].diseas_val = 0;
    this->NodeData[Shanghai].color = Red;

    this->NodeData[StPetersburg].neighbors_citys = {Essen, Istanbul, Moscow};
    this->NodeData[StPetersburg].name_city = "StPetersburg";
    this->NodeData[StPetersburg].diseas_val = 0;
    this->NodeData[StPetersburg].color = Blue;

    this->NodeData[Sydney].neighbors_citys = {Jakarta, Manila, LosAngeles};
    this->NodeData[Sydney].name_city = "Sydney";
    this->NodeData[Sydney].diseas_val = 0;
    this->NodeData[Sydney].color = Red;

    this->NodeData[Taipei].neighbors_citys = {Shanghai, HongKong, Osaka, Manila};
    this->NodeData[Taipei].name_city = "SyTaipeidney";
    this->NodeData[Taipei].diseas_val = 0;
    this->NodeData[Taipei].color = Red;

    this->NodeData[Tehran].neighbors_citys = {Baghdad, Moscow, Karachi, Delhi};
    this->NodeData[Tehran].name_city = "Tehran";
    this->NodeData[Tehran].diseas_val = 0;
    this->NodeData[Tehran].color = Black;

    this->NodeData[Tokyo].neighbors_citys = {Seoul, Shanghai, Osaka, SanFrancisco};
    this->NodeData[Tokyo].name_city = "Tokyo";
    this->NodeData[Tokyo].diseas_val = 0;
    this->NodeData[Tokyo].color = Red;

    this->NodeData[Washington].neighbors_citys = {Atlanta, NewYork, Montreal, Miami};
    this->NodeData[Washington].name_city = "Washington";
    this->NodeData[Washington].diseas_val = 0;
    this->NodeData[Washington].color = Blue;

    remove_cures();
    remove_stations();
  }

  int &Board::operator[](const City &c)
  {
    return this->NodeData[c].diseas_val;
  }

  bool Board::is_clean()
  {
    for (auto &Node : this->NodeData)
    {
      if (Node.second.diseas_val != 0) // !=0 == not clean from diseas
      {
        return false;
      }
    }
    return true;
  }

  void Board::remove_cures()
  {
    for (auto &mmedicine : this->NodeData)
    {
      mmedicine.second.medicine = false;
    }
  }

  void Board::remove_stations()
  {
    for (auto &stations : this->NodeData)
    {
      stations.second.research_station = false;
    }
  }

  std::ostream &operator<<(std::ostream &out, Board &board)
  {
    std::set<Color> Drugs_discovered;
    int size_research_station = 0;
    for (auto &node : board.NodeData)
    {
      if (node.second.research_station)
      {
        size_research_station++;
      }
      if (node.second.medicine)
      {
        Drugs_discovered = {node.second.color};
      }
      out << " [name: " << node.second.name_city << "  ,diseas_val: " << node.second.diseas_val << " ,there is research_station? : " << node.second.research_station << "] \n";
    }
    out << "\n";
    out << "size of research_station= " << size_research_station << "\n"
        << "discaverd coure= ";
    for (const auto &Drugs : Drugs_discovered)
    {
      out << Color_string(Drugs) << "  ";
    }
    return out;
  }

  bool Board::is_neighbor(City &source, City &dest)
  {
    return (NodeData[source].neighbors_citys.find(dest) != NodeData[source].neighbors_citys.end());
  }

  bool Board::get_research_station(City &current)
  {
    return (NodeData[current].research_station);
  }

  void Board::set_research_station(City &current)
  {
    NodeData[current].research_station = true;
  }

  Color &Board::get_city_color(City &current)
  {
    return NodeData[current].color;
  }

  void Board::set_cure(Color &color)
  {
    for (auto &node : NodeData)
    {
      if (node.second.color == color)
      {
        node.second.medicine = true;
      }
    }
  }

  bool Board::get_cure(Color &color)
  {
    bool rec = false;
    for (auto &node : NodeData)
    {
      if (node.second.color == color)
      {
        rec = node.second.medicine;
        break;
      }
    }
    return rec;
  }

  void Board::set_treat(City &current)
  {
    if (get_cure(get_city_color(current)))
    {
      NodeData[current].diseas_val = 0;
    }
    else
    {

      this->NodeData.at(current).diseas_val--;
    }
  }

  int Board::get_val_diseas(City &current)
  {
    return NodeData[current].diseas_val;
  }

  std::string Board::get_city_name(City &city){
    return NodeData[city].name_city;
  }

  set<City> &Board::get_neighbors(City &current)
  {
    return this->NodeData.at(current).neighbors_citys;
  }

}