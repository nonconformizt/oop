#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "aircraft.cpp"
#include "functions.cpp"
using namespace std;



int main () 
{
    cout << "Choose base class: \n1. queue<Flight*>\n2.long";
    int baseclass = user_prompt(1,2);

    auto flighttree = new oop::Tree<queue<oop::Flight*>>();
    auto longtree = new oop::Tree<long>();

    cout << "Where to get data from? \n1. file\n2. keyboard\n";
    int datasource = user_prompt(1,2);

    if (datasource == 1)
    {
        cout << "Insert name of file\n";
        string filename;
        cin >> filename;
        flighttree = getFlightTree(filename);
    }

    flighttree->print();

    return 0;
}
