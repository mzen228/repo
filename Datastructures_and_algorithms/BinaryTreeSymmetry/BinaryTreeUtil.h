#pragma once
#include <iostream>

struct Node {
	int data;
	Node* lchild;
	Node* rchild;
	Node() {}
	Node(int data_) :data{ data_ } {
		lchild = nullptr;
		rchild = nullptr;
	}
};

void preorderTraversal(Node* root) {
	if (!root)
		return;

	std::cout << root->data << ", ";
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}

void postorderTraversal(Node* root) {
	if (!root)
		return;

	postorderTraversal(root->lchild);
	postorderTraversal(root->rchild);
	std::cout << root->data << ", ";
}

void inorderTraversal(Node* root) {
	if (!root)
		return;

	inorderTraversal(root->lchild);
	std::cout << root->data << ", ";
	inorderTraversal(root->rchild);
}

void traversals(Node* root) {
	if (!root)
		return;

	std::cout << "Preorder traversal: ";
	preorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Postorder traversal: ";
	postorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Inorder traversal: ";
	inorderTraversal(root);
	std::cout << std::endl;

	std::cout << std::endl;
}