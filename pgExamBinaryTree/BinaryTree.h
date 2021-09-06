#pragma once
#include <iostream>

template<typename elemType>
class BinaryTree
{
private:
	/* ===== Member 00 : 二叉树节点 ===== */
	struct Node
	{
		elemType element;
		Node* left;
		Node* right;

		// 构造函数
		Node(const elemType& p_ele, Node* p_lt, Node* p_rt)
			: element(p_ele), left(p_lt), right(p_rt) { }

		Node(elemType&& p_ele, Node* p_lt, Node* p_rt)
			: element(p_ele), left(p_lt), right(p_rt) { }
	};

	/* ===== Member 01 : 根节点 ===== */
	Node* root;

	/* ===== Function 01 : 通过先序构造二叉树 ===== */
	bool Create_pre(std::string::const_iterator& it, Node*& node);

	/* ===== Function 02 : 先序遍历 ===== */
	void Traverse_pre(Node* node);

	/* ===== Function 03 : 访问当前节点 ===== */
	void Visit(Node* node);

	/* ===== Function 04 : 中序遍历 ===== */
	void Traverse_in(Node* node);

	/* ===== Function 05 : 后序遍历 ===== */
	void Traverse_pos(Node* node);

public:
	/* ===== Function 00 : Constructor ===== */
	BinaryTree();

	/* ===== Function 01 : 通过先序构造二叉树 ===== */
	/* 参数：二叉树先序遍历结果，例如：ABCD###E#F##G##，其中#表示为空 */
	bool Create_pre(std::string pre);

	/* ===== Function 02 : 先序遍历 ===== */
	void Traverse_pre();

	/* ===== Function 04 : 中序遍历 ===== */
	void Traverse_in();

	/* ===== Function 05 : 后序遍历 ===== */
	void Traverse_pos();
};

