#include "stack.h"

int main(){
	Stack<int> mys;
	mys.push(1);
	mys.push(2);
	mys.push(3);
	mys.push(4);
	mys.LinkedList<int>::print();
	std::cout << std::endl;
	mys.pop();
	mys.LinkedList<int>::print();
	std::cout << std::endl;
	mys.pop();
	mys.LinkedList<int>::print();
	return 0;
}