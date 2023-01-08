/*Display a binary tree*/

/*
							  7
					3
							  6
		  1
							  5
					2
							  4
*/
#include <iostream>
#include <memory>

struct Node {
	int data;
	std::shared_ptr<Node> lchild;
	std::shared_ptr<Node> rchild;
	Node(int d) :data{ d }, lchild{ nullptr }, rchild{ nullptr } {}
};

void displayBinaryTree(std::shared_ptr<Node> root, int space) {
	int length{ 10 };

	if (!root)
		return;

	space += length;
	displayBinaryTree(root->rchild, space);
	std::cout << std::endl; 
	for (size_t i{}; i < space; ++i)
		std::cout << ' ';
	std::cout << root->data;
	
	displayBinaryTree(root->lchild, space);
}

int main() {
	auto root = std::make_shared<Node>(1);
	root->lchild = std::make_shared<Node>(2);
	root->rchild = std::make_shared<Node>(3);
	root->lchild->lchild = std::make_shared<Node>(4);
	root->lchild->rchild = std::make_shared<Node>(5);
	root->rchild->lchild = std::make_shared<Node>(6);
	root->rchild->rchild = std::make_shared<Node>(7);

	displayBinaryTree(root,0);

	return 0;
}