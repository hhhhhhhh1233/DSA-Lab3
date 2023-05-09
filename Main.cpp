#include <iostream>
#include "Tree.h"
#include <string>
#include <random>

using std::cout;

int main()
{
	BinarySearchTree tree;
	std::string nme[] = {"a ","b ","c ","d ","e ","f ","g ","h ","i ","j ","k ", "l ", "m ", "n ", "o "};

	cout << "digraph test { \n";
	srand(time(0));

	for (int i = 0; i < 15; i++)
	{
		tree.MaintainedInsert(rand()%100);
		tree.DisplayDot(tree.GetRoot(), nme[i]);
	}
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
