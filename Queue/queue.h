#include "../LinkedList/linkedlist.h"

template <typename T> class Queue : public LinkedList<T> {
public:
	void pop();
	void push(T new_value);
};

template <typename T>
void Queue<T>::pop(){
	LinkedList<T>::remove_position(0);
}

template <typename T>
void Queue<T>::push(T new_value){
	LinkedList<T>::insert(new_value, LinkedList<T>::size);
}
