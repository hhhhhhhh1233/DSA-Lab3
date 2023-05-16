BinarySearchTree: Main.cpp Tree.cpp Tree.h
	@g++ -o3 Main.cpp Tree.cpp -o BinarySearchTree
test: BinarySearchTree
	@./BinarySearchTree

show: BinarySearchTree
	@./BinarySearchTree | dot -Tpng | display

graph: test
	python graphTime.py 
