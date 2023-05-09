#include <iostream>
#include "Tree.h"
#include <string>
#include <random>

using std::cout;

int main()
{
	srand(time(0));
	BinarySearchTree tree;
	std::string nme[] = {"a ","b ","c ","d ","e ","f ","g ","h ","i ","j ","k ", "l ", "m ", "n ", "o "};

	int nums[100];

	//cout << "digraph test { \n";

	
	for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
	{
		nums[i] = rand() % 100;
		//tree.DisplayDot(tree.GetRoot(), nme[i]);
	}

	int x = 0;
	for (float j = 0.5f; j < 1; j += 0.05f)
	{
		for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
		{
			tree.MaintainedInsert(nums[i], j);
		}
		//tree.Display(tree.GetRoot()); cout << "\n";
		tree.DisplayDot(tree.GetRoot(), nme[x]);
		tree.DeleteTree(tree.GetRoot());
		x++;
	}


	//tree.DisplayDot(tree.GetRoot(), "M "); cout << "\n";

	//tree.RegenerateSubTree(tree.GetRoot());

	//tree.DisplayDot(tree.GetRoot(), "P "); cout << "\n";
	//cout << "}";
}
