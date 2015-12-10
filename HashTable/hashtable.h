#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../LinkedList/linkedlist.h"
#include "../ArrayList/arraylist.h"

template <typename T> class HashTable : public LinkedList<T>{
	public:
		HashTable();
		~HashTable();
		void add (T value);
		void remove(T value);
		bool find(T value);
	protected:
		LinkedList<T> *myHashTable;
		int hash_function(T value);
		void resize();
		int m, n;
};

template <typename T>
HashTable<T>::HashTable(){
	this->m = 27;
	this->n = 0;
	myHashTable = new LinkedList<T>[this->m];
	std::cerr << "constructing HashTable" << std::endl;
}

template <typename T>
HashTable<T>::~HashTable(){
	std::cerr << "destroying HashTable" << std::endl;
}

template <typename T>
void HashTable<T>::add(T value){
	if(this->n == this->m) resize();
	int position = hash_function(value);
	myHashTable[position].LinkedList<T>::insert(value, 0);
	this->n++;
}

template <typename T>
bool HashTable<T>::find(T value){
	int pos = 0;
	try{
		int position = hash_function(value);
		pos = myHashTable[position].LinkedList<T>::find(value);
	}
	catch(const std::invalid_argument &ia){
		return false;
	}
	return true;
}


/* Not a good hash function, but will work for this implementation */
template <typename T>
int HashTable<T>::hash_function(T value){
	int key_value = int(value);
	int pos = key_value%this->m;
	return pos;
}

template <typename T>
void HashTable<T>::resize(){
	std::cerr << "resizing hash ... " << std::endl;
	int oldsize = this->m;
	this->m = 2*this->m + 1;
	LinkedList<T> *aux_hash = myHashTable;
	myHashTable = new LinkedList<T>[this->m];
	for (int i=0; i<oldsize; i++){
		myHashTable[i] = aux_hash[i];
	}

}

template <typename T>
void HashTable<T>::remove(T value){
	int pos = 0;
	try{
		int position = hash_function(value);
		pos = myHashTable[position].LinkedList<T>::find(value);
		myHashTable[position].LinkedList<T>::remove_position(pos);

	}
	catch(const std::invalid_argument &ia){
		throw std::invalid_argument("Value not found in the HashTable");
	}
}	

#endif