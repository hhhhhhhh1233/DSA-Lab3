#pragma once

#include <string>

class Node
{
private:
	int data;
	int height;
	int size;
	Node* left;
	Node* right;
	Node* parent;
public:
	Node(int val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		height = 0;
		size = 1;
	}
	int GetSize() { return size; }
	void SetSize(int newSize) { size = newSize; }
	int GetData() { return data; }
	void SetData(int val) { data = val; }
	int GetHeight() { return height; }
	void SetHeight(int newDepth) { height = newDepth; }
	Node* GetRightNode() { return right; }
	void SetRightNode(Node* newRight) { right = newRight; }
	Node* GetLeftNode() { return left; }
	void SetLeftNode(Node* newLeft) { left = newLeft; }
	Node* GetParent() { return parent; }
	void SetParent(Node* newParent) { parent = newParent; }
};

class BinarySearchTree
{
private:
	Node* root;
public:
	Node* GetRoot() { return root; }
	BinarySearchTree();
	~BinarySearchTree();
	Node* Insert(int data);
	Node* MaintainedInsert(int data, float c);
	Node* Search(int data);
	void DeleteTree(Node* ref);
	void DeleteSubTree(Node* ref);
	void Display(Node* ref);
	void DisplayDot(Node* ref, std::string);
	void ShiftLeft(Node* ref);
	void ShiftRight(Node* ref);
	void CalculateDepth(Node* ref);
	void CalculateSize(Node* ref);
	void GetKeysInTree(Node* ref, int* arr, int& count);
	Node* GeneratePerfectTree(int arr[], int begin, int end);
	void RegenerateSubTree(Node* ref);
};
