#pragma once

//       [10]
//   [5]       [20]
//[nil] [nil] [9] [30]

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};
};

class BSTree
{
public:
	void Print() { Print(_root, 10, 0); };
	void Print(Node* node, int x, int y);
	void Print_Inorder() { Print_Inorder(_root); };
	void Print_Inorder(Node* node);

	Node* Search(Node* node, int key); // Àç±ÍÇÔ¼ö.ver
	Node* Search2(Node* node, int key); // while¹®.ver

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Insert(int key);
	void Delete(int key);
	void Delete(Node* node);

	void Replace(Node* u, Node* v);

private:
	Node* _root = nullptr;
};

