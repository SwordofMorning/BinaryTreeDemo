#pragma once
#include <iostream>
#include <deque>

template<typename elemType>
class BinaryTree
{
private:
	/* ===== Member 00 : 二叉树节点 ===== */
	template<typename elemType>
	class Node
	{
	public:
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
	Node<elemType>* root;

	/* ===== Function 01 : 通过先序构造二叉树 ===== */
	bool Create_pre(std::string::const_iterator& it, Node<elemType>*& node);

	/* ===== Function 02 : 先序遍历 ===== */
	void Traverse_pre(Node<elemType>* node);

	/* ===== Function 03 : 访问当前节点 ===== */
	void Visit(Node<elemType>* node);

	/* ===== Function 04 : 中序遍历 ===== */
	void Traverse_in(Node<elemType>* node);

	/* ===== Function 05 : 后序遍历 ===== */
	void Traverse_pos(Node<elemType>* node);

	/* ===== Function 06 : 按值查找 ===== */
	Node<elemType>* FindVal(const elemType& ele, Node<elemType>* node);

	/* ===== Function 07 : 插入（线索二叉树，按准则排序，此处用<） ===== */
	void Insert(const elemType& ele, Node<elemType>*& node);

	/* ===== Function 08 : 查找最小值 ===== */
	Node<elemType>* FindMin(Node<elemType>* node);

	/* ===== Function 09 : 查找最大值 ===== */
	Node<elemType>* FindMax(Node<elemType>* node);

	/* ===== Function 10 : 按元素删除 ===== */
	void Remove_val(const elemType& ele, Node<elemType>*& node);

	/* ===== Function 11 : 高度 ===== */
	int Height(Node<elemType>* node);

	/* ===== Function 12 : 宽度 ===== */
	int Width(Node<elemType>* node);

	/* ===== Function 13 : 完全二叉树的判定 ===== */
	bool is_Complete(Node<elemType>* node);

	/* ===== Function 14 : 二叉树旋转 ===== */
	Node<elemType>* Mirror(Node<elemType>* node);

	/* ===== Function 15 : 平衡二叉树 ===== */
	bool is_Avl(Node<elemType>* node, int& height);

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

	/* ===== Function 06 : 按值查找 ===== */
	Node<elemType>* FindVal(const elemType& ele);

	/* ===== Function 07 : 插入（线索二叉树，按准则排序，此处用<） ===== */
	void Insert(const elemType& ele);

	/* ===== Function 10 : 按元素删除 ===== */
	void Remove_val(const elemType& ele);

	/* ===== Function 11 : 高度 ===== */
	int Height();

	/* ===== Function 12 : 宽度 ===== */
	int Width();

	/* ===== Function 13 : 完全二叉树的判定 ===== */
	bool is_Complete();

	/* ===== Function 14 : 二叉树旋转 ===== */
	Node<elemType>* Mirror();

	/* ===== Function 15 : 平衡二叉树 ===== */
	bool is_Avl();
};