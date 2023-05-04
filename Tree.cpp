#include "Tree.h"
#include <iostream>
using std::cout;

BinarySearchTree::BinarySearchTree()
{
	head = nullptr;
	size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	DeleteTree(head);
}

	void BinarySearchTree::Insert(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		size = 1;
		return;
	}
	Node* ref = head;
	Node* refParent;
	do
	{
		refParent = ref;
		if (data > ref->GetData())
		{
			ref = ref->GetRightNode();
		}
		else if (data < ref->GetData())
		{
			ref = ref->GetLeftNode();
		}
	} while (ref != nullptr);
	if (data > refParent->GetData())
	{
		refParent->SetRightNode(new Node(data));
		refParent->GetRightNode()->SetParent(refParent);
	}
	else if (data < refParent->GetData())
	{
		refParent->SetLeftNode(new Node(data));
		refParent->GetLeftNode()->SetParent(refParent);
	}
	size++;
}
void BinarySearchTree::DeleteTree(Node* ref)
{
	if (ref != nullptr)
	{
		DeleteTree(ref->GetLeftNode());
		DeleteTree(ref->GetRightNode());
		delete ref;
	}
}

	void BinarySearchTree::Display(Node* ref)
{
	if (ref != nullptr)
	{
		if (ref->GetLeftNode() != nullptr)
			if (ref->GetLeftNode()->GetParent() != ref)
				cout << "\nERROR: Parent mismatch!\n";
		if (ref->GetRightNode() != nullptr)
			if (ref->GetRightNode()->GetParent() != ref)
				cout << "\nERROR: Parent mismatch!\n";

		cout << ref->GetData() << ", ";
		Display(ref->GetLeftNode());
		Display(ref->GetRightNode());
	}
}

void BinarySearchTree::ShiftLeft(Node* ref)
{
	if (head == ref)
	{
		return;
	}

	Node* parent = ref->GetParent();
	Node* child = ref->GetLeftNode();
	Node* grandParent = parent->GetParent();

	if (grandParent != nullptr)
	{
		if (grandParent->GetLeftNode() == parent)
			grandParent->SetLeftNode(ref);
		if (grandParent->GetRightNode() == parent)
			grandParent->SetRightNode(ref);
	}

	if (parent == head)
	{
		head = ref;
	}

	parent->SetRightNode(child);
	ref->SetLeftNode(parent);

	ref->SetParent(parent->GetParent());
	parent->SetParent(ref);
	child->SetParent(parent);
}

void BinarySearchTree::ShiftRight(Node* ref)
{
	if (head == ref)
	{
		return;
	}


	Node* parent = ref->GetParent();
	Node* child = ref->GetRightNode();
	Node* grandParent = parent->GetParent();

	if (grandParent != nullptr)
	{
		if (grandParent->GetLeftNode() == parent)
			grandParent->SetLeftNode(ref);
		if (grandParent->GetRightNode() == parent)
			grandParent->SetRightNode(ref);
	}

	if (parent == head)
	{
		head = ref;
	}

	parent->SetLeftNode(child);
	ref->SetRightNode(parent);

	ref->SetParent(parent->GetParent());
	parent->SetParent(ref);
	if (child != nullptr)
		child->SetParent(parent);
}