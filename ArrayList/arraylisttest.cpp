#include "arraylist.h"

int main(){
	ArrayList<int> myal;
	//myal.remove(6); //empty removal
	for (int i=0; i<45; i++){
		myal.insert(i,0);	
	}
	myal.print();
	std::cout << "size: " << myal.getSize() << std::endl;

	myal.remove(0);
	myal.print();
	std::cout << std::endl;

	myal.remove(43);
	myal.print();
	std::cout << std::endl;

	myal.remove(19);
	myal.print();
	std::cout << std::endl;

	myal.clear();
	std::cout << "size: " << myal.getSize() << std::endl;

	std::cout << std::endl;

	myal.insert(1,0);
	myal.insert(6,1);
	myal.insert(8,1);
	myal.insert(7,0);
	myal.insert(4,4);

	myal.print();


	return 0;
}