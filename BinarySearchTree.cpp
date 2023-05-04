#include <iostream>
#include "Tree.h"

using std::cout;

int main()
{
	BinarySearchTree tree;
	
	tree.Insert(2);
	tree.Insert(5);
	tree.Insert(0);
	tree.Insert(4);
	tree.Insert(-1);
	tree.Insert(1);
	
	tree.Display(tree.GetHead()); cout << "\n";

	//tree.shiftLeft(tree.GetHead()->GetRightNode());
	//tree.display(tree.GetHead()); cout << "\n";
	
	tree.ShiftRight(tree.GetHead()->GetLeftNode()->GetLeftNode());
	tree.Display(tree.GetHead());
}