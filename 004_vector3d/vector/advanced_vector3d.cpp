#ifndef ADVANCED_VEC
#define ADVANCED_VEC
#include "./vector3d.cpp"
#include <iostream>
#include <math.h>

namespace oop
{


class AdvancedVector3D : public Vector3D {

public: 
    AdvancedVector3D ()
        : Vector3D() {};
    AdvancedVector3D (double x1, double y1, double z1, double x2, double y2, double z2)
        : Vector3D(x1, y1, z1, x2, y2, z2) {};

    double length();
    double scalarProd(AdvancedVector3D * vec);
    double angleCos(AdvancedVector3D * vec);

    using Vector3D::operator=;


};


double AdvancedVector3D::length()
{
    return sqrt(
        (end.x - begin.x)*(end.x - begin.x) +
        (end.y - begin.y)*(end.y - begin.y) +
        (end.z - begin.z)*(end.z - begin.z)
    );
}


double AdvancedVector3D::scalarProd(AdvancedVector3D * vec)
{
    return
        (end.x - begin.x)*(vec->end.x - vec->begin.x) +
        (end.y - begin.y)*(vec->end.y - vec->begin.y) +
        (end.z - begin.z)*(vec->end.z - vec->begin.z);
}


double AdvancedVector3D::angleCos(AdvancedVector3D * vec)
{
    return scalarProd(vec) / (length() * vec->length());
}



}

#endif // ADVANCED_VEC