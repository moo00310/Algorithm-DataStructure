#include "RBTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE

};

void SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

RBTree::RBTree()
{ 
	//널 포인터 역할
	_nil = new Node(); //black
	_root = _nil;
}

RBTree::~RBTree()
{
	delete _nil;
}

void RBTree::Print(Node* node, int x, int y)
{
	if (node == _nil)
		return;

	SetCursorPosition(x, y);

	if (node->color == Color::Black)
		SetCursorColor(ConsoleColor::BLUE);
	else
		SetCursorColor(ConsoleColor::RED);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

	SetCursorColor(ConsoleColor::WHITE);
}

Node* RBTree::Search(Node* node, int key)
{
	if (node == _nil || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

Node* RBTree::Min(Node* node)
{
	while (node->left != _nil)
	{
		node = node->left;
	}
	return node;
}

Node* RBTree::Max(Node* node)
{
	while (node->right != _nil)
	{
		node = node->right;
	}
	return node;
}

Node* RBTree::Next(Node* node)
{
	if (node->right != _nil)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent != _nil && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void RBTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	Node* node = _root;
	Node* parent = _nil;

	while (node != _nil)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;

	if (parent == _nil)
		_root = newNode;
	else if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;

	//검사
	newNode->left = _nil;
	newNode->right = _nil;
	newNode->color = Color::Red;

	InsertFixup(newNode);
}

void RBTree::InsertFixup(Node* node)
{
	//1) p = red, uncle = red
	// -> p= black, uncle= black, pp = red로 바꿈
	// 
	//2) p = red, uncle = black (triangle)
	// -> 회전을 통해 case3으로 바꿔줌
	// 
	//3) p = red, uncle = black (list)
	// -> 색상병경 + 회전

	// [ppp](R)
	//       [pp(B)]            [pp(R)]       
	//  [p(R)]   [u(?)]  -> [p(B)]    [u(B)라면] 로 교체
	//     [n(R)]		       [n(R)]

	while (node->parent->color == Color::Red)
	{
		if (node->parent == node->parent->parent->left)
		{
			Node* uncle = node->parent->parent->right;
			if (uncle->color == Color::Red)
			{
				node->parent->color = Color::Black; //p
				uncle->color = Color::Black; //u
				node->parent->parent->color = Color::Red; //pp

				node = node->parent->parent; //[pp]의 조건도 검사
			}
			else
			{
				//     [pp(B)]       (Left Rotate)         [pp(B)]    
				//  [p(R)]   [u(B)]       ->		   [n(R)]    [u(B)] 
				//     [n(R)]					   [p(R)]		

				if (node == node->parent->right) //Triangle 타입
				{
					node = node->parent;
					LeftRotate(node);
				}


				//        [pp(R)]      (RightRotate)        [p(B)]    
				//   [p(B)]    [u(B)]        ->        [n(R)]    [pp(R)] 
				// [n(R)]									        [u(B)]

				//List 타입
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				RightRotate(node->parent->parent);
			}	
		}		
		else
		{
			//       [pp(B)]                  [pp(R)]       
			//  [u(R)]   [p(R)]       ->  [u(B)]    [p(B)]
			//              [n(R)]		                [n(R)]

			Node* uncle = node->parent->parent->left;
			if (uncle->color == Color::Red)
			{
				node->parent->color = Color::Black; //p
				uncle->color = Color::Black; //u
				node->parent->parent->color = Color::Red; //pp

				node = node->parent->parent; //[pp]의 조건도 검사
			}
			else
			{
				//      [pp(B)]         (Right Rotate)          [pp(B)]    
				//  [u(B)]     [p(R)]         ->		    [u(B)]    [p(R)] 
				//           [n(R)]					                     [n(R)]		

				if (node == node->parent->left) //Triangle 타입
				{
					node = node->parent;
					RightRotate(node);
				}

				//      [pp(B)]                                [pp(R)]         
				// [u(B)]    [p(R)]             ->        [u(B)]    [p(B)]     
				//               [n(R)]						              [n(R)]	

				//    (Left Rotate) 

				//          [p(B)]        
				//    [pp(R)]    [n(R)]    
				// [u(B)]

				//List 타입
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				LeftRotate(node->parent->parent);
			}
		}
	}

	_root->color = Color::Black;
}

void RBTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void RBTree::Delete(Node* node)
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

//u를 v 서브트리로 교체
//그리고 delete u
void RBTree::Replace(Node* u, Node* v)
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

//     [p]                                 [p]
//     [y]      (Right Rotate 시계방향)     [x]   
//  [x]   [3]             ->		    [1]     [y]  
//[1][2]	   	(Left Rotate 반시계방향)      [2] [3]
//                         <-

void RBTree::LeftRotate(Node* x)
{
	Node* y = x->right;

	x->right = y->left; //[2]

	if(y->left!=_nil)
		y->left->parent = x;

	y->parent = x->parent;

	if (x->parent == _nil)
		_root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;

}

void RBTree::RightRotate(Node* y)
{
	Node* x = y->left;

	y->left = x->right;

	if (y->right != _nil)
		y->right->parent = y;

	x->parent = y->parent;

	if (y->parent == _nil)
		_root = x;
	else if (y == y->parent->right)
		y->parent->right = x;
	else
		y->parent->left = x;

	x->right = y;
	y->parent = x;
}
