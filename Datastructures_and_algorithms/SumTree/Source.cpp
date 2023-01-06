/*Given a binary tree, in-place replace each node's value to the sum of 
all elements present in its left and right subtree*/

#include <iostream>

struct Node {
	int data;
	std::shared_ptr<Node> rchild;
	std::shared_ptr<Node> lchild;
	Node(int data_) :data{ data_ }, rchild{ nullptr }, lchild{ nullptr } {}
};

int preorderSum(std::shared_ptr<Node> root);
void sumTree(std::shared_ptr<Node> root);
void preorderTraversal(std::shared_ptr<Node> root);

void preorderTraversal(std::shared_ptr<Node> root) {

	if (!root)
		return;

	std::cout << root->data << ", ";

	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}

void sumTree(std::shared_ptr<Node> root) {
	
	if (!root)
		return;

	root->data = preorderSum(root) - root->data; 

	sumTree(root->lchild);
	sumTree(root->rchild);
}

int preorderSum(std::shared_ptr<Node> root) {
	
	if (!root)
		return 0;

	return root->data + preorderSum(root->lchild) + preorderSum(root->rchild);
}

int main() {
	auto root = std::make_shared<Node>(1);
	root->lchild = std::make_shared<Node>(2);
	root->rchild = std::make_shared<Node>(3);
	root->lchild->rchild = std::make_shared<Node>(4);
	root->rchild->lchild = std::make_shared<Node>(5);
	root->rchild->rchild = std::make_shared<Node>(6);
	root->rchild->lchild->lchild = std::make_shared<Node>(7);
	root->rchild->lchild->rchild = std::make_shared<Node>(8);

	std::cout << "Preorder traversal of original tree: ";
	preorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Preorder traversal of sum tree: ";
	sumTree(root);
	preorderTraversal(root);
	std::cout << std::endl;

	return 0;
}