/*Convert a binary tree into itsm mirror by traversing the tree
in a postorder manner and swapping the left and right child pointers*/
#include <iostream>
#include "BinaryTreeUtil.h"

void postOrderChildSwap(std::shared_ptr<Node> root);

void postOrderChildSwap(std::shared_ptr<Node> root) {
	if (!root)
		return;

	postOrderChildSwap(root->lchild);
	postOrderChildSwap(root->rchild);

	auto tmp{ root->lchild };
	root->lchild = root->rchild;
	root->rchild = tmp;
}

int main() {
	auto root = std::make_shared<Node>(1);
	root->lchild = std::make_shared<Node>(2);
	root->rchild = std::make_shared<Node>(3);
	root->lchild->lchild = std::make_shared<Node>(4);
	root->lchild->rchild = std::make_shared<Node>(5);
	root->rchild->lchild = std::make_shared<Node>(6);
	root->rchild->rchild = std::make_shared<Node>(7);

	std::cout << "Original binary tree..." << std::endl;
	traversals(root);

	postOrderChildSwap(root);

	std::cout << "Mirror binary tree..." << std::endl; 
	traversals(root);

	return 0;
}