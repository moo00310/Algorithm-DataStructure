#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "BSTree.h"
using namespace std;

//이진 탐색 트리

int main()
{
	BSTree bst;
	bst.Insert(20);
	bst.Insert(10);
	bst.Insert(30);
	bst.Insert(40);
	bst.Insert(50);
	bst.Insert(25);
	bst.Insert(26);

	bst.Delete(20);
	bst.Delete(26); 
	bst.Delete(10);

	//bst.Print_Inorder();
	bst.Print();
}