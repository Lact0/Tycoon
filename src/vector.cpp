#include "vector.h"
#include <cmath>
#include <iostream>

void Vector::calcMag() {
    mag = 0;
    for(int i : vect) {
        mag += i * i;
    }
    mag = sqrt(mag);
}

Vector::Vector() {
    mag = 0;
    vect = std::vector<double>(2);
}

Vector::Vector(int d) {
    mag = 0;
    vect = std::vector<double>(d);
}

Vector::Vector(std::vector<int> vect) {
    this->vect = std::vector<double>(vect.begin(), vect.end());
    calcMag();
}

Vector::Vector(std::vector<double> vect) {
    this->vect = vect;
    calcMag();
}

Vector::Vector(std::vector<double> vect, double mag) {
    this->vect = vect;
    this->mag = mag;
}

std::string Vector::toString() {
    std::string ret = "[";
    for(int i : vect) {
        ret += std::to_string(i) + ", ";
    }
    return ret.substr(0, ret.length() - 2) + "]";
}

Vector Vector::operator+(const Vector& o) const {
    int s = o.vect.size() < vect.size()? o.vect.size() : vect.size();
    int l = vect.size() > o.vect.size()? vect.size() : o.vect.size();
    std::vector<int> newVect(l);
    for(int i = 0; i < s; i++) {
        newVect[i] = vect[i] + o.vect[i];
    }
    for(int i = s; i < l; i++) {
        newVect[i] = vect.size() > o.vect.size()? vect[i] : o.vect[i];
    }
    return Vector(newVect);
}

Vector Vector::operator-(const Vector& o) const {
    int s = o.vect.size() < vect.size()? o.vect.size() : vect.size();
    int l = vect.size() > o.vect.size()? vect.size() : o.vect.size();
    std::vector<int> newVect(l);
    for(int i = 0; i < s; i++) {
        newVect[i] = vect[i] - o.vect[i];
    }
    for(int i = s; i < l; i++) {
        newVect[i] = vect.size() > o.vect.size()? vect[i] : -o.vect[i];
    }
    return Vector(newVect);
}

Vector Vector::operator*(const Vector& o) const {
    std::vector<double> newVect = vect;
    for(int i = 0; i < vect.size(); i++) {
        newVect[i] = vect[i] * o.vect[i];
    }
    return Vector(newVect);
}

Vector Vector::operator/(const Vector& o) const {
    std::vector<double> newVect = vect;
    for(int i = 0; i < vect.size(); i++) {
        if(o.vect[i] == 0) {
            newVect[i] = 0;
        } else {
            newVect[i] = vect[i] / o.vect[i];
        }
    }
    return Vector(newVect);
}

Vector Vector::operator*(double n) const {
    std::vector<double> newVect = vect;
    for(int i = 0; i < vect.size(); i++) {
        newVect[i] = vect[i] * n;
    }
    return Vector(newVect, mag * n);
}

Vector Vector::operator/(double n) const {
    if(n == 0) {
        return Vector(vect.size());
    }
    std::vector<double> newVect = vect;
    for(int i = 0; i < vect.size(); i++) {
        newVect[i] = vect[i] / n;
    }
    return Vector(newVect, mag / n);
}

void Vector::operator+=(const Vector& o) {
    for(int i = 0; i < (o.vect.size() < vect.size()? o.vect.size() : vect.size()); i++) {
        vect[i] += o.vect[i];
    }
    calcMag();
}

void Vector::operator-=(const Vector& o) {
    for(int i = 0; i < (o.vect.size() < vect.size()? o.vect.size() : vect.size()); i++) {
        vect[i] -= o.vect[i];
    }
    calcMag();
}

void Vector::operator*=(const Vector& o) {
    for(int i = 0; i < vect.size(); i++) {
        vect[i] *= o.vect[i];
    }
    calcMag();
}

void Vector::operator/=(const Vector& o) {
    for(int i = 0; i < vect.size(); i++) {
        if(o.vect[i] == 0) {
            vect[i] = 0;
        } else {
            vect[i] /= o.vect[i];
        }
    }
    calcMag();
}

void Vector::operator*=(double n) {
    for(int i = 0; i < vect.size(); i++) {
        vect[i] *= n;
    }
    mag *= n;
}

void Vector::operator/=(double n) {
    if(n == 0) {
        vect = std::vector<double>(vect.size());
        mag = 0;
        return;
    }
    for(int i = 0; i < vect.size(); i++) {
        vect[i] /= n;
    }
    mag /= n;
}

bool Vector::operator==(const Vector &o) const {
    return vect == o.vect;
}