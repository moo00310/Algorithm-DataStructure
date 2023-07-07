
#pragma once
//       [10]
//   [5]       [20]
//[NIL] [NIL] [9] [30]

enum class Color
{
	Red = 0,
	Black =1,
};

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};
	Color color = Color::Black;
};

// Red-Black Tree ����
//1) ��� ����Red or Black
//2) root�� Black
//3) NIL(Leaf)�� Black
//3) Red ����� �ڽ��� Black(�����ؼ� Red- Red X)
//4) �� ���κ��� ~ �������� ���� ��ε��� ��� ���� ���� Black�� ������. (Delete���� ����� �߿�)

class RBTree
{
public:
	RBTree();
	~RBTree();

	void Print();
	void Print(Node* node, int x, int y);

	Node* Search(Node* node, int key); // ����Լ�.ver

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Insert(int key);
	void InsertFixup(Node* node);

	void Delete(int key);
	void Delete(Node* node);
	void DeleteFixup(Node* node);

	void Replace(Node* u, Node* v);

	void LeftRotate(Node* x);
	void RightRotate(Node* y);

private:
	Node* _root = nullptr;
	Node* _nil = nullptr;
};