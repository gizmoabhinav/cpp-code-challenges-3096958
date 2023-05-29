#include "complex_num.h"

complex_num::complex_num(double r, double i){
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.real = real + w.real;
    z.imaginary = imaginary + w.imaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.real = real - w.real;
    z.imaginary = imaginary - w.imaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.real = (real*w.real) - (imaginary*w.imaginary);
    z.imaginary = (real*w.imaginary) + (imaginary*w.real);
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    z.real = ((real*w.real) + (imaginary*w.imaginary))/((w.real*w.real)+(w.imaginary*w.imaginary));
    z.imaginary = ((imaginary*w.real)-(real*w.imaginary))/((w.real*w.real)+(w.imaginary*w.imaginary));
    return z;
}

void complex_num::print(std::ostream &os){
    if (imaginary < 0) {
        os << real << " - " << (imaginary*-1) << "i"; 
    } else {
        os << real << " + " << imaginary << "i";
    }
    os << std::flush;
}