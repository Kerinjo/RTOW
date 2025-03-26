#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
        double e[3];

        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        // const applying to member function, meaning that the function
        // does not modify the state of the objects it's called on
        double operator[](int i) const { return e[i]; }
        // const here is for const-corectness, so that you can call operator[] on const vectors!
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3& v) {  
        // const here indicates, that the reference to a vec3 object passed
        // through a parameter, cannot be modified within this function 
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

#endif