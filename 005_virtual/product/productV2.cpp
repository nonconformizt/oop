#ifndef PRODUCT_CPP
#define PRODUCT_CPP
#include <string>

namespace oop
{


class Product {
protected:
    double price;
    double discount;
    std::string name;

public: 
    Product() {}
    void setPrice(double p) { price = p; } 
    double getSalePrice() const { return price - (0.01 * price * discount); }
    std::string getName () const { return name; }
};


class Milk: public Product {
public: 
    Milk() : Product() {
        discount = 10.0;
        name = "MILK";
    }
};


class Bread: public Product {
public: 
    Bread() : Product() {
        discount = 5.0;
        name = "BREAD";
    }
};


class Pasta: public Product {
public: 
    Pasta() : Product() {
        discount = 33.0;
        name = "PASTA";
    }
};


class Rice: public Product {
public: 
    Rice() : Product() {
        discount = 3.0;
        name = "RICE";
    }
};


class Butter: public Product {
public: 
    Butter() : Product() {
        discount = 24.0;
        name = "BUTTER";
    }
};








} // namespace oop

#endif // PRODUCT_CPP