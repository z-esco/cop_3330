#include "a2.h"
//Ostream << operator overload
std::ostream& operator<<(std::ostream& o, Complex a){
    if(a.getImg()>0)
        return std::cout << a.getReal() << " + " << a.getImg() << "i" << std::endl; 
    else if(a.getImg()==0)
        return std::cout << a.getReal() << std::endl;
    else if(a.getReal()==0)
        return std::cout << a.getImg() << "i" << std::endl;
    else
        return std::cout << a.getReal() << " - " << a.getImg()*-1 << "i" << std::endl;
}
//==Operator overload
bool operator==(Complex a, Complex b){
    return (a.getReal()==b.getReal() && a.getImg()==b.getImg());
}

Complex::Complex(){//default constructor
    real= 0;
    img= 0;   
}
Complex::Complex(double real){//conversion constructor
    this-> real = static_cast<int> (real);
    img = 0;
}
Complex::Complex(int real, int img){//paramatrized constructor
    this->real = real;
    this->img = img;
}
//getter definitions
int Complex::getReal(){ 
    return real;
}
int Complex::getImg(){
    return img;
}
//Member operator overloads
Complex Complex::operator+(Complex b){
    Complex r;

    r.real = this-> real + b.real;
    r.img = this ->img + b.img;

    return r;
}
Complex Complex::operator-(Complex b){
    Complex r;

    r.real = this-> real - b.real;
    r.img = this -> img - b.img;

    return r;
}
//Friend operator overloads
Complex operator-(Complex a){
    Complex r;

    r.real = a.getReal() *-1;
    r.img = a.getImg() *-1;

    return r;
}
Complex operator*(Complex a, Complex b){
    Complex r;

    r.real = (a.getReal() * b.getReal()) - (a.getImg()*b.getImg());
    r.img = (a.getReal() * b.getImg()) + (a.getImg()*b.getReal());

    return r;
}
//Membber complement function definiton
Complex Complex::complement(){
    Complex r;

    r.real = this-> real;
    r.img = this ->img *-1;

    return r;
}
