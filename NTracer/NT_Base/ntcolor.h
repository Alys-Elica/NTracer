#ifndef LTCOLOR_H
#define LTCOLOR_H

class NTColor {
public:
    NTColor(double r, double g, double b);
    NTColor();

    friend NTColor operator*(const NTColor &col1, const NTColor &col2);
    friend NTColor operator*(const NTColor &col, const double multiple);
    friend void operator*=(NTColor &col, const NTColor &col2);
    friend void operator*=(NTColor &col, const double multiple);

    friend NTColor operator+(const NTColor &col1, const NTColor &col2);
    friend void operator+=(NTColor &col1, const NTColor &col2);

    friend NTColor operator/ (const NTColor& c1, double multiple);

    friend void operator/= (NTColor& c1, double multiple);

    double r;
    double g;
    double b;
};

#endif // LTCOLOR_H
