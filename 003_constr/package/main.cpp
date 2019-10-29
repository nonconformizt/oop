#include <iostream>
#include <list>
#include "./package.class.cpp"
#include "./package.utils.cpp"
using namespace std;



int main()
{
    list<Package> * pkgs = readPackageList();

    for (auto & pkg : *pkgs)
        pkg.print();

    cout << "\nAverage weight: " << packageAverageWeight(pkgs) << endl;
    cout << "\nAverage cost: " << packageAverageCost(pkgs) << endl;

    findPackageForReceiver(pkgs);

    return 0;
}

