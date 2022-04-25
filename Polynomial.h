#include <math.h>  
#include "Dot.h"
#include <iostream>

    class Polynomial {
    private:
		double X = 10000;
		double Y = 0;
		std::string funx[100] = {""};
        int funcIndex = 0;
	public:
		Polynomial (Dot d);

		void SetX(double X);
		void SetY(double Y);
		double getX() { return X; }
		std::string* getFunx() {
			std::string *p = funx;
			return p;
		}
		int findZeros(double nr);
		int findOrder();
		void findPolynomials();
		void findValue();
	};
