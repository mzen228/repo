#include <iostream>

struct Node {
	int data;
	std::shared_ptr<Node> rchild;
	std::shared_ptr<Node> lchild;
	Node(int d) :data{ d }, rchild{ nullptr }, lchild{ nullptr } {}
};

void preorder(std::shared_ptr<Node> root) {

	if (!root)
		return;
	
	std::cout << root->data << ", ";

	preorder(root->lchild);

	preorder(root->rchild); 
}

void inorder(std::shared_ptr<Node> root) {

	if (!root)
		return;

	inorder(root->lchild);

	std::cout << root->data << ", ";

	inorder(root->rchild);
}

void postorder(std::shared_ptr<Node> root) {

	if (!root)
		return;

	postorder(root->lchild);

	postorder(root->rchild);

	std::cout << root->data << ", ";
}

void btTraversals(std::shared_ptr<Node> root) {
	std::cout << "Preorder traversal: ";
	preorder(root);
	std::cout << std::endl;

	std::cout << "Postorder traversal: ";
	postorder(root);
	std::cout << std::endl;

	std::cout << "Inorder traversal: ";
	inorder(root);
	std::cout << std::endl;
}

int main() {
	std::shared_ptr<Node> root = std::make_shared<Node>(1);
	root->lchild = std::make_shared<Node>(2);
	root->rchild = std::make_shared<Node>(3); 
	root->lchild->lchild = std::make_shared<Node>(4);
	root->lchild->rchild = std::make_shared<Node>(5);
	root->rchild->lchild = std::make_shared<Node>(6);
	root->rchild->rchild = std::make_shared<Node>(7);

	btTraversals(root);

	return 0;
}