#ifndef PRODUCT_CPP
#define PRODUCT_CPP

namespace oop
{


class Product {
protected:
    double price;
    double discount;

public: 
    Product (double p) {
        price = p;
    }
    virtual double getSalePrice() const;
};


class Milk: public Product {
public: 
    Milk (double p) : Product(p) {
        discount = 10.0;
    }
    double getSalePrice() {
        return price * (0.01 * discount);
    }
};


class Bread: public Product {
public: 
    Bread (double p) : Product(p) {
        discount = 5.0;
    }
    double getSalePrice() {
        return price * (0.01 * discount);
    }
};


class Pasta: public Product {
public: 
    Pasta (double p) : Product(p) {
        discount = 33.0;
    }
    double getSalePrice() {
        return price * (0.01 * discount);
    }
};


class Rice: public Product {
public: 
    Rice (double p) : Product(p) {
        discount = 3.0;
    }
    double getSalePrice() {
        return price * (0.01 * discount);
    }
};


class Butter: public Product {
public: 
    Butter (double p) : Product(p) {
        discount = 24.0;
    }
    double getSalePrice() {
        return price * (0.01 * discount);
    }
};








} // namespace oop

#endif // PRODUCT_CPP