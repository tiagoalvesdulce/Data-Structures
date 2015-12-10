#include "hashtable.h"

int main(){
	HashTable<int> myh;
	for (int i=0; i<50; i++){
		myh.add(i);
	}
	std::cout << "added" << std::endl;
	if(myh.find(0)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(2)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(49)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(23)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(90)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	myh.remove(0);
	myh.remove(2);
	myh.remove(49);
	myh.remove(23);
	if(myh.find(0)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(2)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(49)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(23)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	if(myh.find(90)) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	return 0;
}