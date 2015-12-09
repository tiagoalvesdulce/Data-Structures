#include "linkedlist.h"

int main(){
	LinkedList<std::string> myLL;
	myLL.insert("string 2",0);
	myLL.insert("string 3",1);
	myLL.insert("string 4",2);
	myLL.insert("string 5",0);
	myLL.insert("string 6",1);
	myLL.insert("string 7",3);
	myLL.print();
	std::cout << "size: " << myLL.getSize() << std::endl;
	std::cout << "string7 found at: " << myLL.find("string 7") << std::endl;  
	myLL.remove_value("string 7");
	myLL.print();
	myLL.remove_value("string 5"); 
	myLL.print();
	myLL.remove_value("string 4");
	myLL.print();
	std::cout << "size: " << myLL.getSize() << std::endl;
	myLL.remove_position(0);
	std::cout << std::endl;
	myLL.print();
	myLL.remove_position(1);
	std::cout << std::endl;
	myLL.print();
	myLL.insert("string 5",0);
	myLL.insert("string 6",1);
	myLL.insert("string 7",3);
	std::cout << std::endl;
	myLL.print();
	myLL.remove_position(1);
	std::cout << std::endl;
	myLL.print();
	std::cout << "size: " << myLL.getSize() << std::endl;
	myLL.clear();
	std::cout << "clearing ... " << std::endl;
	std::cout << "size: " << myLL.getSize() << std::endl;
	myLL.print();
	return 0;
}