#include "BinaryTree.h"

/* ===== Function 00 : Constructor ===== */
/* ===== 二叉树构造函数 ===== */
template<typename elemType>
inline BinaryTree<elemType>::BinaryTree()
{
	root = nullptr;
}

/* ===== Function 01 : 通过先序构造二叉树 ===== */
template<typename elemType>
bool BinaryTree<elemType>::Create_pre(std::string pre)
{
	// 根已存在直接返回false，不允许重构建
	if (root) return false;

	std::string::const_iterator it = pre.begin();

	return this->Create_pre(
		it,
		root
	);
}

template<typename elemType>
bool BinaryTree<elemType>::Create_pre(std::string::const_iterator& it, Node*& node)
{
	if (*it == '#')
	{
		node = nullptr;
	}
	else if (*it != '#')
	{
		node = new Node(*it, nullptr, nullptr);

		// 根的判断
		if (!root)
		{
			root = node;
		}

		Create_pre(++it, node->left);
		Create_pre(++it, node->right);
	}

	return true;
}


/* ===== Function 02 : 先序遍历 ===== */
template<typename elemType>
void BinaryTree<elemType>::Traverse_pre()
{
	this->Traverse_pre(root);
}

template<typename elemType>
void BinaryTree<elemType>::Traverse_pre(Node* node)
{
	if (!node) return;

	this->Visit(node);
	this->Traverse_pre(node->left);
	this->Traverse_pre(node->right);
}

/* ===== Function 03 : 访问当前节点 ===== */
template<typename elemType>
void BinaryTree<elemType>::Visit(Node* node)
{
	std::cout << node->element << std::endl;
}