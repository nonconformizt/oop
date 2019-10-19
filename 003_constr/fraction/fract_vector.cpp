#include <iostream>
#include <vector>
#include "fraction.cpp"
using namespace std;

class FractionVector
{

private:
    vector<Fraction> vec;

public:
    FractionVector(int len);
    void print();
    void push(Fraction f) { vec.push_back(f); }
    void times(int factor);
    double magnitude();
    double scalar(FractionVector const & v);

    friend FractionVector operator + (FractionVector const & v1, FractionVector const & v2);
    friend FractionVector operator - (FractionVector const & v1, FractionVector const & v2);
};


FractionVector::FractionVector(int len)
{
    int n, m;
    for (int i = 0; i < len; i++)
    {
        n = rnd(-100, 100);
        m = rnd(-100, 100);
        vec.push_back(Fraction(n, m));
    }
}


void FractionVector::print()
{
    cout << "Vector contains: ";
    for (auto const &f : vec)
        cout << f << " ";    
    cout << endl;
}


void FractionVector::times(int factor)
{
    for (auto & f : vec)
        f.times(factor);
}


double FractionVector::magnitude()
{
    double res = 0;
    for (auto & f : vec)
        res += double(f) * double(f);
    res = sqrt(res);
    return res;
}


double FractionVector::scalar(FractionVector const & v)
{
    if (v.vec.size() != vec.size());

    double res = 0;
    for (auto & f : vec)
        res += double(f) * double(f);
    return res;
}


FractionVector operator + (FractionVector const & v1, FractionVector const & v2)
{
    auto res = FractionVector(0);

    if (v1.vec.size() != v2.vec.size())
        throw "Vectors must be of the same length!";

    for (int i = v1.vec.size() - 1; i >= 0; i--)
        res.push(v1.vec.at(i) + v2.vec.at(i));

    return res;
}


FractionVector operator - (FractionVector const & v1, FractionVector const & v2)
{
    auto res = FractionVector(0);

    if (v1.vec.size() != v2.vec.size())
        throw "Vectors must be of the same length!";


    for (int i = v1.vec.size() - 1; i >= 0; i--)
        res.push(v1.vec.at(i) - v2.vec.at(i));
}
