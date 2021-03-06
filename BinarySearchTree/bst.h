#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>

struct Node
{
	int val;
	Node* left;
	Node* right;
	~Node(){
		delete left;
		delete right;
		std::cerr << "destroying left and right ... " << std::endl;

	}
};

class Bst
{
public:
	Bst();
	~Bst();
	Node* predecessor(Node *item);
	Node* sucessor(Node *item);
	void insert(int value);
	void remove(int value); /*STILL MISSING THE CASE WHERE THE NODE HAVE 2 CHILDS */
	bool find(int value);
	void print_in_order();
	bool isEmpty();
private:
	void print_in_order_helper(Node* item);
	Node *root;
};

#endif