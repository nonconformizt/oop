#include <iostream>
#include "./util.cpp"
using namespace std;


class Fraction
{

private:
    int num, denum;
    void reduce();
    void normalize();

public:
    Fraction(int n, int d);

    friend Fraction operator + (Fraction const & f1, Fraction const & f2);
    friend Fraction operator - (Fraction const & f1, Fraction const & f2);
    friend Fraction operator * (Fraction const & f1, Fraction const & f2);
    friend Fraction operator / (Fraction const & f1, Fraction const & f2);
    friend ostream & operator << (ostream &out, const Fraction &f);
    friend istream & operator >> (istream &inp, Fraction &f);
    
    operator double() const { return (double(num)/double(denum)); }

    string to_string() const { return std::to_string(num) + "/" + std::to_string(denum); }
    void times(int factor) { num *= factor; reduce(); }

};


Fraction::Fraction(int n, int d)
{
    num = n; 
    denum = d;
    reduce();
}


void Fraction::reduce()
{
    int div = gcd(num, denum);
    num /= div;
    denum /= div;
    normalize();
}


void Fraction::normalize()
{
    // very slow, but simple
    num = sgn(num) * sgn(denum) * abs(num);
    denum = abs(denum);
}


Fraction operator + (Fraction const & f1, Fraction const & f2)
{
    auto res = Fraction(
        (f1.num * f2.denum) + (f2.num * f1.denum), 
        f1.denum * f2.denum
    );
    res.reduce();
    return res;
}


Fraction operator - (Fraction const & f1, Fraction const & f2)
{
    auto res = Fraction(
        (f1.num * f2.denum) - (f2.num * f1.denum), 
        f1.denum * f2.denum
    );
    res.reduce();
    return res;
}


Fraction operator * (Fraction const & f1, Fraction const & f2)
{
    auto res = Fraction(
        f1.num * f2.num, 
        f1.denum * f2.denum
    );
    res.reduce();
    return res;
}


Fraction operator / (Fraction const & f1, Fraction const & f2)
{
    auto res = Fraction(
        f1.num * f2.denum, 
        f2.denum * f1.num
    );
    res.reduce();
    return res;
}


ostream & operator << (ostream &out, const Fraction &f) 
{
    out << f.to_string();
    return out;
}


istream & operator >> (istream &inp, Fraction &f)
{
    cout << "Enter numerator: ";
    inp >> f.num;
    cout << "Enter denominator: ";
    inp >> f.denum;
    f.reduce();
    return inp;
}
