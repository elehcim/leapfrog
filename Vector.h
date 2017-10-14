#include <cmath>
#include <iostream>

class Vec {
    double _x;
    double _y;

public:
    Vec() { _x=0; _y=0; }
    Vec(double x, double y)
        { _x = x; _y = y; }

    double x() const { return _x; }
    double y() const { return _y; }

    double norm() const 
        { return sqrt(_x*_x + _y*_y); }
    
    double norm2() const
        { return _x*_x + _y*_y; }

    double norm3() const
        { double r = sqrt(_x*_x + _y*_y); return r*r*r; }

    Vec& operator+=(Vec v) {
        _x += v._x;
        _y += v._y;
        return *this;
    }
    Vec& operator-=(Vec v) {
        _x -= v._x;
        _y -= v._y;
        return *this;
    }
    Vec& operator*=(double s) {
        _x *= s;
        _y *= s;
        return *this;
    }
    Vec& operator/=(double s) {
        _x /= s;
        _y /= s;
        return *this;
    }
    
};

Vec operator+(Vec a, Vec b) { return a += b; }
Vec operator-(Vec a, Vec b) { return a -= b; }

// operations between a vector
Vec operator*(Vec a, double s) { return a *= s; }
Vec operator*(double s, Vec b) { return b *= s; }
Vec operator/(Vec a, double s) { return a /= s; }

std::ostream& operator<<(std::ostream& out, Vec a) {
    return out << "(" << a.x() << ", " << a.y() << ")";
}
