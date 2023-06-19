#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Node //��� ����
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T()) //�⺻ ������ �ʱ�ȭ
	{

	}

	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

public:
	Node* _prev; //���� ��带 ����Ű�� ������
	Node* _next;
	T _data;

};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}
	Iterator(Node<T>* node) : _node(node)
	{

	}

	//++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//it++
	Iterator operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	//--it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	//it--
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	//it*
	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}
	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		//[head] <-> ...  <-> [tail]
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}
	~List()
	{
		while (_size > 0)
		{
			pop_back();
		}
		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}

	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

private:

	//[head] <-> [1] <-> [PrevNode]		  <->         [before] <-> [tail]
	//[head] <-> [1] <-> [PrevNode] <-> [NewNode] <-> [before] <-> [tail]

	Node<T>* AddNode(Node<T>* before, const T& value) //������ ��� �ٷ� ������ �߰�
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;
		return newNode;
	}

	//[head] <-> [PrevNode] <-> [node] <-> [nextNode] <-> [tail]
	//[head] <-> [PrevNode]		  <->	   [nextNode] <-> [tail]

	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	using iterator = Iterator<T>; //�빮�� ���ͷ����ͷ� �ν��ϰ�

	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size;

};




int main()
{
	List<int> li;

	//li[3] = 3;(x) �������� ����Ʈ�� ������

	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{

		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i); //li.end() ������ ����
		}
		else
		{
			li.push_back(i); //�ǵڿ� ����([tail(li.end)] ��� �տ� ����)
		}

	}

	li.pop_back(); //�ǵڿ� ���� ����([tail(li.end)] ��� �տ� ����)

	li.erase(eraseIt); //�߰� ���� ����

	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}
}