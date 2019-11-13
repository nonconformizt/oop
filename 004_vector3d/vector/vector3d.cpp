#ifndef VECTOR_3D
#define VECTOR_3D
#include <iostream>

namespace oop
{

class Dot3D {
    public: double x, y, z;
};


class Vector3D {

protected:
    Dot3D begin;
    Dot3D end;

public:
    Vector3D() {};
    Vector3D(double x1, double y1, double z1, double x2, double y2, double z2);

    Vector3D operator + (Vector3D const &vec);
    Vector3D operator - (Vector3D const &vec);
    Vector3D operator = (Vector3D const &rhs);
    friend std::ostream & operator << (std::ostream &out, const Vector3D &vec);

};


Vector3D::Vector3D(double x1, double y1, double z1, double x2, double y2, double z2)
{
    begin.x = x1;
    begin.y = y1;
    begin.z = z1;
    end.x = x2;
    end.y = y2;
    end.z = z2;
}


Vector3D Vector3D::operator + (Vector3D const &vec)
{
    Vector3D res;
    res.begin.x = begin.x + vec.begin.x;
    res.begin.y = begin.y + vec.begin.y;
    res.begin.z = begin.z + vec.begin.z;
    
    res.end.x = end.x + vec.end.x;
    res.end.y = end.y + vec.end.y;
    res.end.z = end.z + vec.end.z;
    
    return res;
}


Vector3D Vector3D::operator = (Vector3D const &rhs)
{
    begin.x == rhs.begin.x;
    begin.y == rhs.begin.y;
    begin.z == rhs.begin.z;

    end.x == rhs.end.x;
    end.y == rhs.end.y;
    end.z == rhs.end.z;
}



Vector3D Vector3D::operator - (Vector3D const &vec)
{
    Vector3D res;
    res.begin.x = begin.x - vec.begin.x;
    res.begin.y = begin.y - vec.begin.y;
    res.begin.z = begin.z - vec.begin.z;
    res.end.x = end.x - vec.end.x;
    res.end.y = end.y - vec.end.y;
    res.end.z = end.z - vec.end .z;
    return res;
}


std::ostream & operator << (std::ostream &out, const Vector3D &vec)
{
    out << "Begin: " << vec.begin.x << " " << vec.begin.y << " " << vec.begin.z << "\n"
        << "End: " << vec.end.x << " " << vec.end.y << " " << vec.end.z << "\n";
    return out;
}










} // namespace oop

#endif // VECTOR_3D