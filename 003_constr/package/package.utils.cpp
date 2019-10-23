#ifndef PACKAGE_UTILS
#define PACKAGE_UTILS

#include "./package.class.cpp"
#include <list>
#include <sstream>
#include <fstream>
using namespace std;


Package * readPackage(string line)
{
    stringstream stream(line);

    string name;
    unsigned int date;
    string sender;
    string receiver;
    float weight;
    unsigned int cost;

    stream >> name >> date >> sender >> receiver >> weight >> cost;

    auto pkg = new Package(name, date, sender, receiver, weight, cost);

    return pkg;
}


list<Package> * readPackageList()
{
    auto res = new list<Package>;

    // TODO: get filename
    ifstream input("test.txt");
    string tmp;

    while (getline(input, tmp)) 
        res->push_back(*readPackage(tmp));

    return res;
}


double packageAverageWeight(list<Package> * pkgs)
{
    double res = 0.0;

    for (auto & pkg : *pkgs)
        res += pkg.getWeight();
    res /= pkgs->size();

    return res;
}


double packageAverageCost(list<Package> * pkgs)
{
    double res = 0.0;

    for (auto & pkg : *pkgs)
        res += pkg.getCost();
    res /= pkgs->size();

    return res;
}



#endif