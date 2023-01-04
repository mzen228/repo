#include <iostream>

struct Node {
	int data;
	Node* rchild;
	Node* lchild;
	Node(int d) :data{ d }, rchild{ nullptr }, lchild{ nullptr } {}
};

void preorder(Node* root) {

	if (!root)
		return;
	
	std::cout << root->data << ", ";

	preorder(root->lchild);

	preorder(root->rchild); 
}

void inorder(Node* root) {

	if (!root)
		return;

	inorder(root->lchild);

	std::cout << root->data << ", ";

	inorder(root->rchild);
}

void postorder(Node* root) {

	if (!root)
		return;

	postorder(root->lchild);

	postorder(root->rchild);

	std::cout << root->data << ", ";
}

void btTraversals(Node* root) {
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
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3); 
	root->lchild->lchild = new Node(4);
	root->lchild->rchild = new Node(5);
	root->rchild->lchild = new Node(6);
	root->rchild->rchild = new Node(7);

	btTraversals(root);

	return 0;
}