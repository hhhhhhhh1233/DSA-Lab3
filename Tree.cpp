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

Node* BinarySearchTree::Insert(int data)
{
	if (root == nullptr)
	{
		root = new Node(data);
		return root;
	}

	Node* newNode = new Node(data);

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
		else
		{
			cout << "WARNING: Key " << data << " already exists in tree!\n";
			return ref;
		}
	} while (ref != nullptr);
	if (data > refParent->GetData())
	{
		refParent->SetRightNode(newNode);
		refParent->GetRightNode()->SetParent(refParent);
	}
	else if (data < refParent->GetData())
	{
		refParent->SetLeftNode(newNode);
		refParent->GetLeftNode()->SetParent(refParent);
	}
	CalculateDepth(root);
	CalculateSize(root);
	return newNode;
}

void BinarySearchTree::DeleteTree(Node* ref)
{
	if (ref == root)
		root = nullptr;
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
				cout << "ERROR: Parent mismatch! " << ref->GetData() << " is not parented to " << ref->GetLeftNode()->GetData() << "\n";
		if (ref->GetRightNode() != nullptr)
			if (ref->GetRightNode()->GetParent() != ref)
				cout << "ERROR: Parent mismatch! " << ref->GetData() << " is not parented to " << ref->GetRightNode()->GetData() << "\n"; 

		Display(ref->GetLeftNode());
		if (ref == root)
			cout << "Key " << ref->GetData() << " at height " << ref->GetHeight() << " with size " << ref->GetSize() << " parented to nullptr" << ", \n";
		else
			cout << "Key " << ref->GetData() << " at height " << ref->GetHeight() << " with size " << ref->GetSize() << " parented to " << ref->GetParent()->GetData() << ", \n";
		Display(ref->GetRightNode());
	}
}

void BinarySearchTree::DisplayDot(Node* ref, const char* prefix)
{
	if (ref != nullptr)
	{
		if (ref->GetLeftNode() != nullptr)
			if (ref->GetLeftNode()->GetParent() != ref)
				cout << "ERROR: Parent mismatch! " << ref->GetData() << " is not parented to " << ref->GetLeftNode()->GetData() << "\n";
		if (ref->GetRightNode() != nullptr)
			if (ref->GetRightNode()->GetParent() != ref)
				cout << "ERROR: Parent mismatch! " << ref->GetData() << " is not parented to " << ref->GetRightNode()->GetData() << "\n";
		if (ref->GetParent() != nullptr) {
			cout << "  \"" << prefix << ref->GetParent()->GetData() << "\" ->  \"" << prefix << ref->GetData() << "\";\n";
		}
		DisplayDot(ref->GetLeftNode(), prefix);
		DisplayDot(ref->GetRightNode(), prefix);
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
	if (grandParent != nullptr)
	{
		CalculateDepth(grandParent);
		CalculateSize(grandParent);
	}
	else
	{
		CalculateDepth(parent);
		CalculateSize(parent);
	}
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
	if (grandParent != nullptr)
	{
		CalculateDepth(grandParent);
		CalculateSize(grandParent);
	}
	else
	{
		CalculateDepth(parent);
		CalculateSize(parent);
	}
}

void BinarySearchTree::CalculateDepth(Node* ref)
{
	if (ref != nullptr)
	{
		if (ref->GetLeftNode() == nullptr && ref->GetRightNode() == nullptr)
		{
			ref->SetHeight(0);
		}
		else if (ref->GetLeftNode() == nullptr)
		{
			CalculateDepth(ref->GetRightNode());
			ref->SetHeight(ref->GetRightNode()->GetHeight() + 1);
		}
		else if (ref->GetRightNode() == nullptr)
		{
			CalculateDepth(ref->GetLeftNode());
			ref->SetHeight(ref->GetLeftNode()->GetHeight() + 1);
		}
		else
		{
			CalculateDepth(ref->GetLeftNode());
			CalculateDepth(ref->GetRightNode());
			if (ref->GetLeftNode()->GetHeight() > ref->GetRightNode()->GetHeight())
				ref->SetHeight(ref->GetLeftNode()->GetHeight() + 1);
			else
				ref->SetHeight(ref->GetRightNode()->GetHeight() + 1);
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

void BinarySearchTree::GetKeysInTree(Node* ref, int* arr, int& count)
{
	if (ref != nullptr)
	{
		GetKeysInTree(ref->GetLeftNode(), arr, count);
		arr[count] = ref->GetData();
		count++;
		/*for (int i = 0;; i++)
		{
			if (arr[i] == NULL)
			{
				arr[i] = ref->GetData();
				break;
			}
		}*/
		GetKeysInTree(ref->GetRightNode(), arr, count);
	}
}

Node* BinarySearchTree::GeneratePerfectTree(int arr[], int begin, int end)
{
	if (end - begin == 0)
	{
		return Insert(arr[begin]);
	}
	if (end - begin == 1)
	{
		Node* ba = Insert(arr[begin]);
		Insert(arr[end]);
		return ba;
	}
	int median = (begin + end) / 2;
	
	Node* ba = Insert(arr[median]);
	GeneratePerfectTree(arr, begin, median - 1);
	GeneratePerfectTree(arr, median + 1, end);
	return ba;
}

void BinarySearchTree::RegenerateSubTree(Node* ref)
{
	int size = ref->GetSize();
	int* arr = new int[size] {NULL};
	int counter = 0;

	GetKeysInTree(ref, arr, counter);
	if (ref->GetParent() != nullptr)
		if (ref->GetParent()->GetRightNode() == ref)
			ref->GetParent()->SetRightNode(nullptr);
		else if (ref->GetParent()->GetLeftNode() == ref)
			ref->GetParent()->SetLeftNode(nullptr);
	DeleteTree(ref);
	GeneratePerfectTree(arr, 0, size - 1);
}
