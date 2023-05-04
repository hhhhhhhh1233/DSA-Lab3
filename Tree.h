#pragma once

class Node
{
private:
	int data;
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
	}
	int GetData() { return data; }
	void SetData(int val) { data = val; }
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
	Node* head;
	int size;
public:
	int GetSize() { return size; }
	Node* GetHead() { return head; }
	BinarySearchTree();
	~BinarySearchTree();
	void Insert(int data);
	void DeleteTree(Node* ref);
	void Display(Node* ref);
	void ShiftLeft(Node* ref);
	void ShiftRight(Node* ref);
};