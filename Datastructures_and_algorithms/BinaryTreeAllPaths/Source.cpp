/*Print all possible paths from the root node to each leaf node*/
#include <iostream>
#include <algorithm>
#include <vector>
#include "BinaryTreeUtil.h"

void print(const std::vector<int>& vec);
bool isLeafNode(std::shared_ptr<Node> root); 
void printAllPaths(std::shared_ptr<Node> root);

void print(const std::vector<int>& vec) {
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
	std::cout << std::endl; 
}

bool isLeafNode(std::shared_ptr<Node> root) {
	return !root->lchild && !root->rchild;
}

void printAllPaths(std::shared_ptr<Node> root) {
	static std::vector<int> vec;

	if (!root)
		return;

	vec.push_back(root->data);

	if (isLeafNode(root))
		print(vec);

	printAllPaths(root->lchild);
	printAllPaths(root->rchild);
	vec.pop_back();
}

int main() {
	auto root = std::make_shared<Node>(1);
	root->lchild = std::make_shared<Node>(2);
	root->rchild = std::make_shared<Node>(3);
	root->lchild->lchild = std::make_shared<Node>(4);
	root->lchild->rchild = std::make_shared<Node>(5);
	root->rchild->lchild = std::make_shared<Node>(6);
	root->rchild->rchild = std::make_shared<Node>(7);
	root->rchild->lchild->lchild = std::make_shared<Node>(8);
	root->rchild->rchild->rchild = std::make_shared<Node>(9);

	std::cout << "Printing all possible paths from the root node to each leaf node...\n";
	printAllPaths(root);

	return 0;
}