/*Given a binary tree, check if it has a symmetric structure or not
i.e., the left and right subtree mirror each other*/

#include "BinaryTreeUtil.h"
#include <iostream>

bool isSymmetric(std::shared_ptr<Node> root);
bool isSymmetric(std::shared_ptr<Node> left, std::shared_ptr<Node> right);

bool isSymmetric(std::shared_ptr<Node> root) {
	if (!root)
		return true;

	return isSymmetric(root->lchild, root->rchild);
}

bool isSymmetric(std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
	if (!left && !right)
		return true;

	return (left && right) && isSymmetric(left->lchild, right->rchild) &&
		isSymmetric(left->rchild, right->lchild);
}

int main() {
	auto root = std::make_shared<Node>(1);
	root->lchild = std::make_shared<Node>(2);
	root->rchild = std::make_shared<Node>(3);
	root->lchild->rchild = std::make_shared<Node>(4);
	root->rchild->lchild = std::make_shared<Node>(5);

	traversals(root);

	if (isSymmetric(root))
		std::cout << "Binary tree is symmetric!\n";
	else
		std::cout << "Binary tree is not symmetric...\n";

	return 0;
}