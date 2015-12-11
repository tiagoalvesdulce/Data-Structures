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

Node* Bst::sucessor(Node *item){
	if(item->right != NULL){
		item=item->right;
		while(item->left != NULL) item=item->left;
	}
	cout << "sucessor is: " << item->val;
	return item;
}

Node* Bst::predecessor(Node *item){
	if(item->left != NULL){
		item=item->left;
		while(item->right != NULL) item=item->right;
	}
	return item;
}

/* STILL MISSING THE CASE WHERE THE NODE HAVE 2 CHILDS */
void Bst::remove(int value){
	cout << endl;
	cout << value << endl;
	Node *temp = root;
 	Node *prev = temp;
	while(temp != NULL){
		if(value < temp->val) {prev = temp;temp=temp->left;}
		else if (value > temp->val) {prev = temp;temp=temp->right;}
		else {
			if (temp->right == NULL && temp->left == NULL){
				if(temp == prev->right) prev->right = NULL;
				if(temp == prev->left) prev->left = NULL;
				delete temp;
				return;
			}
			else if(temp->right == NULL && temp->left != NULL){
				if (temp == prev->right){
					prev->right = temp->left;
					temp->left = NULL;
				}
				else if (temp == prev->left){
					prev->left = temp->left;
					temp->left = NULL;
				}
				delete temp;
				return;
			}
			else if(temp->right != NULL && temp->left == NULL){
				if (temp == prev->right){
					prev->right = temp->right;
					temp->right = NULL;
				}
				else if (temp == prev->left){
					prev->left = temp->right;
					temp->right = NULL;
				}
				delete temp;
				return;
			}
			else if(temp->right != NULL && temp->left != NULL){
				Node *suc = sucessor(temp);
				Node aux;
				aux = *temp;
				*temp = *suc;
				*suc = aux;
				remove(suc->val);
				return;
			}
		}
	}
	throw invalid_argument("Value not found");
}