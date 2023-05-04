#include "Tree.h"
#include <iostream>

using std::cout;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	DeleteTree(root);
}

void BinarySearchTree::Insert(int data)
{
	if (root == nullptr)
	{
		root = new Node(data);
		return;
	}

	Node* ref = root;
	Node* refParent;
	do
	{
		ref->SetSize(ref->GetSize() + 1);
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
	CalculateDepth(root);
	CalculateSize(root);
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

		cout << ref->GetData() << " at depth " << ref->GetDepth() << " with size " << ref->GetSize() << ", \n";
		Display(ref->GetLeftNode());
		Display(ref->GetRightNode());
	}
}

void BinarySearchTree::ShiftLeft(Node* ref)
{
	if (root == ref)
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

	if (parent == root)
	{
		root = ref;
	}

	parent->SetRightNode(child);
	ref->SetLeftNode(parent);

	ref->SetParent(parent->GetParent());
	parent->SetParent(ref);
	if (child != nullptr)
		child->SetParent(parent);
	CalculateDepth(grandParent);
	CalculateSize(grandParent);
}

void BinarySearchTree::ShiftRight(Node* ref)
{
	if (root == ref)
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

	if (parent == root)
	{
		root = ref;
	}

	parent->SetLeftNode(child);
	ref->SetRightNode(parent);

	ref->SetParent(parent->GetParent());
	parent->SetParent(ref);
	if (child != nullptr)
		child->SetParent(parent);
	CalculateDepth(grandParent);
	CalculateSize(grandParent);
}

void BinarySearchTree::CalculateDepth(Node* ref)
{
	if (ref != nullptr)
	{
		if (ref->GetLeftNode() == nullptr && ref->GetRightNode() == nullptr)
		{
			ref->SetDepth(0);
		}
		else if (ref->GetLeftNode() == nullptr)
		{
			CalculateDepth(ref->GetRightNode());
			ref->SetDepth(ref->GetRightNode()->GetDepth() + 1);
		}
		else if (ref->GetRightNode() == nullptr)
		{
			CalculateDepth(ref->GetLeftNode());
			ref->SetDepth(ref->GetLeftNode()->GetDepth() + 1);
		}
		else
		{
			CalculateDepth(ref->GetLeftNode());
			CalculateDepth(ref->GetRightNode());
			if (ref->GetLeftNode()->GetDepth() > ref->GetRightNode()->GetDepth())
				ref->SetDepth(ref->GetLeftNode()->GetDepth() + 1);
			else
				ref->SetDepth(ref->GetRightNode()->GetDepth() + 1);
		}
	}
}

void BinarySearchTree::CalculateSize(Node* ref)
{
	if (ref != nullptr)
	{
		if (ref->GetLeftNode() == nullptr && ref->GetRightNode() == nullptr)
		{
			ref->SetSize(1);
		}
		else if (ref->GetLeftNode() == nullptr)
		{
			CalculateSize(ref->GetRightNode());
			ref->SetSize(ref->GetRightNode()->GetSize() + 1);
		}
		else if (ref->GetRightNode() == nullptr)
		{
			CalculateSize(ref->GetLeftNode());
			ref->SetSize(ref->GetLeftNode()->GetSize() + 1);
		}
		else
		{
			CalculateSize(ref->GetLeftNode());
			CalculateSize(ref->GetRightNode());
			ref->SetSize(ref->GetLeftNode()->GetSize() + ref->GetRightNode()->GetSize() + 1);
		}
	}
}
