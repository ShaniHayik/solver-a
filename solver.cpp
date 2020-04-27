#include "solver.hpp"
#include <cmath>
#include <iostream>
using namespace std;
namespace solver {

RealVariable::RealVariable(double a ,double b, double c)
{
    this->a=a;
    this->b=b;
    this->c=c;
}
ComplexVariable::ComplexVariable(double r, double im)
{
    this->real=r;
    this->im=im;
}


//+ operator
RealVariable operator+(const RealVariable& x, const RealVariable &y )
{
    return RealVariable(x.getA()+y.getA(), x.getB()+y.getB(), x.getC()+y.getC());
}

RealVariable operator+(const RealVariable& x, const double y )
{
    return RealVariable(x.getA(), x.getB(), x.getC()+y);
}
RealVariable operator+(const double y, const RealVariable& x)
{
    return RealVariable(x.getA(), x.getB(), x.getC()+y);
}


//- operator
RealVariable operator-(const RealVariable& x, const RealVariable &y )
{
    return RealVariable(x.getA()-y.getA(), x.getB()-y.getB(), x.getC()-y.getC());
}

RealVariable operator-(const RealVariable& x, const double y)
{
    return RealVariable(x.getA(), x.getB(), x.getC()-y);
}

RealVariable operator-(const double y, const RealVariable& x)
{
    return RealVariable(x.getA(), x.getB(), y-x.getC());
}


//* operator
RealVariable operator*(const RealVariable& x, const RealVariable &y )
{
    return RealVariable(x.getA() * y.getC() + y.getA() * x.getC() + x.getC() * y.getB() ,x.getB() * y.getC() + y.getB() * x.getC(),x.getC() * y.getC());
}
RealVariable operator*(const RealVariable& x, const double y )
{
    return RealVariable(x.getA(), x.getB(), x.getC()*y);
}
RealVariable operator*(const double y, const RealVariable& x)
{
    return RealVariable(x.getA()*y, x.getB()*y, x.getC()*y);
}


//: operator
RealVariable operator/(const RealVariable& x, const RealVariable &y )
{
    return RealVariable(x.getA()/y.getA(), x.getB()/y.getB(), x.getC()/y.getC());
}
RealVariable operator/(const RealVariable& x, const double y )
{
    return RealVariable(x.getA()/y, x.getB()/y, x.getC()/y);
}
RealVariable operator/(const double y, const RealVariable& x)
{
    return RealVariable(x.getA(), x.getB(), y/x.getC());
}


// ^ power
    RealVariable operator^(const RealVariable &x, const double power){
    if((power>2 && x.getA()==0 && x.getB()==0)) return RealVariable(0,0,pow(x.c,power));
    if ((x.getA()!=0) || (power>2) || (power<0) ) throw std::out_of_range {" the power is not valid"};
    if(x.getB()!=0 && x.getC()!=0 && power==2) return RealVariable(pow(x.getB(),power),x.getB()*x.getC()*power,pow(x.getC(),power));
    if(x.getB()!=0 && x.getC()==0 && power==2) return RealVariable(pow(x.getB(),power),0,0);
    if(power==1) return x;
    if(power==0) return RealVariable(0,0,1);
}

// == operator
 RealVariable operator==(const RealVariable& x, const RealVariable &y) { return x-y; }
 RealVariable operator==(const RealVariable& x, const double y){ return x-y; }
 RealVariable operator==(const double y, const RealVariable &x){ return y-x; }



 double solve(const RealVariable& x){
    double a = x.getA();
    double b = x.getB();
    double c = x.getC();
    // maybe throw error about power>2
    if(a==0) {
        if(b==0 && c!=0)
            throw std::out_of_range {" there is no result "};
        else return c/-b;
    }

    if ((b * b - 4 * a * c) > 0)
        return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
      //  return(-x.b + sqrt(x.b * x.b - 4 * x.a * x.c)) / (2 * x.a);

    else if ((b * b - 4 * a * c) == 0)
        return ((-b + sqrt(b * b - 4 * a * c)) / (2 * a));

     throw std::out_of_range {"There is no a real solution"};

        // complex case
//    else if ((x.b * x.b - 4 * x.a * x.c) < 0)
//    x1 = ((-x.b + sqrt(x.b * x.b - 4 * x.a * x.c) * sqrt (-1)) / (2 * x.a)
//    x2 = ((-x.b + sqrt(x.b * x.b - 4 * x.a * x.c) * sqrt (-1)) / (2 * x.a);

}
}












