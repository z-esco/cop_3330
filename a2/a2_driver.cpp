#include "a2.h"

int main(){
    //Declare variables
    int aReal, bReal, aImg, bImg;
    double convert;

    //Collect Input
    std::cout << "Input real value for first commplex number: ";   
    std::cin >> aReal;
    std::cout << "Input imaginary value for first commplex number: ";
    std::cin >> aImg;
    std::cout << "Input real value for second commplex number: ";
    std::cin >>bReal;
    std::cout << "Input imaginary value for second commplex number: ";
    std::cin >> bImg;
    std::cout << "Input double to be converted into a complex number ";
    std:: cin >> convert;

    //Initialize objects
    Complex a(aReal, aImg);
    Complex b(bReal, bImg);
    Complex c(convert);
    Complex def;

    //Display results of functions
    std::cout << "\na= " << a;
    std::cout << "b= " << b;
    std::cout << "a+b= " << a+b;
    std::cout << "a-b= " << a-b;
    std::cout << "a*b= " << a*b;
    std::cout <<"The negation of a is " << -a;
    std::cout << "The complement of b is " << b.complement();
    if(a==b)
        std::cout << "a equals b" << std::endl;
    else
        std::cout << "a does not equal b" << std::endl;
    std::cout << "Default complex is: " << def;
    std::cout << "Converted complex is now " << c;

}