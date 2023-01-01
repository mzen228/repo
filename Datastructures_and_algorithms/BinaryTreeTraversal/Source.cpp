#include <iostream>

struct Node {
	int data;
	Node* rchild;
	Node* lchild;
	Node(int d) :data{ d }, rchild{ nullptr }, lchild{ nullptr } {}
};

void preorder(Node* p) {

	if (!p)
		return;
	
	std::cout << p->data << ' ';

	preorder(p->lchild);

	preorder(p->rchild); 
}

void inorder(Node* p) {

	if (!p)
		return;

	inorder(p->lchild);

	std::cout << p->data << ' ';

	inorder(p->rchild);
}

void postorder(Node* p) {

	if (!p)
		return;

	postorder(p->lchild);

	postorder(p->rchild);

	std::cout << p->data << ' ';
}

int main() {
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3); 

	std::cout << "Preorder traversal: ";
	preorder(root);
	std::cout << std::endl;

	std::cout << "Inorder traversal: ";
	inorder(root);
	std::cout << std::endl;

	std::cout << "Postorder traversal: ";
	postorder(root);
	std::cout << std::endl;

	return 0;
}