#include "BSTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BSTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);
	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BSTree::Print_Inorder(Node* node)
{
	//���� ��ȸ (preorder traverse)
	//���� ��ȸ (inorder)
	//���� ��ȸ (postorder)

	//  [��]
	//[��][��]
	if (node == nullptr)
		return;
	//����: [��]�� �տ��´�
	//����: [��]�� �߰��� �´�
	//����: [��]�� �������� �´�

	//[��][��][��]
	cout << node->key << endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);
}

Node* BSTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

Node* BSTree::Search2(Node* node, int key)
{
	while (node && key != node->key)
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	return node;
}

Node* BSTree::Min(Node* node)
{
	while (node->left)
	{
		node = node->left;
	}
	return node;
}

Node* BSTree::Max(Node* node)
{
	while (node->right)
	{
		node = node->right;
	}
	return node;
}

Node* BSTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BSTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BSTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BSTree::Delete(Node* node)
{
	if (node == nullptr)
		return;
	if (node->left == nullptr)
		Replace(node, node->right);
	else if (node->right == nullptr)
		Replace(node, node->left);
	else
	{
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}

}

//u�� v ����Ʈ���� ��ü
//�׸��� delete u
void BSTree::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)
		v->parent = u->parent;

	delete u;
}
