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

    // range_vec[0] += " 00:00:00";
    // range_vec[1] += " 23:59:59";

    // std::cout << "!" << range_vec[0] << "\n";
    // std::cout << "!" << range_vec[1] << "\n";
    std::array<tm, 2> range_tm;
    strptime(range_vec[0].c_str(), "%d/%m/%Y %H:%M:%S", &range_tm[0]);
    strptime(range_vec[1].c_str(), "%d/%m/%Y %H:%M:%S", &range_tm[1]);

    // convert to timestamp
    std::array<time_t, 2> range_t;
    range_t[0] = mktime(&range_tm[0]);
    range_t[1] = mktime(&range_tm[1]);

    // std::cout << range_tm[0].tm_mday << " " << range_tm[0].tm_mon << " " << range_tm[0].tm_year << "\n"
    //           << range_tm[1].tm_mday << " " << range_tm[1].tm_mon << " " << range_tm[1].tm_year << "\n";

    // int i = 0;
    // check if booked already
    for (auto const & t: booked_t)
    {
        // cannot book
        if ((range_t[0] <= t[0] && range_t[1] >= t[0])
         || (range_t[0] <= t[1] && range_t[1] >= t[1])
         || (range_t[0] >= t[0] && range_t[1] <= t[1])) {
            // std::cout << "Booking of range \n" 
            // << range_tm[0].tm_mday << " " << range_tm[0].tm_mon << " " << range_tm[0].tm_year << "\n"
            // << range_tm[1].tm_mday << " " << range_tm[1].tm_mon << " " << range_tm[1].tm_year << "\n";
            // std::cout << "Failed for range: \n" 
            // << booked[i][0].tm_mday << " " << booked[i][0].tm_mon << " " << booked[i][0].tm_year << std::endl 
            // << booked[i][1].tm_mday << " " << booked[i][1].tm_mon << " " << booked[i][1].tm_year << std::endl;
            return false;
        }
        // i++;
    }


    booked.push_back(range_tm);
    booked_t.push_back(range_t);

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