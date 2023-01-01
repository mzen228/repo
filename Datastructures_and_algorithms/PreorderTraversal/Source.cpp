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

int main() {
	Node* root = new Node(1);
	root->lchild = new Node(2);
	root->rchild = new Node(3); 

	std::cout << "Preorder traversal: ";
	preorder(root);
}