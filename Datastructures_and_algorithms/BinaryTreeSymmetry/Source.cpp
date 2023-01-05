/*Given a binary tree, check if it has a symmetric structure or not
i.e., the left and right subtree mirror each other*/

#include "BinaryTreeUtil.h"
#include <iostream>

bool isSymmetric(Node* root);
bool isSymmetric(Node* left, Node* right);

bool isSymmetric(Node* root) {
	if (!root)
		return true;

	return isSymmetric(root->lchild, root->rchild);
}

bool isSymmetric(Node* left, Node* right) {
	if (!left && !right)
		return true;

	return (left && right) && isSymmetric(left->lchild, right->rchild) &&
		isSymmetric(left->rchild, right->lchild);
}

int main() {
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3);
	root->lchild->rchild = new Node(4);
	root->rchild->lchild = new Node(5);

	traversals(root);

	if (isSymmetric(root))
		std::cout << "Binary tree is symmetric!\n";
	else
		std::cout << "Binary tree is not symmetric...\n";

	return 0;
}