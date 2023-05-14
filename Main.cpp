#include <iostream>
#include "Tree.h"
#include <string>
#include <random>
#include <time.h>
#include <chrono>

using std::cout;

int main()
{
	srand(time(0));
	BinarySearchTree tree;
	// cout << "digraph test { \n";

	// for (int i = 0; i < 15; i++)
	// {
	// 	tree.Insert(i);
	// 	if (!tree.VerifySize(tree.GetRoot()))
	// 	{
	// 		cout << "Tree is Wrong!\n";
	// 		tree.Display(tree.GetRoot());
	// 	}
	// }
	// //cout << "Size of root is " << tree.NodeSize(tree.GetRoot()) << "\n";
	// tree.DisplayDot(tree.GetRoot(), "N ");
	// tree.RegenerateSubTree(tree.GetRoot()->GetRightNode()->GetRightNode());
	// tree.DisplayDot(tree.GetRoot(), "M ");

	// cout << "}";
	std::string nme[] = {"a ","b ","c ","d ","e ","f ","g ","h ","i ","j ","k ", "l ", "m ", "n ", "o "};

	int size = 40000000;
	int* nums = new int[size];

	//cout << "digraph test { \n";

	
	for (int i = 0; i < size; i++)
	{
		nums[i] = rand() % 100000000;
		//tree.DisplayDot(tree.GetRoot(), nme[i]);
	}

	cout << "DONE GENERATING " << size << " ELEMENTS\n";

	int x = 0;
	for (float j = 0.55f; j < 1; j += 0.05f)
	{
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < size; i++)
		{
			tree.MaintainedInsert(nums[i], j);
		}
		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
		cout << "Time taken: " << duration << " with c = " << j;
		
		double totalTime = 0;
		auto loopBegin = std::chrono::steady_clock::now();
		for (int i = 0; i < 100; i++)
		{
			begin = std::chrono::steady_clock::now();
			tree.Search(nums[i * (size/100)]);
			end = std::chrono::steady_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
			totalTime += duration;
		}
		auto loopEnd = std::chrono::steady_clock::now();
		auto loopDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
		cout << ", Average search time: " << totalTime/100 << " microseconds\n";
		//tree.Display(tree.GetRoot()); cout << "\n";
		//tree.DisplayDot(tree.GetRoot(), nme[x]);
		tree.DeleteTree(tree.GetRoot());
		x++;
	}
	delete nums;


	//tree.DisplayDot(tree.GetRoot(), "M "); cout << "\n";

	//tree.RegenerateSubTree(tree.GetRoot());

	//tree.DisplayDot(tree.GetRoot(), "P "); cout << "\n";
	//cout << "}";
}
