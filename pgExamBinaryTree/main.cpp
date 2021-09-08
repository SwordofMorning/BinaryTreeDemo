#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
	BinaryTree<char> Tree_Char;

	Tree_Char.Create_pre("AB##C##");
	Tree_Char.Traverse_pre();
	std::cout << std::endl;
	Tree_Char.Traverse_in();
	std::cout << std::endl;
	Tree_Char.Traverse_pos();
	std::cout << std::endl;

	std::cout << Tree_Char.FindVal('A') << std::endl;

	BinaryTree<int> Tree_Int;

	Tree_Int.Insert(5);
	Tree_Int.Insert(3);
	Tree_Int.Insert(7);
	Tree_Int.Insert(2);
	Tree_Int.Insert(9);
	Tree_Int.Insert(4);
	Tree_Int.Insert(6);
	Tree_Int.Traverse_pre();
	std::cout << std::endl;
	Tree_Int.Traverse_in();
	std::cout << std::endl;
	Tree_Int.Traverse_pos();
	std::cout << std::endl;



	return 0;
}