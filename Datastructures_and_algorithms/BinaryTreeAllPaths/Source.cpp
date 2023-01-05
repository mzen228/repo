/*Print all possible paths from the root node to each leaf node*/
#include <iostream>
#include <algorithm>
#include <vector>
#include "BinaryTreeUtil.h"

void print(const std::vector<int>& vec);
bool isLeafNode(Node* root); 
void printAllPaths(Node* root);

void print(const std::vector<int>& vec) {
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
	std::cout << std::endl; 
}

bool isLeafNode(Node* root) {
	return !root->lchild && !root->rchild;
}

void printAllPaths(Node* root) {
	static std::vector<int> vec;

	if (!root)
		return;

	vec.push_back(root->data);

	if (isLeafNode(root))
		print(vec);

	printAllPaths(root->lchild);
	printAllPaths(root->rchild);
	vec.pop_back();
}

int main() {
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3);
	root->lchild->lchild = new Node(4);
	root->lchild->rchild = new Node(5);
	root->rchild->lchild = new Node(6);
	root->rchild->rchild = new Node(7);
	root->rchild->lchild->lchild = new Node(8);
	root->rchild->rchild->rchild = new Node(9);

	std::cout << "Printing all possible paths from the root to each leaf node...\n";
	printAllPaths(root);

	return 0;
}