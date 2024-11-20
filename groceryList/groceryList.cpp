#include "a3.h"

//Class Defintions
//default constructor
GroceryItem::GroceryItem(){
    name = "";
    price = 0.00;
}

//parameterized constructor
GroceryItem::GroceryItem(std::string s, double d){
    name = s;
    price = d;
}

//getter definitions
double const GroceryItem::getPrice(){
    return price;
}

std::string const GroceryItem::getName(){
    return name;
}

//setter definitions
void GroceryItem::setPrice(double d){
    price = d;
}

void GroceryItem::setName(std::string s){
    name = s;
}

//Misc Function Defintions
//Menu Display Defintion
char menu(){
    char sel;
    bool valid;

    valid = false;

    //display menu and get valid selection
    while(!valid){
    std::cout << "Please select a Menu option:\n(A)Insert Item\n(B)Remove Item\n(C)List Items\n(D)Checkout\n";
    std::cin >> sel;

    //convert input to uppercase
    sel = toupper(sel);

    //check input validity
    switch(sel){
        case 'A':
        case 'B':
        case 'C':
        case 'D':
            valid = true;
            break;
        default:
            std::cout << "Invalid Menu selection. Try again.\n";
            break;
    }
    }
    return sel;
}

//insertion operator overload
std::ostream& operator << (std::ostream& o, GroceryItem item){
    if(item.getPrice()>0)
        return std::cout << item.getName() << ": $" << item.getPrice() << std::endl;
    else
        return std::cout << "";
}

GroceryList::GroceryList(){
    list = new GroceryItem[3];
}

//destructor
GroceryList::~GroceryList(){
    delete[] list;
}

//getter definiton
GroceryItem* GroceryList::getPtr(){
    return list;
}
//Add Item Funciton Defintion
void GroceryList::addItem(int& count, int& size){
    GroceryItem newItem;
    std::string s;
    double d;

    //get item name and price
    std::cout << "Input new item name: ";
    std::cin >> s;
    std::cout << "Input new item price: ";
    std::cin >> d;

    // use setters to assign values to newItem
    newItem.setName(s);
    newItem.setPrice(d);
    //increase itemCount by reference
    count++;

    //checks to see if array needs to be increased and increases it
    if(count%3 == 1 && count > 3){
        GroceryItem * tempList;
        size = size + 3;
        //creates larger temp array and assigns the same values to it 
        tempList = new GroceryItem[size];
        for(int i=0; i<size-3; i++)
            tempList[i] = list[i];
        tempList[count-1] = newItem;

        //deallocates old pointer
        delete[] list;
        //reassigns pointer to larger list
        list = tempList;
    }
    else{ 
        //assigns new item if array is large enough
        list[count-1] = newItem;
    }
}

//Remove Item function Defintion
void GroceryList::removeItem(int& size, int& count){
    std::string del;
    int delIndex;
    bool valid;

    valid = false;
    //gets name of deleted item and checks for validity
    while(!valid){
    std::cout << "Input name of item you want to delete: ";
    std::cin >> del;
        //finds index of item to be deleted
        for(int i = 0; i<size; i++){
            if(list[i].getName() == del){
                delIndex = i;
                valid = true;
            }
        }
        //tells user to try again
        if(!valid)
            std::cout << "Invalid Item name try again.\n";
    }

    //Create temp array
    GroceryItem * tempArray;
    tempArray = new GroceryItem[size];

    //copies all elements before item to be deleted
    for(int i=0;i<delIndex;i++)
        tempArray[i] = list[i];
    //copies all elements after delted array one space back
    for(int i=delIndex+1; i<size; i++)
        tempArray[i-1] = list[i];
    //deallocate list
    delete[] list;
    //assign list new location
    list = tempArray;
    
    count --;
}

//Prints List
void const GroceryList::printList(int count){
    std::cout << "Grocery List:\n";
    for(int i=0; i<count; i++)
        std::cout << "\t" << list[i] << std::endl;
}

void const GroceryList::total(int count, bool& getTotal){

    const double TAX = 0.07;
    double subTotal, total;


    for(int i=0; i<count; i++)
        subTotal+= list[i].getPrice();
    total = subTotal + subTotal*TAX;

    std::cout << "Subtotal: $" << subTotal << "\nTotal: $" << total << std::endl;

    getTotal = true;
}
