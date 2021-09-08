#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
	BinaryTree<char> bt;

	bt.Create_pre("AB##C##");

	bt.Traverse_pre();
	std::cout << std::endl;
	bt.Traverse_in();
	std::cout << std::endl;
	bt.Traverse_pos();
	std::cout << std::endl;

	std::cout << bt.FindVal('A') << std::endl;

	return 0;
}