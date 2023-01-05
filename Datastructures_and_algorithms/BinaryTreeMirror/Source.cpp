/*Convert a binary tree into itsm mirror by traversing the tree
in a postorder manner and swapping the left and right child pointers*/
#include <iostream>
#include "BinaryTreeUtil.h"

void postOrderChildSwap(Node* root);

void postOrderChildSwap(Node* root) {
	if (!root)
		return;

	postOrderChildSwap(root->lchild);
	postOrderChildSwap(root->rchild);

	Node* tmp{ root->lchild };
	root->lchild = root->rchild;
	root->rchild = tmp;
}

int main() {
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3);
	root->lchild->lchild = new Node(4);
	root->lchild->rchild = new Node(5);
	root->rchild->lchild = new Node(6);
	root->rchild->rchild = new Node(7);

	std::cout << "Original binary tree..." << std::endl;
	traversals(root);

	postOrderChildSwap(root);

	std::cout << "Mirror binary tree..." << std::endl; 
	traversals(root);

	return 0;
}