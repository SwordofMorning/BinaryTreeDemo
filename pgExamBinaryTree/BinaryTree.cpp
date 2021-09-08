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
bool BinaryTree<elemType>::Create_pre(std::string::const_iterator& it, Node<elemType>*& node)
{
	if (*it == '#')
	{
		node = nullptr;
	}
	else if (*it != '#')
	{
		node = new Node<elemType>(*it, nullptr, nullptr);

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
void BinaryTree<elemType>::Traverse_pre(Node<elemType>* node)
{
	if (!node) return;

	this->Visit(node);
	this->Traverse_pre(node->left);
	this->Traverse_pre(node->right);
}

/* ===== Function 03 : 访问当前节点 ===== */
template<typename elemType>
void BinaryTree<elemType>::Visit(Node<elemType>* node)
{
	std::cout << node->element;
}

/* ===== Function 04 : 中序遍历 ===== */
template<typename elemType>
void BinaryTree<elemType>::Traverse_in()
{
	this->Traverse_in(root);
}

template<typename elemType>
void BinaryTree<elemType>::Traverse_in(Node<elemType>* node)
{
	if (!node) return;

	this->Traverse_pre(node->left);
	this->Visit(node);
	this->Traverse_pre(node->right);
}

/* ===== Function 05 : 后序遍历 ===== */
template<typename elemType>
void BinaryTree<elemType>::Traverse_pos()
{
	this->Traverse_pos(root);
}

template<typename elemType>
void BinaryTree<elemType>::Traverse_pos(Node<elemType>* node)
{
	if (!node) return;

	this->Traverse_pre(node->left);
	this->Traverse_pre(node->right);
	this->Visit(node);
}

/* ===== Function 06 : 按值查找 ===== */
template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindVal(const elemType& ele)
{
	return this->FindVal(ele, root);
}

template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindVal(const elemType& ele, Node<elemType>* node)
{
	// 空节点
	if (!node) return nullptr;

	// 是当前节点
	if (node->element == ele) return node;

	// 查左子树
	Node<elemType>* lt = nullptr;
	lt = this->FindVal(ele, node->left);

	if (lt) return lt;

	// 查右子树
	Node<elemType>* rt = nullptr;
	rt = this->FindVal(ele, node->right);

	if (rt) return rt;

	// 无结果
	return nullptr;
}