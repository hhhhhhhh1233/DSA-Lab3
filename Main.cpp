#include <iostream>
#include "Tree.h"

using std::cout;

int main()
{
	BinarySearchTree tree;
	
	for (int i = 0; i < 7; i++)
	{
		tree.Insert(i);
	}

	tree.Display(tree.GetRoot()); cout << "\n";

	tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	tree.ShiftRight(tree.GetRoot()->GetLeftNode()->GetLeftNode());
	tree.ShiftLeft(tree.GetRoot()->GetRightNode()->GetRightNode());
	
	tree.Display(tree.GetRoot()); cout << "\n";
}