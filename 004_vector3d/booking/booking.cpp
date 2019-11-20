    #ifndef BOOKING
#define BOOKING

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <time.h>
#include "./utils.cpp"

namespace oop
{


class Booking {

private:
    std::vector <std::array<tm, 2>> booked;
    std::vector <std::array<time_t, 2>> booked_t;

public:
    bool book(std::string range);
    void load();

};



bool Booking::book(std::string range)
{
    auto range_vec = split(range);
    if (range_vec.size() == 1)
        range_vec.push_back(range);

    std::array<tm, 2> range_tm;
    strptime(range_vec[0].c_str(), "%d/%m/%Y", &range_tm[0]);
    strptime(range_vec[1].c_str(), "%d/%m/%Y", &range_tm[1]);
    range_tm[1].tm_hour = 23;
    range_tm[1].tm_min = 59;
    range_tm[1].tm_sec = 59;

    // convert to timestamp
    std::array<time_t, 2> range_t;
    range_t[0] = mktime(&range_tm[0]);
    range_t[1] = mktime(&range_tm[1]);

    // check if booked already
    for (auto const & t: booked_t)
    {
        // cannot book
        if ((range_t[0] <= t[0] && range_t[1] >= t[0])
         || (range_t[0] <= t[1] && range_t[1] >= t[1])
         || (range_t[0] >= t[0] && range_t[1] <= t[1]))
            return false;
    }


    booked.push_back(range_tm);
    booked_t.push_back(range_t);

    // booked successfully!
    return true;
}




void Booking::load()
{
    std::ifstream input("data.txt");

    if (!input.is_open())
        throw "Cannot open file!";

    std::string line;
    while (std::getline(input, line))
        book(line);

}







} // namespace oop

#endif // BOOKING