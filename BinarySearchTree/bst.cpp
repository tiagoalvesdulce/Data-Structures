#include "bst.h"

using namespace std;

Bst::Bst(){
	this->root = NULL;
	cerr << "constructing bst ... " << endl;
}

Bst::~Bst(){
	delete this->root;
	cerr << "destroying bst ... " << endl;
}

bool Bst::isEmpty(){
	return (root == NULL);

}

void Bst::insert(int value){
	Node *newNode = new Node;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = value;
	if (isEmpty()){
		root = newNode;
		return;
	}
	Node *temp = root;
	Node *prev = temp;
	while(temp != NULL){
		if(value < temp->val) {prev = temp;temp=temp->left;}
		else if (value > temp->val) {prev = temp;temp=temp->right;}
		else throw invalid_argument("Value already in BST");
	}
	if(value < prev->val) prev->left = newNode;
	else prev->right = newNode;
}

void Bst::print_in_order_helper(Node* item){
	if(item != NULL){
		print_in_order_helper(item->left);
		cout << item->val << endl;
		print_in_order_helper(item->right);
	}
}

void Bst::print_in_order(){
	Node *item = root;
	print_in_order_helper(item);
}

bool Bst::find(int value){
	Node *temp = root;
	while(temp != NULL){
		if(value < temp->val) {temp=temp->left;}
		else if (value > temp->val) {temp=temp->right;}
		else return true;
	}
	return false;
}

void Bst::remove(int value){
	/* Remove will be implemented later */
}