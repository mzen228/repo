/*Given a binary tree, in-place replace each node's value to the sum of 
all elements present in its left and right subtree*/

#include <iostream>

int preorderSum(Node* root);
void sumTree(Node* root);
void preorderTraversal(Node* root);

struct Node {
	int data;
	Node* rchild;
	Node* lchild; 
	Node(int data_) :data{ data_ }, rchild{ nullptr }, lchild{ nullptr } {}
};

void preorderTraversal(Node* root) {

	if (!root)
		return;

	std::cout << root->data << ", ";

	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}

void sumTree(Node* root) {
	
	if (!root)
		return;

	root->data = preorderSum(root) - root->data; 
	std::cout << root->data << ", ";

	sumTree(root->lchild);
	sumTree(root->rchild);
}

int preorderSum(Node* root) {
	
	if (!root)
		return 0;

	return root->data + preorderSum(root->lchild) + preorderSum(root->rchild);
}

int main() {
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3);
	root->lchild->rchild = new Node(4);
	root->rchild->lchild = new Node(5);
	root->rchild->rchild = new Node(6);
	root->rchild->lchild->lchild = new Node(7);
	root->rchild->lchild->rchild = new Node(8);

	std::cout << "Preorder traversal of original tree: ";
	preorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Preorder traversal of sum tree: ";
	sumTree(root);
	std::cout << std::endl;

	return 0;
}