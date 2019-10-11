#include <iostream>
#include <cmath>


class Vector3D
{
private:
    double x;
    double y;
    double z;

 public:
    Vector3D(double x,double y,double z);
    Vector3D();
    friend Vector3D operator+(const Vector3D& left, const Vector3D& right);
    friend Vector3D operator*(double a);
    friend Vector3D operator-(const Vector3D& left, const Vector3D& right);
    friend bool operator>(const Vector3D& left, const Vector3D& right);
    friend bool operator<(const Vector3D& left, const Vector3D& right);
    friend bool operator==(const Vector3D& left, const Vector3D& right);
    Vector3D crossProduct(const Vector3D& vector);
    void lambdaProduct(double lambda);
    double scalarProduct(const Vector3D& vector);
    const double getLength() const ;
    double getAngle( Vector3D& vector);
    double getX();
    double getY();
    double getZ();

};
    Vector3D operator""_vect3D(long double n);
