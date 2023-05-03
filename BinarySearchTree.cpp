#include <iostream>
using std::cout;

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
	int size = 0;
public:
	int GetSize() { return size; }
	Node* GetHead() { return head; }
	void insert(int data)
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
	void display(Node* ref)
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
			display(ref->GetLeftNode());
			display(ref->GetRightNode());
		}
	}
	void shiftLeft(Node* ref)
	{
		Node* parent = ref->GetParent();
		Node* child = ref->GetLeftNode();
		
		if (parent == head)
		{
			head = ref;
		}

		parent->SetRightNode(ref->GetLeftNode());
		ref->SetLeftNode(parent);

		ref->SetParent(parent->GetParent());
		parent->SetParent(ref);
		child->SetParent(parent);
	}

};

int main()
{
	BinarySearchTree tree;
	tree.insert(2);
	tree.insert(5);
	tree.insert(1);
	tree.insert(4);
	tree.insert(0);
	tree.display(tree.GetHead());
	cout << "\n";
	tree.shiftLeft(tree.GetHead()->GetRightNode());
	tree.display(tree.GetHead());
}