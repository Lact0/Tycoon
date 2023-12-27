#include "vector.h"
#include <cmath>
#include <iostream>

void Vector::calcMag() {
    mag = 0;
    for(int i = 0; i < d; i++) {
        mag += vect[i] * vect[i];
    }
    mag = sqrt(mag);
}
Vector::Vector() {
    d = 2;
    mag = 0;
    vect = new int[2];
}

Vector::Vector(int d) {
    this->d = d;
    mag = 0;
    vect = new int[d];
}

Vector::Vector(int* vect, int d) {
    this->d = d;
    this->vect = vect;
    calcMag();
}

Vector::Vector(int* vect, int d, double mag) {
    this->d = d;
    this->vect = vect;
    this->mag = mag;
}

Vector Vector::operator+(const Vector& o) const {
    int s = o.d < d? o.d : d;
    int l = d > o.d? d : o.d;
    int* newVect = new int[l];
    for(int i = 0; i < s; i++) {
        newVect[i] = vect[i] + o.vect[i];
    }
    for(int i = s; i < l; i++) {
        newVect[i] = d > o.d? vect[i] : o.vect[i];
    }
    return Vector(newVect, l);
}

Vector Vector::operator-(const Vector& o) const {
    int s = o.d < d? o.d : d;
    int l = d > o.d? d : o.d;
    int* newVect = new int[l];
    for(int i = 0; i < s; i++) {
        newVect[i] = vect[i] - o.vect[i];
    }
    for(int i = s; i < l; i++) {
        newVect[i] = d > o.d? vect[i] : -o.vect[i];
    }
    return Vector(newVect, l);
}

Vector Vector::operator*(double n) const {
    int* newVect = new int[d];
    for(int i = 0; i < d; i++) {
        newVect[i] = vect[i] * n;
    }
    return Vector(newVect, d, mag * n);
}

Vector Vector::operator/(double n) const {
    if(n == 0) {
        return Vector(d);
    }
    int* newVect = new int[d];
    for(int i = 0; i < d; i++) {
        newVect[i] = vect[i] / n;
    }
    return Vector(newVect, d, mag / n);
}

void Vector::operator+=(const Vector& o) {
    for(int i = 0; i < o.d < d? o.d : d; i++) {
        vect[i] += o.vect[i];
    }
}

void Vector::operator-=(const Vector& o) {
    for(int i = 0; i < o.d < d? o.d : d; i++) {
        vect[i] -= o.vect[i];
    }
}

void Vector::operator*=(double n) {
    for(int i = 0; i < d; i++) {
        vect[i] *= n;
    }
}

void Vector::operator/=(double n) {
    if(n == 0) {
        for(int i = 0; i < d; i++) {
            vect[i] = 0;
        }
        return;
    }
    for(int i = 0; i < d; i++) {
        vect[i] /= n;
    }
}