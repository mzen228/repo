#include <iostream>

struct Node {
	int data;
	std::shared_ptr<Node> lchild;
	std::shared_ptr<Node> rchild;
	Node(int d) :data{ d }, lchild{ nullptr }, rchild{ nullptr } {}
};

void rInorderTraversal(std::shared_ptr<Node> root) {

	if (!root) {
		return; 
	}

	rInorderTraversal(root->lchild);
	std::cout << root->data << ", ";
	rInorderTraversal(root->rchild);
}

void iInsert(std::shared_ptr<Node> root, int key) {

	std::shared_ptr<Node> t = nullptr; 

	while (root) {
		t = root;

		if (key < root->data) {
			root = root->lchild;
		}
		else if (key > root->data) {
			root = root->rchild;
		}
		else if (key == root->data) {
			return; 
		}
	}

	if (key < t->data) {
		t->lchild = std::make_shared<Node>(key);
	}
	else if (key > t->data) {
		t->rchild = std::make_shared<Node>(key); 
	}
}


int main() {
	auto root = std::make_shared<Node>(15);
	root->lchild = std::make_shared<Node>(10);
	root->lchild->lchild = std::make_shared<Node>(8);
	root->lchild->rchild = std::make_shared<Node>(12);
	root->rchild = std::make_shared<Node>(20);
	root->rchild->lchild = std::make_shared<Node>(16);
	root->rchild->rchild = std::make_shared<Node>(25);

	std::cout << "Original BST...\n";
	rInorderTraversal(root);
	std::cout << std::endl; 

	std::cout << "Inserting 17...\n";
	iInsert(root, 17);
	rInorderTraversal(root);
	std::cout << std::endl;

	std::cout << "Inserting 40...\n";
	iInsert(root, 40);
	rInorderTraversal(root);
	std::cout << std::endl;

	return 0;
}