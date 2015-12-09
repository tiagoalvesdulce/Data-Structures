#include "../LinkedList/linkedlist.h"

template <typename T> class Stack : public LinkedList<T> {
	public:
		void pop();
		void push(T new_value);
};

template <typename T>
void Stack<T>::pop(){
	LinkedList<T>::remove_position(LinkedList<T>::getSize()-1);
}

template <typename T>
void Stack<T>::push(T new_value){
	LinkedList<T>::insert(new_value,LinkedList<T>::getSize());
}