#include "a3.h"

int main(){
    char menuSel;
    int itemCount, size;
    bool getTotal;
    
    size = 3;
    itemCount = 0;
    getTotal = false;

    GroceryList list;




    
    std::cout<< "Welcome to the Grocery List\n\n";
    while(!getTotal){
        menuSel = menu();

        switch(menuSel){
            case 'A':
                list.addItem(itemCount, size);
                break;
            case 'B':
                list.removeItem(size, itemCount);
                break;        
            case 'C':
                list.printList(itemCount);
                break;
            case 'D':
                list.total(size , getTotal);
                break;
        }
    }

    std::cout << "Thanks for shopping!\n";
    
    return 0;
}