#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
	// BT

	BinaryTree<char> Tree_Char;

	std::cout << " ===== ����һ����ͨ�Ķ����� ===== " << std::endl;
	Tree_Char.Create_pre("AB##C##");
	Tree_Char.Traverse_pre();
	std::cout << std::endl;
	Tree_Char.Traverse_in();
	std::cout << std::endl;
	Tree_Char.Traverse_pos();
	std::cout << std::endl;

	// Insert

	BinaryTree<int> Tree_Int;

	std::cout << " ===== ����һ��search������ ===== " << std::endl;
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

	std::cout << " ===== �߶ȼ��� ===== " << std::endl;
	std::cout << Tree_Char.Height() << std::endl;
	std::cout << Tree_Int.Height() << std::endl;

	// Width
	std::cout << " ===== ��ȼ��� ===== " << std::endl;
	std::cout << Tree_Char.Width() << std::endl;
	std::cout << Tree_Int.Width() << std::endl;

	// Complete
	std::cout << " ===== �ж��Ƿ�����ȫ������ ===== " << std::endl;
	std::cout << Tree_Char.is_Complete() << std::endl;
	std::cout << Tree_Int.is_Complete() << std::endl;

	// Remove
	std::cout << " ===== �Ƴ������������Ľڵ� val = 5 ===== " << std::endl;
	Tree_Int.Remove_val(5);
	Tree_Int.Traverse_in();
	std::cout << std::endl;

	// Height
	std::cout << " ===== �߶ȼ��� ===== " << std::endl;
	std::cout << Tree_Int.Height() << std::endl;

	// Width
	std::cout << " ===== �߶ȼ��� ===== " << std::endl;
	std::cout << Tree_Int.Width() << std::endl;

	// Complete
	std::cout << " ===== �ж��Ƿ�����ȫ������ ===== " << std::endl;
	std::cout << Tree_Int.is_Complete() << std::endl;

	// Mirror
	std::cout << " ===== ��ת ===== " << std::endl;
	Tree_Char.Mirror();
	Tree_Int.Mirror();
	Tree_Char.Traverse_in();
	std::cout << std::endl;
	Tree_Int.Traverse_in();
	std::cout << std::endl;

	// is avl
	std::cout << " ===== �ж��Ƿ���ƽ������� ===== " << std::endl;
	std::cout << Tree_Char.is_Avl() << std::endl;
	std::cout << Tree_Int.is_Avl() << std::endl;

	// Remove
	std::cout << " ===== �Ƴ������������Ľڵ� val = 7��9 ===== " << std::endl;
	Tree_Int.Remove_val(7);
	Tree_Int.Remove_val(9);
	Tree_Int.Traverse_in();
	std::cout << std::endl;

	// is avl
	std::cout << " ===== �ж��Ƿ���ƽ������� ===== " << std::endl;
	std::cout << Tree_Int.is_Avl() << std::endl;
	return 0;
}