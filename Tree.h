#pragma once

class Node
{
private:
	int data;
	int depth;
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
		depth = 0;
		size = 1;
	}
	int GetSize() { return size; }
	void SetSize(int newSize) { size = newSize; }
	int GetData() { return data; }
	void SetData(int val) { data = val; }
	int GetDepth() { return depth; }
	void SetDepth(int newDepth) { depth = newDepth; }
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
	void Insert(int data);
	void DeleteTree(Node* ref);
	void Display(Node* ref);
	void ShiftLeft(Node* ref);
	void ShiftRight(Node* ref);
	void CalculateDepth(Node* ref);
	void CalculateSize(Node* ref);
};