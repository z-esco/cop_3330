#include<iostream>

class Complex{
    private:
    int real, img;    

    public: 
    //constructors
    Complex ();
    Complex (double real);
    Complex (int real, int img);
    //member functions
    Complex operator+(Complex b);
    Complex operator-(Complex b);
    Complex complement();
    //getters
    int getReal() ;
    int getImg();
};
//<< and == operator overload declarations
std::ostream& operator<<(std::ostream& o, Complex a);
bool operator==(Complex a, Complex b);