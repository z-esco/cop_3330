#include <iostream>
using namespace std;

template <class T>
class QuickQueue{
    T* operator=(T* t);
    
    public:
        QuickQueue();
        ~QuickQueue();


        bool enQueue(T item);
        T* deQueue();

        void printQueue();
        int getSize();
        T* getElement(unsigned int n);

        QuickQueue(const QuickQueue<T>& q);

    private:
        T** array;
        int current;
};

#include "quickQueue.hpp"
