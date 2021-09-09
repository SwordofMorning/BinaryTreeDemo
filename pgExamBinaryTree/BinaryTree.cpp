#include "BinaryTree.h"

/* ===== Function 00 : Constructor ===== */
template<typename elemType>
inline BinaryTree<elemType>::BinaryTree()
{
	root = nullptr;
}

/* ===== Function 01 : ͨ������������� ===== */
template<typename elemType>
bool BinaryTree<elemType>::Create_pre(std::string pre)
{
	// ���Ѵ���ֱ�ӷ���false���������ع���
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

/* ===== Function 02 : ������� ===== */
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

/* ===== Function 03 : ���ʵ�ǰ�ڵ� ===== */
template<typename elemType>
void BinaryTree<elemType>::Visit(Node<elemType>* node)
{
	std::cout << node->element;
}

/* ===== Function 04 : ������� ===== */
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

/* ===== Function 05 : ������� ===== */
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

/* ===== Function 06 : ��ֵ���� ===== */
template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindVal(const elemType& ele)
{
	return this->FindVal(ele, root);
}

template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindVal(const elemType& ele, Node<elemType>* node)
{
	// �սڵ�
	if (!node) return nullptr;

	// �ǵ�ǰ�ڵ�
	if (node->element == ele) return node;

	// ��������
	Node<elemType>* lt = nullptr;
	lt = this->FindVal(ele, node->left);

	if (lt) return lt;

	// ��������
	Node<elemType>* rt = nullptr;
	rt = this->FindVal(ele, node->right);

	if (rt) return rt;

	// �޽��
	return nullptr;
}

/* ===== Function 07 : ���루��������������׼�����򣬴˴���<�� ===== */
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

/* ===== Function 08 : ������Сֵ ===== */
template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindMin(Node<elemType>* node)
{
	if (!node) return nullptr;

	if (!node->left) return node;
	
	return FindMin(node->left);
}

/* ===== Function 09 : �������ֵ ===== */
template<typename elemType>
BinaryTree<elemType>::Node<elemType>* BinaryTree<elemType>::FindMax(Node<elemType>* node)
{
	if (!node) return nullptr;

	if (!node->right) return node;

	return FindMax(node->right);
}

/* ===== Function 010 : ��Ԫ��ɾ�� ===== */
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
	else if (node->left && node->right)		// ��ɾ��Ŀ���������ڵ�
	{
		node->element = this->FindMin(node->right)->element;
		Remove_val(node->element, node->right);
	}
	else									// ��ɾ��Ŀ��ֻ��һ���ڵ���޽ڵ�
	{
		Node<elemType>* oldOne = node;
		node = (node->left) ?
			node->left :
			node->right;
		delete oldOne;
	}
}

/* ===== Function 11 : �߶� ===== */
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

/* ===== Function 12 : ��� ===== */
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
			// ���׳��ӣ�����һ��ѹ�����
			Node<elemType>* head = dq.front();
			dq.pop_front();

			if (head->left)	dq.push_back(head->left);
			if (head->right) dq.push_back(head->right);

			curentWidth--;
		}

		// ��ǰ��Ľڵ���
		curentWidth = dq.size();

		maxWidth = (maxWidth < curentWidth) ?
			curentWidth :
			maxWidth;
	}

	return maxWidth;
}
