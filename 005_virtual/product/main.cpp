#include <iostream>
#include "product.cpp"

using namespace oop;

int main ()
{
    double temp;

    std::cout << "Insert base price of MILK:\n";
    std::cin >> temp;
    Milk milk(temp);
    std::cout << "Price with discount: " << milk.getSalePrice() << std::endl;

    std::cout << "Insert base price of BREAD:\n";
    std::cin >> temp;
    Bread bread(temp);
    std::cout << "Price with discount: " << bread.getSalePrice() << std::endl;

    std::cout << "Insert base price of PASTA:\n";
    std::cin >> temp;
    Pasta pasta(temp);
    std::cout << "Price with discount: " << pasta.getSalePrice() << std::endl;

    std::cout << "Insert base price of RICE:\n";
    std::cin >> temp;
    Rice rice(temp);
    std::cout << "Price with discount: " << rice.getSalePrice() << std::endl;

    std::cout << "Insert base price of BUTTER:\n";
    std::cin >> temp;
    Butter butter(temp);
    std::cout << "Price with discount: " << butter.getSalePrice() << std::endl;



    return 0;
}

