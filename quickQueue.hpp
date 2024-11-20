const int MAX = 10;

template <class T>
    QuickQueue<T>::QuickQueue(){
        current = 0;
        array = new T*[MAX];
    }

template <class T>
    QuickQueue<T>::~QuickQueue(){
        for(int i=0; i<current; i++)
            delete array[i];
        delete[] array;
    }

template <class T>
    QuickQueue<T>::QuickQueue(const QuickQueue<T>& q){
        delete[]array;
        array = new T(q.getSize());
        for(int i = 0; i< q.getSize(); i++)
            array[i] = q.getElement(i);
        current = q.getSize();
    }

template <class T>
    T* QuickQueue<T>::getElement(unsigned int n){
        if(n>=MAX)
            n = MAX-1;
        return array[n];
    }

template <class T>
    int QuickQueue<T>::getSize(){
        return current;
    }
template <class T>
    bool QuickQueue<T>::enQueue(T item){
        if(current< MAX){
        current ++;
        array[current-1] = new T;
        *array[current - 1] = item;
        return true;
        }
        else
            return false;
    }

template <class T>
    T* QuickQueue<T>::deQueue(){
        T* item = array[0];
        for(int i = 0; i < current;i++)
            array[i] = array[i+1];
        current --;
        array[current] = new T;

        return item;
    }

template <class T>
    void QuickQueue<T>::printQueue(){
        if(current == 0)
            cout << "Empty Set\n";
        else{
            for(int i=0; i<current; i++){
                cout<<*array[i] << " ";
            }
            cout << endl;
        }
    }

template <class T>
    T* QuickQueue<T>::operator=(T* t){
        for(int i = 0; i<current; i++)
            array[i] = t.getElement[i];
        current = getSize();
         return this;
    }
