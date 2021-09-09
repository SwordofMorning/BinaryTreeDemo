#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
	// BT

	BinaryTree<char> Tree_Char;

	std::cout << " ===== 构造一个普通的二叉树 ===== " << std::endl;
	Tree_Char.Create_pre("AB##C##");
	Tree_Char.Traverse_pre();
	std::cout << std::endl;
	Tree_Char.Traverse_in();
	std::cout << std::endl;
	Tree_Char.Traverse_pos();
	std::cout << std::endl;

	// Insert

	BinaryTree<int> Tree_Int;

	std::cout << " ===== 构造一个search二叉树 ===== " << std::endl;
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

	// Height

	std::cout << " ===== 高度计算 ===== " << std::endl;
	std::cout << Tree_Char.Height() << std::endl;
	std::cout << Tree_Int.Height() << std::endl;

	// Width
	std::cout << " ===== 宽度计算 ===== " << std::endl;
	std::cout << Tree_Char.Width() << std::endl;
	std::cout << Tree_Int.Width() << std::endl;

	// Complete
	std::cout << " ===== 判断是否是完全二叉树 ===== " << std::endl;
	std::cout << Tree_Char.is_Complete() << std::endl;
	std::cout << Tree_Int.is_Complete() << std::endl;

	// Remove
	std::cout << " ===== 移除线索二叉树的节点 val = 5 ===== " << std::endl;
	Tree_Int.Remove_val(5);
	Tree_Int.Traverse_in();
	std::cout << std::endl;

	// Height
	std::cout << " ===== 高度计算 ===== " << std::endl;
	std::cout << Tree_Int.Height() << std::endl;

	// Width
	std::cout << " ===== 高度计算 ===== " << std::endl;
	std::cout << Tree_Int.Width() << std::endl;

	// Complete
	std::cout << " ===== 判断是否是完全二叉树 ===== " << std::endl;
	std::cout << Tree_Int.is_Complete() << std::endl;

	// Mirror
	std::cout << " ===== 旋转 ===== " << std::endl;
	Tree_Char.Mirror();
	Tree_Int.Mirror();
	Tree_Char.Traverse_in();
	std::cout << std::endl;
	Tree_Int.Traverse_in();
	std::cout << std::endl;

	// is avl
	std::cout << " ===== 判断是否是平衡二叉树 ===== " << std::endl;
	std::cout << Tree_Char.is_Avl() << std::endl;
	std::cout << Tree_Int.is_Avl() << std::endl;

	// Remove
	std::cout << " ===== 移除线索二叉树的节点 val = 7、9 ===== " << std::endl;
	Tree_Int.Remove_val(7);
	Tree_Int.Remove_val(9);
	Tree_Int.Traverse_in();
	std::cout << std::endl;

	// is avl
	std::cout << " ===== 判断是否是平衡二叉树 ===== " << std::endl;
	std::cout << Tree_Int.is_Avl() << std::endl;
	return 0;
}