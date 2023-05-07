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

	cout << "digraph test { \n";

	tree.DisplayDot(tree.GetRoot(),"I "); cout << "\n";

	tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	tree.DisplayDot(tree.GetRoot(),"1 "); cout << "\n";
	tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	tree.DisplayDot(tree.GetRoot(),"2 "); cout << "\n";
	tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	tree.DisplayDot(tree.GetRoot(),"3 "); cout << "\n";
	tree.ShiftRight(tree.GetRoot()->GetLeftNode()->GetLeftNode());
	tree.DisplayDot(tree.GetRoot(),"4 "); cout << "\n";
	tree.ShiftLeft(tree.GetRoot()->GetRightNode()->GetRightNode());

	tree.DisplayDot(tree.GetRoot(), "F "); cout << "\n";
	cout << "}";
}
