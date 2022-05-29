// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
template<typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };
 private:
	Node* root;
	Node* addNode(Node*, T);
	int depthTree(Node*);
	int searchNode(Node*, T);
 public:
	BST();
	void add(T);
	int depth();
	int search(T);
	BST(const BST<T>& temp);
	T getValue() { return root->value; }
};


template <typename T>
BST<T>::BST(const BST<T>&  temp) {
	root = new Node;
	root->value = temp.root->value;
	root->count = temp.root->count;
	root->left = root->right = nullptr;
}

template<typename T>
BST<T>::BST() :root(nullptr) {}

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
	if (root == nullptr) {
		root = new Node;
		root->value = value;
		root->count = 1;
		root->left = root->right = nullptr;
	}
	else if (root->value > value) {
		root->left = addNode(root->left, value);
	}
	else if (root->value < value) {
		root->right = addNode(root->right, value);
	}
	else
		root->count++;
	return root;
}

template<typename T>
void BST<T>::add(T value) {
	root = addNode(root, value);
}

template<typename T>
int BST<T>::depthTree(Node* root) {
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 0;
	int left = depthTree(root->left);
	int right = depthTree(root->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

template<typename T>
int BST<T>::depth() {
	return depthTree(root);
}

template<typename T>
int BST<T>::searchNode(Node* root, T value)
{
	if (root == nullptr)
		return 0;
	else if (root->value > value)
		return searchNode(root->left, value);
	else if (root->value < value)
		return searchNode(root->right, value);
	else
		return root->count;
}

template<typename T>
int BST<T>::search(T value)
{
	return searchNode(root, value);
}

BST<std::string> makeTree(const char* filename)
{
	BST<std::string> tree;
	ifstream file(filename);
	string str,node;
	while (!file.eof()) {
		node="";
		file >> str;
		bool flag = 0;
		for (int i = 0; i < str.length(); i++) {
			if (isalpha(str[i]))
			{
				flag = 1;
				str[i]=tolower(str[i]);
				node += str[i];
			}
			else if (flag == 1)
			{
				tree.add(node);
				node = "";
				flag = 0;
			}
		}
		if (!node.empty()) {
			tree.add(node);
		}
	}
	return tree;
#endif  // INCLUDE_BST_H_
