/*Evaluate a given binary expression tree representing an arithmetical expression*/
#include <string>
#include <iostream>

template <typename T>
struct Node {
	T data;
	std::shared_ptr<Node<T>> lchild;
	std::shared_ptr<Node<T>> rchild;
	Node(T data_) :data{ data_ }, lchild{ nullptr }, rchild{ nullptr } {}
};

int compute(std::string op, int a, int b) {
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
		return a / b;
}

double expressionTree(std::shared_ptr<Node<std::string>> root) {
	if (!root)
		return 0;

	if (!root->lchild && !root->rchild)
		return std::stod(root->data); 

	double x{ expressionTree(root->lchild) };
	double y{ expressionTree(root->rchild) };

	return compute(root->data, x, y);
}

int main() {
	// Binary tree that represents: ((10-5)*5)+(21/7)
	auto root = std::make_shared<Node<std::string>>("+");
	root->lchild = std::make_shared<Node<std::string>>("*");
	root->rchild = std::make_shared<Node<std::string>>("/");
	root->lchild->lchild = std::make_shared<Node<std::string>>("-");
	root->lchild->rchild = std::make_shared<Node<std::string>>("5");
	root->lchild->lchild->lchild = std::make_shared<Node<std::string>>("10");
	root->lchild->lchild->rchild = std::make_shared<Node<std::string>>("5");
	root->rchild->lchild = std::make_shared<Node<std::string>>("21");
	root->rchild->rchild = std::make_shared<Node<std::string>>("7");
	
	std::cout << "Expression tree result: " << expressionTree(root) << std::endl; 

	return 0;
}