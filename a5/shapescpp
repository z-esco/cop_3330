#include "shapes.h"
#include <cmath>

//Increase size of array
void increaseArray(Shape** &list, int size){
    //creates temporary array with size +1
    Shape** temp = new Shape*[size];

    //copy shapes from list
    for(int i = 0; i<size; i++)
        temp[i] = list[i];
    
    //deletes list contents
    delete[] list;

    //points list pointer to temp list
    list = temp;
    
}

//get Area/perimeter answer
char const getAns(){
    char ans;
    bool valid = false;

    //creates validity loops
    do{
        //asks for input
        std::cout << "Would you like to know the perimeter and area of the Shape?(Y/N)";
        std::cin >> ans;
        ans = toupper(ans);
        std::cout << std::endl;

        if(ans == 'Y' || ans =='N')
            valid = true;
    }while(!valid);

    return ans;
}

//parameterized constructor 
Circle::Circle(){
    double r;

    std::cout << "Input the radius of the circle: ";
    std::cin >> r;
    radius = r;
}

//returns circle perimeter
double Circle::getPerimeter(){
    return 2.0*M_PI*radius;
}

//returns circle area
double Circle::getArea(){
    return M_PI*radius*radius;
}

//Square default constructor
Square::Square(){
    double l;

    std::cout << "Input the length of the square: ";
    std::cin >> l;
    
    length = l;
}

//returns square perimeter
double Square::getPerimeter(){
    return 4*length;
}

//returns square area
double Square::getArea(){
    return length*length;
}

//triangle default constructor
Triangle::Triangle(){
    double l1, l2, l3;
    
    std::cout << "Input the length of side 1: ";
    std::cin >> l1;
    std::cout << "Input the length of side 2: ";
    std::cin >> l2;
    std::cout << "Input the length of side 3: ";
    std::cin >> l3;

    a = l1;
    b = l2;
    c = l3;
}

//returns triangle perimeter
double Triangle::getPerimeter(){
    return a + b + c;
}

//returns triangle area
double Triangle::getArea(){
    double s = getPerimeter()/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
