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
protected:
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	LinkedList();
	~LinkedList();
	void insert(T new_value, int position);
	/* Removes the first occurrence of the node who have the value
	   passed as a parameter.
	 */
	void remove_value(T value);
	/* Removes the node in the position passed */
	void clear();
	void remove_position(int pos);
	void print();
	int getSize();
	int find(T value);
	bool isEmpty();

};

template <typename T>
LinkedList<T>::LinkedList(){
	head = tail = NULL;
	size = 0;
	std::cerr << "constructing list" << std::endl;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	Node<T> *temp = head;
	while(temp != NULL){
		Node<T> *aux = temp;
		temp = temp->next;
		delete aux;
	}
	std::cerr << "destroying list" << std::endl;
}

template <typename T>
bool LinkedList<T>::isEmpty(){
	if (this->size == 0) return true;
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
		this->size++;
		return;
	}
	if(position == 0){
		newNode->next = this->head;
		this->head = newNode;
		this->size++;
		return;
	}
	if (position == size){
		this->tail->next = newNode;
		this->tail = newNode;
		this->size++;
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
	this->size++;	
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
void LinkedList<T>::remove_value(T value){
	int pos = 0;
	try{
		pos = find(value);
	}
	catch(const std::invalid_argument &ia){
		throw std::invalid_argument ("Value not found, remove isn't possible");
	}
	std::cout << size-1 << std::endl; 
	if(pos == 0){
		Node<T> *temp = this->head;
		head = head->next;
		this->size--;
		delete temp;
		return;
	}
	if(pos == size-1){
		int cont=0;
		Node<T> *temp = this->head;
		while(cont < pos-1){
			temp = temp->next;
			cont++;
		}
		Node<T> *aux = temp->next;
		temp->next = aux->next;
		tail = temp;
		this->size--;
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
	this->size--;
	delete aux;
}

template <typename T>
void LinkedList<T>::remove_position(int pos){
	if (pos < 0 || pos > size-1){
		throw std::invalid_argument("Position out of range");
	}
	if(pos == 0){
		Node<T> *temp = this->head;
		head = head->next;
		delete temp;
		this->size--;
		return;
	}
	if(pos == size-1){
		int cont=0;
		Node<T> *temp = this->head;
		while(cont < pos-1){
			temp = temp->next;
			cont++;
		}
		Node<T> *aux = temp->next;
		temp->next = aux->next;
		tail = temp;
		delete aux;
		this->size--;
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
	this->size--;
	delete aux;
}

template <typename T>
void LinkedList<T>::clear(){
	Node<T> *temp = head;
	while(!isEmpty()){
		Node<T> *aux = temp;
		temp = temp->next;
		this->size--;
		aux = NULL;
	}
	head = tail = NULL;
}

#endif