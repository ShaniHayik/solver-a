#include <iostream>
#include <complex>
using namespace std;


namespace solver{
    
class RealVariable{
    private:
    double a,b,c;

    public:
    RealVariable(double a ,double b, double c);
    RealVariable(): a(0), b(1), c(0) {}

    const double & getA () const{
        return this->a;
    }
    const double & getB () const{
        return b;
    }
    const double & getC () const{
        return c;
    }

    // + operator
    friend RealVariable operator+(const RealVariable& x, const RealVariable &y );
    friend RealVariable operator+(const RealVariable& x, const double y );
    friend RealVariable operator+(const double y, const RealVariable& x);

    // - operator
    friend RealVariable operator-(const RealVariable& x,const RealVariable& y );
    friend RealVariable operator-(const RealVariable& x, const double y);
    friend RealVariable operator-(const double y, const RealVariable& x);

    //* operator
    friend RealVariable operator*(const RealVariable& x, const RealVariable &y);
    friend RealVariable operator*(const RealVariable& x, const double y);
    friend RealVariable operator*(const double y, const RealVariable& x);

    //: operator
    friend RealVariable operator/(const RealVariable& x, const RealVariable &y);
    friend RealVariable operator/(const RealVariable& x, const double y);
    friend RealVariable operator/(const double y, const RealVariable& x);

    // ^ operator
    friend RealVariable operator^(const RealVariable &x, const double power);

    // == operator
    friend RealVariable operator==(const RealVariable& x, const RealVariable& y);
    friend RealVariable operator==(const RealVariable& X, const double y);
    friend RealVariable operator==(const double y, const RealVariable& X);
    };

    class ComplexVariable{
    private:
        double real;
        double im;
    public:
        ComplexVariable(double r, double im);


    };

    double solve (const RealVariable& x);

}

