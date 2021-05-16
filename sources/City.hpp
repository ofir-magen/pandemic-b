#pragma once
#include <iostream>
#include <type_traits>
#include <map>
#include <set>
namespace pandemic
{
    enum City
    {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };

    // inline std::string city_string(City city)
    // {
    //     if (city == Algiers)
    //     {
    //         return "Algiers";
    //     }
    //     if (city == Atlanta)
    //     {
    //         return "Atlanta";
    //     }
    //     if (city == Baghdad)
    //     {
    //         return "Baghdad";
    //     }
    //     if (city == Bangkok)
    //     {
    //         return "Bangkok";
    //     }
    //     if (city == Beijing)
    //     {
    //         return "Beijing";
    //     }
    //     if (city == Bogota)
    //     {
    //         return "Bogota";
    //     }
    //     if (city == BuenosAires)
    //     {
    //         return "BuenosAires";
    //     }
    //     if (city == Cairo)
    //     {
    //         return "Cairo";
    //     }
    //     if (city == Chennai)
    //     {
    //         return "Chennai";
    //     }
    //     if (city == Chicago)
    //     {
    //         return "Chicago";
    //     }
    //     if (city == Delhi)
    //     {
    //         return "Delhi";
    //     }
    //     if (city == Essen)
    //     {
    //         return "Essen";
    //     }
    //     if (city == HoChiMinhCity)
    //     {
    //         return "HoChiMinhCity";
    //     }
    //     if (city == HongKong)
    //     {
    //         return "HongKong";
    //     }
    //     if (city == Istanbul)
    //     {
    //         return "Istanbul";
    //     }
    //     if (city == Jakarta)
    //     {
    //         return "Jakarta";
    //     }
    //     if (city == Johannesburg)
    //     {
    //         return "Johannesburg";
    //     }
    //     if (city == Karachi)
    //     {
    //         return "Karachi";
    //     }
    //     if (city == KePasio)
    //     {
    //         return "KePasio";
    //     }
    //     if (city == Khartoum)
    //     {
    //         return "Khartoum";
    //     }
    //     if (city == Kinshasa)
    //     {
    //         return "Kinshasa";
    //     }
    //     if (city == Kolkata)
    //     {
    //         return "Kolkata";
    //     }
    //     if (city == Lagos)
    //     {
    //         return "Lagos";
    //     }
    //     if (city == Lima)
    //     {
    //         return "Lima";
    //     }
    //     if (city == London)
    //     {
    //         return "London";
    //     }
    //     if (city == LosAngeles)
    //     {
    //         return "LosAngeles";
    //     }
    //     if (city == Madrid)
    //     {
    //         return "Madrid";
    //     }
    //     if (city == Manila)
    //     {
    //         return "Manila";
    //     }
    //     if (city == MexicoCity)
    //     {
    //         return "MexicoCity";
    //     }
    //     if (city == Miami)
    //     {
    //         return "Miami";
    //     }
    //     if (city == Milan)
    //     {
    //         return "Milan";
    //     }
    //     if (city == Montreal)
    //     {
    //         return "Montreal";
    //     }
    //     if (city == Moscow)
    //     {
    //         return "Moscow";
    //     }
    //     if (city == Mumbai)
    //     {
    //         return "Mumbai";
    //     }
    //     if (city == NewYork)
    //     {
    //         return "NewYork";
    //     }
    //     if (city == Osaka)
    //     {
    //         return "Osaka";
    //     }
    //     if (city == Paris)
    //     {
    //         return "Paris";
    //     }
    //     if (city == Riyadh)
    //     {
    //         return "Riyadh";
    //     }
    //     if (city == SanFrancisco)
    //     {
    //         return "SanFrancisco";
    //     }
    //     if (city == Santiago)
    //     {
    //         return "Santiago";
    //     }
    //     if (city == SaoPaulo)
    //     {
    //         return "SaoPaulo";
    //     }
    //     if (city == Seoul)
    //     {
    //         return "Seoul";
    //     }
    //     if (city == Shanghai)
    //     {
    //         return "Shanghai";
    //     }
    //     if (city == StPetersburg)
    //     {
    //         return "StPetersburg";
    //     }
    //     if (city == Sydney)
    //     {
    //         return "Sydney";
    //     }
    //     if (city == Taipei)
    //     {
    //         return "Taipei";
    //     }
    //     if (city == Tehran)
    //     {
    //         return "Tehran";
    //     }
    //     if (city == Tokyo)
    //     {
    //         return "Tokyo";
    //     }
    //     if (city == Washington)
    //     {
    //         return "Washington";
    //     }
    //     return "no city at all";
    // }
}