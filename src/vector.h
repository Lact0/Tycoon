#pragma once

class Vector {
    public:
        int* vect;
        int d;
        double mag;

        Vector();
        Vector(int d);
        Vector(int* vect, int d);

        Vector operator+(const Vector& o) const;
        Vector operator-(const Vector& o) const;
        Vector operator*(double n) const;
        Vector operator/(double n) const;

        void operator+=(const Vector& o);
        void operator-=(const Vector& o);
        void operator*=(double n);
        void operator/=(double n);

    private:
        Vector(int* vect, int d, double mag);

        void calcMag();
};