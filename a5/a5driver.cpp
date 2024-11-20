#include "sampleDriver.h"
#include <iostream>


int main(){
    char menu, ans;
    int size, count;
    double aSum, pSum;
    bool quit;
    
    //variable initialization
    size = 1;
    count = 0;

    //creates dynamically allocated list of shape pointers
    Shape** list  = new Shape*[size];

    while(!quit){
        //menu function
        std::cout << "\nSelect a menu option:\n(A)Create a Circle\n(B)Create a Square\n"
            << "(C)Create a Triangle\n(D)Get area of all shapes\n(E)Get perimeter "
            << "of all shapes\n(F)End program\n\nInput:";
            
        //inputs menu selection
        std::cin >> menu;
        menu = toupper(menu);

        //just to look nice
        std::cout << std::endl;

        //switch statement for menu selection
        switch(menu){
            case 'A':
                //creares new circle object and assigns it to next open spot
                list[count] = new Circle();   
            break;

            case 'B':
                //creates new sqquare object and assigns it to next list spot
                list[count] = new Square();
            break;

            case 'C':
                //creates new triangle and adds it to list
                list[count] = new Triangle();
            break;

            case 'D':
                //accesses list and aggregates area
                for(int i = 0; i < count; i++)
                    aSum += list[i]->getArea();

                //prints gross area
                std::cout << "Aggregate Area Sum: " << aSum << std::endl;
            break;

            case 'E':
                //accesess list and aggregates perimeter
                for(int i = 0; i < count; i++)
                    pSum += list[i]->getPerimeter();
                //prints result
                std::cout << "Aggregate Perimeter Sum: " << pSum << std::endl;
            break;

            case 'F':
                //deletes list to stop memory leak
                delete[] list;
                quit = true;
            break;

            default:
                std::cout << "Invalid menu selection. Try again\n";
            break;
        }
        if(menu == 'A' || menu == 'B'|| menu == 'C'){
            //increases size and count counters
            count ++;
            size ++;

            //sends list and new size to increase array size
            increaseArray(list, size);

            //asks if user wants area and perimeter displayed
            ans = getAns();
            //displays them if yes
            if(ans == 'Y'){
                std::cout << "Perimeter: " << list[count-1]->getPerimeter() << std::endl;
                std::cout << "Area: " << list[count-1]->getArea() << std::endl;
            }           
        }
            
    }

    return 0;
}
