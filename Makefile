BinarySearchTree: Main.cpp Tree.cpp Tree.h
	g++ Main.cpp Tree.cpp -o BinarySearchTree
test: BinarySearchTree
	@./BinarySearchTree

show: BinarySearchTree
	@./BinarySearchTree | dot -Tpng | display
