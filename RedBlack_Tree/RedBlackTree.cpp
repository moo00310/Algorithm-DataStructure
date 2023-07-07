#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "RBTree.h"

#include <thread>
using namespace std;

//이진 탐색 트리

int main()
{
	RBTree bst;
	bst.Insert(30);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(10);
	bst.Print();
	this_thread::sleep_for(1s);

	//bst.Print_Inorder();
}