#pragma once
#include <iostream>

template<typename elemType>
class BinaryTree
{
private:
	/* ===== Member 00 : �������ڵ� ===== */
	template<typename elemType>
	class Node
	{
	public:
		elemType element;
		Node* left;
		Node* right;

		// ���캯��
		Node(const elemType& p_ele, Node* p_lt, Node* p_rt)
			: element(p_ele), left(p_lt), right(p_rt) { }

		Node(elemType&& p_ele, Node* p_lt, Node* p_rt)
			: element(p_ele), left(p_lt), right(p_rt) { }
	};

	/* ===== Member 01 : ���ڵ� ===== */
	Node<elemType>* root;

	/* ===== Function 01 : ͨ������������� ===== */
	bool Create_pre(std::string::const_iterator& it, Node<elemType>*& node);

	/* ===== Function 02 : ������� ===== */
	void Traverse_pre(Node<elemType>* node);

	/* ===== Function 03 : ���ʵ�ǰ�ڵ� ===== */
	void Visit(Node<elemType>* node);

	/* ===== Function 04 : ������� ===== */
	void Traverse_in(Node<elemType>* node);

	/* ===== Function 05 : ������� ===== */
	void Traverse_pos(Node<elemType>* node);

	/* ===== Function 06 : ��ֵ���� ===== */
	Node<elemType>* FindVal(const elemType& ele, Node<elemType>* node);

	/* ===== Function 07 : ���루��������������׼�����򣬴˴���<�� ===== */
	void Insert(const elemType& ele, Node<elemType>*& node);

public:
	/* ===== Function 00 : Constructor ===== */
	BinaryTree();

	/* ===== Function 01 : ͨ������������� ===== */
	/* ���������������������������磺ABCD###E#F##G##������#��ʾΪ�� */
	bool Create_pre(std::string pre);

	/* ===== Function 02 : ������� ===== */
	void Traverse_pre();

	/* ===== Function 04 : ������� ===== */
	void Traverse_in();

	/* ===== Function 05 : ������� ===== */
	void Traverse_pos();

	/* ===== Function 06 : ��ֵ���� ===== */
	Node<elemType>* FindVal(const elemType& ele);

	/* ===== Function 07 : ���루��������������׼�����򣬴˴���<�� ===== */
	void Insert(const elemType& ele);

};

