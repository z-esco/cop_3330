#include "a6.h"

int main(){
    QuickQueue<int> intQueue;

    for(int i = 1; i<6; i++){
        if(intQueue.enQueue(i*6));
    }    
    intQueue.printQueue();

    cout << "Removed: " << *intQueue.deQueue() << endl;

    cout << "Removed: " << *intQueue.deQueue() << endl;

    intQueue.printQueue();

    QuickQueue<char> charQueue;

    for(int i = 0; i< 5; i++)
        charQueue.enQueue(i+'a');

    charQueue.printQueue();

    cout << "Removed: " << charQueue.deQueue() << endl;

    cout << "Removed: " << charQueue.deQueue() << endl;

    charQueue.printQueue();

    return 0;
}