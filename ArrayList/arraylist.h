#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>
#include <iostream>

template <typename T> class ArrayList{
	public:
		ArrayList();
		~ArrayList();
		void insert(T new_value, int pos);
		void remove(int pos);
		bool find(T val);
		void print();
		int getSize();
		bool isEmpty();
		void clear();
	protected:
		int size;
		int cap;
		T *my_array;
		void resize();
};

template <typename T>
ArrayList<T>::ArrayList(){
	this->size = 0;
	this->cap = 20;
	my_array = new T[this->cap];
	std::cout << "constructing ArrayList" << std::endl;
}

template <typename T>
ArrayList<T>::~ArrayList(){
	delete [] my_array;
	std::cout << "destroying ArrayList" << std::endl;
}

template <typename T>
void ArrayList<T>::insert(T new_value, int pos){
	if (pos < 0 || pos > size){
		throw std::invalid_argument("Out of range");
	}
	if (this->size == this->cap) {std::cerr << "resizing ..." << std::endl; resize();};
	for (int i=this->size; i> pos; i--){
		my_array[i] = my_array[i-1];
	}
	my_array[pos] = new_value;
	size++;
}

template <typename T>
void ArrayList<T>::print(){
	for (int i=0; i<this->size; i++){
		std::cout << my_array[i] << std::endl;
	}
}

template <typename T>
void ArrayList<T>::resize(){
	this->cap = 2*(this->cap);
	T *aux_array = new T[this->cap];
	for (int i=0; i<this->cap; i++){
		aux_array[i] = my_array[i];
	}
	delete [] my_array;
	my_array = aux_array;
}

template <typename T>
void ArrayList<T>::remove(int pos){
	if (isEmpty()) throw std::invalid_argument("The ArrayList is empty!");
	if(pos < 0 || pos > this->size-1) throw std::invalid_argument("Out of range");
	for (int i=pos; i<this->size-1; i++){
		my_array[i] = my_array[i+1];
	}
	this->size--;
}

template <typename T>
bool ArrayList<T>::find(T val){
	for (int i=0; i<this->size; i++){
		if (my_array[i] == val) return true;
	}
	return false;
}

template <typename T>
bool ArrayList<T>::isEmpty(){
	return (this->size==0);
}

template <typename T>
int ArrayList<T>::getSize(){
	return this->size;
}

template <typename T>
void ArrayList<T>::clear(){
	for (int i=0; i<this->size; i++){
		my_array[i] = -1;
	}
	this->size = 0;
}


#endif