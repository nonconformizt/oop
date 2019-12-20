#include <iostream>
#include "product.cpp"

using namespace oop;

int main ()
{
    Product * arr[5] = 
    {
        new Milk(),
        new Bread(),
        new Pasta(),
        new Rice(),
        new Butter()
    };
    double temp;


    for (int i = 0; i < 5; i++)
    {
        std::cout << "Insert base price of " << arr[i]->getName() << ":\n";
        std::cin >> temp;
        arr[i]->setPrice(temp);
        std::cout << "Price with discount: " << arr[i]->getSalePrice() << std::endl;
    }


    return 0;
}

