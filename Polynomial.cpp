#include "Polynomial.h"

Polynomial::Polynomial(Dot d) {
    SetX(d.getX());
    SetY(d.getY());
    findPolynomials();
}

    void Polynomial::SetX(double X) {
        this->X = X;
    }
    void Polynomial::SetY(double Y) {
        this->Y = Y;
    }
    int Polynomial::findZeros(double nr) {
        int count = 0;
        for (nr; nr >= 10; nr /= 10)
            count++;
        return count;
    }
    int Polynomial::findOrder() {
        int funcZeros = findZeros(abs(this->Y));
        int XZeros = findZeros(abs(this->X));
        int order = funcZeros / XZeros;
        return order;
    }
    void Polynomial::findPolynomials() {
        int order = findOrder();
        this->funcIndex = order;
        double Y = this->Y;
        for(funcIndex = 0; funcIndex <= order; this->funcIndex = funcIndex + 1) {				
            findValue();
            this->Y = Y;
        }
    }
    void Polynomial::findValue() {
        int order = findOrder() - funcIndex;
        if (order < 0)
            order = 0;
        double X = this->X;
        double Y = this->Y;
        for (int i = order; i >= 1; i--)
            Y /= X;
        int roundedValue = nearbyint(Y);
        if (roundedValue >= 0)
            funx[funcIndex] += "+" + std::to_string(roundedValue) + "*x^" + std::to_string(order);
        else
            funx[funcIndex] += std::to_string(roundedValue) + "*x^" + std::to_string(order);
        double bigRoundedValue = roundedValue;
        for (int i = order; i >= 1; i--)
            bigRoundedValue = bigRoundedValue * X;
        this->Y -= bigRoundedValue;
        if (this->Y != 0)
            findValue();
    }
