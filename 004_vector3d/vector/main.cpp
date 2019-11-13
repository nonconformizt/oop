#include <iostream>
#include "./vector3d.cpp"
#include "./advanced_vector3d.cpp"
using namespace std;


int main ()
{
    oop::AdvancedVector3D vec1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    oop::AdvancedVector3D vec2(2.0, 10.0, -5.0, 14.0, -9.0, 0.0);
    
    cout << "Vector 1: \n" << vec1 << endl;
    cout << "Vector 2: \n" << vec2 << endl;

    oop::AdvancedVector3D vec3;
    
    vec3 = vec1 + vec2;
    cout << "\nSum of vectors: \n" << vec3 << endl;
    
    vec3 = vec1 - vec2;
    cout << "\nDifference of vectors: \n" << vec3 << endl;

    cout << "Length of vec1: " << vec1.length() << endl;

    cout << "Scalar product of vec1 and vec2: " << vec1.scalarProd(&vec2) << endl;

    cout << "Cosine of angle between vec1 and vec2: " << vec1.angleCos(&vec2) << endl;


}
