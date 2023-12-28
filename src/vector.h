#pragma once
#include <string>
#include <vector>

class Vector {
    public:
        std::vector<int> vect;
        double mag;

        Vector();
        Vector(int d);
        Vector(std::vector<int> vect);

        std::string toString();

        Vector operator+(const Vector& o) const;
        Vector operator-(const Vector& o) const;
        Vector operator*(const Vector& o) const;
        Vector operator/(const Vector& o) const;
        Vector operator*(double n) const;
        Vector operator/(double n) const;

        void operator+=(const Vector& o);
        void operator-=(const Vector& o);
        void operator*=(const Vector& o);
        void operator/=(const Vector& o);
        void operator*=(double n);
        void operator/=(double n);

        bool operator==(const Vector &o) const;

    private:
        Vector(std::vector<int> vect, double mag);

        void calcMag();
};