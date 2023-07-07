
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

// Red-Black Tree 조건
//1) 모든 노드는Red or Black
//2) root는 Black
//3) NIL(Leaf)는 Black
//3) Red 노드의 자식은 Black(연속해서 Red- Red X)
//4) 각 노드로부터 ~ 리프까지 가는 경로들은 모두 같은 수의 Black을 만난다. (Delete에서 상당히 중요)

class RBTree
{
public:
	RBTree();
	~RBTree();

	void Print();
	void Print(Node* node, int x, int y);

	Node* Search(Node* node, int key); // 재귀함수.ver

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