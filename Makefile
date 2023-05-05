tree: Main.cpp Tree.cpp Tree.h
	g++ Main.cpp Tree.cpp Tree.h -o BinarySearchTree
test: BinarySearchTree
	./BinarySearchTree
