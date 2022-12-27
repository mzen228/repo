#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& v) {
	int tmp{};
	for (size_t i{}; i < v.size() - 1; i++) {
		for (size_t j{}; j < v.size() - 1 - i; j++) {
			if (v.at(j) > v.at(j + 1)) {
				tmp = v.at(j);
				v.at(j) = v.at(j + 1);
				v.at(j + 1) = tmp;
			}
		}
	}
}

void printVec(std::vector<int> v) {
	for (auto element : v) {
		std::cout << element << " ";
	}
	std::cout << "\n";
}

int main() {
	std::vector<int> v{ 5,4,3,2,1 };

	printVec(v);

	bubbleSort(v);

	printVec(v);

	std::reverse(v.begin(), v.end());

	printVec(v);
}