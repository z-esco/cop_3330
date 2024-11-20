#include <iostream>

class Shape{
    
    public:
        virtual double getPerimeter()=0;
        virtual double getArea()=0;
};

class Circle: public Shape{

    public: 
        //default constructor
        Circle();

        double getPerimeter();
        double getArea();

    private:
        double radius;

};

class Square: public Shape{
    public:
        Square();
        double getPerimeter();
        double getArea();

    private:
        double length;
};

class Triangle: public Shape{
    public:
        Triangle();
        double getPerimeter();
        double getArea();

    private:
        double a,b,c;
};

void increaseArray(Shape** &list, int size);
char const getAns();
