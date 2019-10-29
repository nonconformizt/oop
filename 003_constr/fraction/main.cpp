#include <iostream>
#include "./fract_vector.cpp"
using namespace std;

#define VECTOR_LEN 10

int main()
{
    auto vec1 = FractionVector(VECTOR_LEN);
    auto vec2 = FractionVector(VECTOR_LEN);

    vec1.print();
    vec2.print();

    auto vec3 = vec1 + vec2;
    cout << "\nSum of vectors: \n";
    vec3.print();

    cout << "\nMultiply by 2: \n";
    vec3.times(2);
    vec3.print();

    cout << "\nMagnitude (length) of a vector = ";
    cout << vec3.magnitude() << endl;

    cout << "\nScalar product of vectors vec1 and vec2:\n";
    cout << vec1.scalar(vec2) << endl;

}