#include <iostream>
#include "./booking.cpp"
using namespace std;




int main ()
{
    oop::Booking hotel;
    hotel.load();

    string inp;
    bool res;
    
    while (true)
    {
        cout << "Enter single date of date range to book your place\n";
        getline(cin, inp);
        if (inp == "0") break;

        if(hotel.book(inp))
            cout << "> Booked successfully!\n";
        else 
            cout << "> Cannot book for this date. Try another range\n";
    }

}


