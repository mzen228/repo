#pragma once
#include <iostream>

struct Node {
	int data;
	std::shared_ptr<Node> lchild;
	std::shared_ptr<Node> rchild;
	Node() {}
	Node(int data_) :data{ data_ } {
		lchild = nullptr;
		rchild = nullptr;
	}
};

void preorderTraversal(std::shared_ptr<Node> root) {
	if (!root)
		return;

	std::cout << root->data << ", ";
	preorderTraversal(root->lchild);
	preorderTraversal(root->rchild);
}

void reversePreorderTraversal(std::shared_ptr<Node> root) {
	if (!root)
		return;

	std::cout << root->data << ", ";
	reversePreorderTraversal(root->rchild);
	reversePreorderTraversal(root->lchild);
}

void postorderTraversal(std::shared_ptr<Node> root) {
	if (!root)
		return;

	postorderTraversal(root->lchild);
	postorderTraversal(root->rchild);
	std::cout << root->data << ", ";
}

void reversePostorderTraversal(std::shared_ptr<Node> root) {
	if (!root)
		return;

	reversePostorderTraversal(root->rchild);
	reversePostorderTraversal(root->lchild);
	std::cout << root->data << ", ";
}

void inorderTraversal(std::shared_ptr<Node> root) {
	if (!root)
		return;

	inorderTraversal(root->lchild);
	std::cout << root->data << ", ";
	inorderTraversal(root->rchild);
}

void reverseInorderTraversal(std::shared_ptr<Node> root) {
	if (!root)
		return;

	reverseInorderTraversal(root->rchild);
	std::cout << root->data << ", ";
	reverseInorderTraversal(root->lchild);
}

void traversals(std::shared_ptr<Node> root) {
	if (!root)
		return;

	std::cout << "Preorder traversal: ";
	preorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Reverse preorder traversal: ";
	reversePreorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Postorder traversal: ";
	postorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Reverse postorder traversal: ";
	reversePostorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Inorder traversal: ";
	inorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Reverse inorder traversal: ";
	reverseInorderTraversal(root);
	std::cout << std::endl;

	std::cout << std::endl;
}