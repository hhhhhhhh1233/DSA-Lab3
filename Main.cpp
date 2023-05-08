#include <iostream>
#include "Tree.h"

using std::cout;

int main()
{
	BinarySearchTree tree;

	for (int i = -5; i < 10; i++)
	{
		tree.MaintainedInsert(i);
	}
	cout << "digraph test { \n";
	tree.DisplayDot(tree.GetRoot(), "M "); cout << "\n";
	//tree.Display(tree.GetRoot());

	tree.RegenerateSubTree(tree.GetRoot());

	tree.DisplayDot(tree.GetRoot(), "P "); cout << "\n";
	cout << "}";

	////cout << "digraph test { \n";
	//tree.Display(tree.GetRoot());
	////tree.DisplayDot(tree.GetRoot(),"I "); cout << "\n";

	//tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	////tree.DisplayDot(tree.GetRoot(),"1 "); cout << "\n";
	//tree.ShiftLeft(tree.GetRoot()->GetRightNode());

	//cout << "\n";
	//tree.Display(tree.GetRoot());

	////tree.DisplayDot(tree.GetRoot(),"2 "); cout << "\n";
	//tree.ShiftLeft(tree.GetRoot()->GetRightNode());
	////tree.DisplayDot(tree.GetRoot(),"3 "); cout << "\n";
	//tree.ShiftRight(tree.GetRoot()->GetLeftNode()->GetLeftNode());
	////tree.DisplayDot(tree.GetRoot(),"4 "); cout << "\n";
	//tree.ShiftLeft(tree.GetRoot()->GetRightNode()->GetRightNode());
	//cout << "\n";
	//tree.Display(tree.GetRoot());

	////tree.DisplayDot(tree.GetRoot(), "F "); cout << "\n";
	////cout << "}";
}
