#ifndef PACKAGE_CLASS
#define PACKAGE_CLASS

#include <iostream>
using namespace std;

class Package
{

private:
    string name;
    unsigned int date;
    string sender;
    string receiver;
    float weight;
    unsigned int cost;

public:
    Package(string name, unsigned int date, string sender, string receiver, float weight, unsigned int cost);
    const unsigned int getWeight() { return weight; }
    const unsigned int getCost() { return cost; }
    const string getReceiver() { return receiver; }

    const void print();

};


Package::Package(string name, unsigned int date, string sender, string receiver, float weight, unsigned int cost)
{
    this->name = name;
    this->date = date;
    this->sender = sender;
    this->receiver = receiver;
    this->weight = weight;
    this->cost = cost;
}


const void Package::print()
{
    cout << "------------------\n" 
         << "Name: " << name 
         << "\nDate: " << date 
         << "\nSender: " << sender 
         << "\nReceiver: " << receiver 
         << "\nWeight: " << weight 
         << "\nCost: " << cost << endl;
}

#endif