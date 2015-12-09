#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdexcept>
#include <iostream>

template <typename T> struct Node
{
	T val;
	Node<T> *next;
};

template <typename T> class LinkedList{
private:
	int size;
protected:
	Node<T> *head;
	Node<T> *tail;
public:
	LinkedList();
	~LinkedList();
	void insert(T new_value, int position);
	void remove(T value);
	void print();
	int getSize();
	int find(T value);
	bool isEmpty();

};

template <typename T>
LinkedList<T>::LinkedList(){
	head = tail = NULL;
	size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){

}

template <typename T>
bool LinkedList<T>::isEmpty(){
	if (size == 0) return true;
	else return false;
}

template <typename T>
void LinkedList<T>::insert(T new_value, int position){
	if(position < 0 || position > size){
		throw std::invalid_argument("Out of range");
	}
	Node<T> *newNode = new Node<T>;
	newNode->val = new_value;
	newNode->next = NULL;
	if (isEmpty()){
		this->head = newNode;
		this->tail = newNode;
		size++;
		return;
	}
	if(position == 0){
		newNode->next = this->head;
		this->head = newNode;
		size++;
		return;
	}
	if (position == size){
		this->tail->next = newNode;
		this->tail = newNode;
		size++;
		return;
	}
	Node<T> *temp = head;
	int cont = 0;
	while(cont < position-1){
		temp = temp->next;
		cont++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	size++;	
}

template <typename T>
void LinkedList<T>::print(){
	Node<T> *temp = head;
	while(temp != NULL){
		std::cout << temp->val << std::endl;
		temp = temp->next;
	}
}

template <typename T>
int LinkedList<T>::getSize(){
	return size;
}

template <typename T>
int LinkedList<T>::find(T value){
	Node<T> *temp = this->head;
	int cont = 0;
	while (temp != NULL){
		if(temp->val == value) return cont;
		else temp = temp->next;
		cont++;
	}
	throw std::invalid_argument("Value not found");
}

template <typename T>
void LinkedList<T>::remove(T value){
	int pos = 0;
	try{
		pos = find(value);
	}
	catch(const std::invalid_argument &ia){
		throw std::invalid_argument ("Value not found, remove isn't possible");
	}
	if(pos == 0){
		Node<T> *temp = this->head;
		head = head->next;
		delete temp;
		return;
	}
	if(pos == size-1){
		int cont=0;
		Node<T> *temp = this->head;
		while(cont < pos-1){
			temp = temp->next;
		}
		Node<T> *aux = temp->next;
		temp->next = aux->next;
		tail = temp;
		delete aux;
		return;
	}
	int cont=0;
	Node<T> *temp = this->head;
	while(cont < pos-1){
		temp = temp->next;
		cont++;
	}
	Node<T> *aux = temp->next;
	temp->next = aux->next;
	delete aux;
}






#endif