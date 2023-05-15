#include <iostream>
#include "Tree.h"
#include <string>
#include <random>
#include <time.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>

std::random_device rd;     // Only used once to initialise (seed) engine
std::mt19937 rng(0);    // Random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(-1'000'000'000, 1'000'000'000); // Guaranteed unbiased


using std::cout;

int main()
{
	std::string nme[] = {"a ","b ","c ","d ","e ","f ","g ","h ","i ","j ","k ", "l ", "m ", "n ", "o "};

	int size = 5'000'000;

	float testedC[47];
	float timeTaken[47];

	int x = 0;
	for (float j = 0.53f; j <= 1.00f; j += 0.01f)
	{
		std::mt19937 rng(0);
		BinarySearchTree tree;
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < size; i++)
		{
			tree.MaintainedInsert(uni(rng), j);
		}
		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
		cout << "Time taken : " << duration << " with c = " << j << ", with " << size - tree.GetRoot()->GetSize() << " duplicates\n";

		testedC[x] = j;
		timeTaken[x] = duration;

		/*std::mt19937 rng(0);
		double totalTime = 0;
		auto loopBegin = std::chrono::steady_clock::now();
		for (int i = 0; i < 100; i++)
		{
			begin = std::chrono::steady_clock::now();
			tree.Search(uni(rng));
			end = std::chrono::steady_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
			totalTime += duration;
		}
		auto loopEnd = std::chrono::steady_clock::now();
		auto loopDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
		cout << ", Average search time: " << totalTime/100 << " microseconds\n";*/
		x++;
	}
	std::ofstream myfile;
	myfile.open("graphTime.py");
	myfile << "import matplotlib.pyplot as plt\nplt.plot([";
	for (int i = 0; i < 47 - 1; i++)
		myfile << testedC[i] << ", ";
	myfile << testedC[47 - 1] << "], ";
	myfile << "[";
	for (int i = 0; i < 47 - 1; i++)
		myfile << timeTaken[i] << ", ";
	myfile << timeTaken[47 - 1] << "])\nplt.show()";
	myfile.close();
}
