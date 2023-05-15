#include <iostream>
#include "Tree.h"
#include <string>
#include <random>
#include <time.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>

using std::cout;

int main()
{
	cout << "Testing w/o random\n";
	for (float c = 0.65f; c <= 0.85f; c += 0.05f)
	{
		srand(0);
		BinarySearchTree tree;
		for (int i = 0; i < 200'000; i++)
		{
			tree.MaintainedInsert(i, c);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
	cout << "Testing w/ random\n";
	for (float c = 0.65f; c <= 0.85f; c += 0.05f)
	{
		srand(0);
		BinarySearchTree tree;
		for (int i = 0; i < 200'000; i++)
		{
			tree.MaintainedInsert(rand()%10'000'000, c);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}

	//std::string nme[] = {"a ","b ","c ","d ","e ","f ","g ","h ","i ","j ","k ", "l ", "m ", "n ", "o "};

	//int size = 20'000'000;

	//float testedC[25];
	//float timeTaken[25];

	//int x = 0;
	//for (float j = 0.51f; j <= 1.01f; j += 0.02f)
	//{
	//	srand(5);
	//	BinarySearchTree tree;
	//	auto begin = std::chrono::steady_clock::now();
	//	for (int i = 0; i < size; i++)
	//	{
	//		tree.MaintainedInsert(rand()%size, j);
	//	}
	//	auto end = std::chrono::steady_clock::now();
	//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
	//	cout << "Time taken: " << duration << " with c = " << j;

	//	testedC[x] = j;
	//	timeTaken[x] = duration;

	//	srand(5);
	//	double totalTime = 0;
	//	auto loopBegin = std::chrono::steady_clock::now();
	//	for (int i = 0; i < 100; i++)
	//	{
	//		begin = std::chrono::steady_clock::now();
	//		tree.Search(rand()%size);
	//		end = std::chrono::steady_clock::now();
	//		duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	//		totalTime += duration;
	//	}
	//	auto loopEnd = std::chrono::steady_clock::now();
	//	auto loopDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
	//	cout << ", Average search time: " << totalTime/100 << " microseconds\n";
	//	x++;
	//}
	//std::ofstream myfile;
	//myfile.open("graphTime.py");
	//myfile << "import matplotlib.pyplot as plt\nplt.plot([";
	//for (int i = 0; i < 25 - 1; i++)
	//	myfile << testedC[i] << ", ";
	//myfile << testedC[24] << "], ";
	//myfile << "[";
	//for (int i = 0; i < 25 - 1; i++)
	//	myfile << timeTaken[i] << ", ";
	//myfile << timeTaken[24] << "])\nplt.show()";
	//myfile.close();
}
