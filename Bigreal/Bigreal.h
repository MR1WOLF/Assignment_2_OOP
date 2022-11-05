#ifndef BIGREAL_H
#define BIGREAL_H
#include "BigDecimalIntClass.h"

class Bigreal{
    private:
        BigDecimalInt integer;
        int point;
    public:
        Bigreal(string bigreal);
        Bigreal(double bigdouble = 0.0);
        Bigreal(BigDecimalInt biginteger);
        BigDecimalInt getNumber();
        int getPoint();
        Bigreal operator+ (Bigreal other);
        Bigreal operator- (Bigreal other);
        Bigreal operator= (Bigreal other);
        friend ostream& operator<<(ostream& os, Bigreal realnum);
};

#endif