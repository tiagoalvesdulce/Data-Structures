#include "queue.h"

int main(){
	Queue<int> myq;
	myq.push(1);
	myq.push(2);
	myq.push(3);
	myq.push(4);
	myq.push(5);
	myq.LinkedList<int>::print();
	std::cout << std::endl;
	myq.pop();
	myq.pop();
	myq.LinkedList<int>::print();
}