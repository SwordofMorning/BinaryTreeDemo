#include <iostream>

#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
	BinaryTree<char> bt;

	bt.Create_pre("AB##C##");

	bt.Traverse_pre();


	return 0;
}