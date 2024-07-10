#include <iostream>
#include <cmath> 
class Complex {
private:
    double real;
    double imag;

public:
    
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    
    double getReal() const { return real; }
    double getImag() const { return imag; }

    
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        double result_real = real * other.real - imag * other.imag;
        double result_imag = real * other.imag + imag * other.real;
        return Complex(result_real, result_imag);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        double result_real = (real * other.real + imag * other.imag) / denominator;
        double result_imag = (imag * other.real - real * other.imag) / denominator;
        return Complex(result_real, result_imag);
    }

   
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    Complex conjugate() const {
        return Complex(real, -imag);
    }


    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }

    
    Complex& operator++() { 
        ++real;
        return *this;
    }

    Complex operator++(int) { 
        Complex temp(*this);
        ++real;
        return temp;
    }

    Complex& operator--() { 
        --real;
        return *this;
    }

    Complex operator--(int) {
        Complex temp(*this);
        --real;
        return temp;
    }

    
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.real << "+" << complex.imag << "i";
        return os;
    }
};

int main() {
 
    Complex c1(2.0, 3.0);
    Complex c2(1.0, 4.0);

    
    Complex sum = c1 + c2;
    std::cout << "Sum: " << sum << std::endl;

    
    Complex diff = c1 - c2;
    std::cout << "Difference: " << diff << std::endl;

    
    Complex product = c1 * c2;
    std::cout << "Product: " << product << std::endl;

    
    Complex quotient = c1 / c2;
    std::cout << "Quotient: " << quotient << std::endl;

  
    if (c1 == c2) {
        std::cout << "c1 is equal to c2" << std::endl;
    } else {
        std::cout << "c1 is not equal to c2" << std::endl;
    }

   
    if (c1 != c2) {
        std::cout << "c1 is not equal to c2" << std::endl;
    } else {
        std::cout << "c1 is equal to c2" << std::endl;
    }

    
    Complex conjugate_c1 = c1.conjugate();
    std::cout << "Conjugate of c1: " << conjugate_c1 << std::endl;

   
    double modulus_c1 = c1.modulus();
    std::cout << "Modulus of c1: " << modulus_c1 << std::endl;

   
    ++c1;
    std::cout << "After prefix increment: " << c1 << std::endl;

   
    c1++;
    std::cout << "After postfix increment: " << c1 << std::endl;

    
    --c1;
    std::cout << "After prefix decrement: " << c1 << std::endl;

   
    c1--;
    std::cout << "After postfix decrement: " << c1 << std::endl;

    return 0;
}


