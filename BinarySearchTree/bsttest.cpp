#include "bst.h"

using namespace std;

int main(){
	Bst mybst;
	mybst.insert(0);
	mybst.insert(1);
	mybst.insert(5);
	mybst.insert(9);
	mybst.insert(3);
	mybst.insert(2);
	mybst.print_in_order();
	if(mybst.find(0)) cout << "yes" << endl;
	else cout << "no" << endl;
	if(mybst.find(9)) cout << "yes" << endl;
	else cout << "no" << endl;
	if(mybst.find(2)) cout << "yes" << endl;
	else cout << "no" << endl;
	if(mybst.find(10)) cout << "yes" << endl;
	else cout << "no" << endl;
	mybst.remove(5);
	mybst.print_in_order();

	cout << endl << " --- PRINT SORTED ARRAY WITH BST --- " << endl;
	int arr[5] = {7,8,2,3,1};
	cout << "Original array: " << endl;
	for(int i=0; i<5; i++){
		cout << arr[i] << endl;
	}
	cout << endl;
	Bst mybst2;
	cout << "Result of in-order traverse: " << endl;
	for (int i=0; i<5; i++){
		mybst2.insert(arr[i]);
	}
	mybst2.print_in_order();
	return 0;
}