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
    Product () {}
    void setPrice(double p) { price = p; } 
    std::string getName () const { return name; }
    virtual double getSalePrice() const = 0;
};


class Milk: public Product {
public: 
    Milk () : Product() {
        discount = 10.0;
        name = "MILK";
    }
    double getSalePrice() const {
        return price - (0.01 * price * discount);
    }
};


class Bread: public Product {
public: 
    Bread () : Product() {
        discount = 5.0;
        name = "BREAD";
    }
    double getSalePrice() const {
        return price - (0.01 * price * discount);
    }
};


class Pasta: public Product {
public: 
    Pasta () : Product() {
        discount = 33.0;
        name = "PASTA";
    }
    double getSalePrice() const {
        return price - (0.01 * price * discount);
    }
};


class Rice: public Product {
public: 
    Rice () : Product() {
        discount = 3.0;
        name = "RICE";
    }
    double getSalePrice() const {
        return price - (0.01 * price * discount);
    }
};


class Butter: public Product {
public: 
    Butter () : Product() {
        discount = 24.0;
        name = "BUTTER";
    }
    double getSalePrice() const {
        return price - (0.01 * price * discount);
    }
};








} // namespace oop

#endif // PRODUCT_CPP