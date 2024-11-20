#include <string>
#include <iostream>

//grocery item class declaration
class GroceryItem{
    public:
    //constructors
    GroceryItem();
    GroceryItem(std::string s, double d);

    //getters
    double const getPrice();
    std::string const getName();

    //setters
    void setPrice(double d);
    void setName(std::string s);

    private:
    std::string name;
    double price;
};

class GroceryList{
    public:
        GroceryList();
        ~GroceryList();
        GroceryItem* getPtr();
        void addItem(int& count, int& size);
        void removeItem(int& size, int& count);
        void const printList(int count);
        void const total(int count, bool&getTotal);

    private:
        GroceryItem* list;
};
//misc function declarations
char menu();
std::ostream& operator<<(std::ostream& o, GroceryItem item);

