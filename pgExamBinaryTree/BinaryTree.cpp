#include "BinaryTree.h"

/* ===== Function 00 : Constructor ===== */
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

	this->Traverse_in(node->left);
	this->Visit(node);
	this->Traverse_in(node->right);
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

	this->Traverse_pos(node->left);
	this->Traverse_pos(node->right);
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

/* ===== Function 07 : 插入（线索二叉树，按准则排序，此处用<） ===== */
template<typename elemType>
void BinaryTree<elemType>::Insert(const elemType& ele)
{
	this->Insert(ele, root);
}

template<typename elemType>
void BinaryTree<elemType>::Insert(const elemType& ele, Node<elemType>*& node)
{
	if (!node)
	{
		node = new Node<elemType>(ele, nullptr, nullptr);
	}
	else if (ele < node->element)
	{
		this->Insert(ele, node->left);
	}
	else if (node->element < ele)
	{
		this->Insert(ele, node->right);
	}
}

/* ===== Function 08 : 查找最小值 ===== */
template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindMin(Node<elemType>* node)
{
	if (!node) return nullptr;

	if (!node->left) return node;
	
	return FindMin(node->left);
}

/* ===== Function 09 : 查找最大值 ===== */
template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindMax(Node<elemType>* node)
{
	if (!node) return nullptr;

	if (!node->right) return node;

	return FindMax(node->right);
}

/* ===== Function 010 : 按元素删除 ===== */
template<typename elemType>
void BinaryTree<elemType>::Remove_val(const elemType& ele)
{
	this->Remove_val(ele, root);
}

template<typename elemType>
void BinaryTree<elemType>::Remove_val(const elemType& ele, Node<elemType>*& node)
{
	if (!node) return;

	if (ele < node->element)
		this->Remove_val(ele, node->left);
	else if (ele > node->element)
		this->Remove_val(ele, node->left);
	else if (node->left && node->right)		// 被删除目标有两个节点
	{
		node->element = this->FindMin(node->right)->element;
		Remove_val(node->element, node->right);
	}
	else									// 被删除目标只有一个节点或无节点
	{
		Node<elemType>* oldOne = node;
		node = (node->left) ?
			node->left :
			node->right;
		delete oldOne;
	}
}

/* ===== Function 11 : 高度 ===== */
template<typename elemType>
int BinaryTree<elemType>::Height()
{
	return this->Height(root);
}


template<typename elemType>
int BinaryTree<elemType>::Height(Node<elemType>* node)
{
	if (!node)	return 0;

	return std::max(this->Height(node->left), this->Height(node->right)) + 1;
}

/* ===== Function 12 : 宽度 ===== */
template<typename elemType>
int BinaryTree<elemType>::Width()
{
	return this->Width(root);
}

template<typename elemType>
int BinaryTree<elemType>::Width(Node<elemType>* node)
{
	if (!node)	return 0;

	std::deque<Node<elemType>*> dq;
	dq.push_back(node);

	int maxWidth = 1;
	int curentWidth = 1;

	while (!dq.empty())
	{
		while (curentWidth > 0)
		{
			// 队首出队，将下一层压入队列
			Node<elemType>* head = dq.front();
			dq.pop_front();

			if (head->left)	dq.push_back(head->left);
			if (head->right) dq.push_back(head->right);

			curentWidth--;
		}

		// 当前层的节点数
		curentWidth = dq.size();

		maxWidth = (maxWidth < curentWidth) ?
			curentWidth :
			maxWidth;
	}

	return maxWidth;
}
