#include "Vector3D.h"

#include <iostream>
#include <cmath>


Vector3D::Vector3D(double x,double y,double z)
: x(x), y(y),z(z) {}
      Vector3D::Vector3D()
: x(0), y(0),z(0) {}
    Vector3D operator+(const Vector3D& left, const Vector3D& right) {
        Vector3D result;
        result.x = left.x+right.x;
        result.y = left.y+right.y;
        result.z = left.z+right.z;

        return result;
    }
    Vector3D operator-(const Vector3D& left, const Vector3D& right) {
        Vector3D result;
        result.x = left.x-right.x;
        result.y = left.y-right.y;
        result.z = left.z-right.z;

        return result;
    }
    bool operator>(const Vector3D& left, const Vector3D& right) {
        return left.getLength()>right.getLength();
    }
    bool operator<(const Vector3D& left, const Vector3D& right) {
        return left.getLength()<right.getLength();
    }
    bool operator==(const Vector3D& left, const Vector3D& right) {
        return (left.x==right.x && left.y==right.y && left.z==right.z);
    }
     Vector3D Vector3D::crossProduct(const Vector3D& vector) {
        Vector3D result;
        result.x = this->y*vector.z-this->z*vector.y;
        result.y = this->z*vector.x-this->x*vector.z;
        result.z = this->x*vector.y-this->y*vector.x;

        return result;
    }
   Vector3D operator*(const Vector3D& left, const double right) {
        Vector3D result;
         result.x = left.x*right;
        result.y = left.y*right;
        result.z = left.z*right;

        return result;
    }
std::ostream& operator<< (std::ostream &out, const Vector3D &vector)
{
    // Поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
    out << vector.x << " " << vector.y << " " << vector.z << "";
 
    return out;
}
    void Vector3D::lambdaProduct(double lambda) {
        this->x*=lambda;
        this->y*=lambda;
        this->z*=lambda;

    }
std::istream& operator>> (std::istream &in, Vector3D &vector)
{
    // Поскольку operator>> является другом класса Point, то мы имеем прямой доступ к членам Point
    // Обратите внимание, параметр point (объект класса Point) должен быть не константным, чтобы мы имели возможность изменить члены класса
    in >> vector.x;
    in >> vector.y;
    in >> vector.z;
 
    return in;
}
    double Vector3D::scalarProduct(const Vector3D& vector) {
        return this->x*vector.x+this->y*vector.y+this->z*vector.z;
    }
    const double Vector3D::getLength() const {
        return sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
    }
     
    double Vector3D::getAngle( Vector3D& vector)  {
        if ((vector.getLength()==0) || (this->getLength())==0) {
            return 0;
        }
            const double halfC = 180/M_PI;
           double cos1 = (this->scalarProduct(vector)/(this->getLength()*vector.getLength())) ;
           if (cos1 < -1) {
               return 180;
           }
           if (cos1>1) {
               return 0;
           }
           return halfC*acos(cos1);
      
    }

    double  Vector3D::getX() {
        return x;
    }
    double  Vector3D::getY() {
        return y;
    }
    double  Vector3D::getZ() {
        return z;
    }
    Vector3D operator""_vect3D(long double n) {
        return  Vector3D(n,n,n);
    }

