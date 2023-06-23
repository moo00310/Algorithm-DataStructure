#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <deque>

using namespace std;

// Queue (FIFO ���Լ���)
// 
// front << [1][2][3][4] << rear(back)

template<typename T>
class ListQueue   // ����Ʈ ������� ����
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		//vector ��� ��
		//_container.erase(_container.begin()); //������ �����Ѵٰ� ���� x, (vector�� �����ϸ� ��ü�� ���� �ؾ��ϱ� ������) -> O(N)

		//list ��� ��
		_container.pop_front(); //list�� �������� -> O(1)
	}

	T& front()
	{
		return _container.front();
	}
	
	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	//vector<T> _container;
	list<T> _container;

	//deque<T> _container; -> ǥ�� Queue������ deque�� �⺻���� ����ϰ� �ִ�.
};


// [front / back][][][][][][][][]

// [front][][][][][][back][][][][]

// [][front][][][][][][back][][][]

// back�� ������ �Ѿ�� ��ȯ�Ѵ�.
// [][][back][][][][][front][][][]

template<typename T>
class ArrayQueue   // ��ȯ ������� ����
{
public:
	ArrayQueue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		//_size ����
		if (_size == _container.size()) 
		{
			int newSize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newSize);

			//������ ����
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value; //�� �ֱ�
		_back = (_back + 1) % _container.size(); //������ �������� ��������
		_size++;
	}

	void pop()
	{
		_front = (_front +1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	vector<T> _container;

	int _front = 0; //���������� �ε���
	int _back = 0; //�������� �ε���
	int _size = 0; //����� queue�� ũ��
};

int main()
{
	ArrayQueue<int> q;

	for (int i = 0; i < 100; i++)
		q.push(i);

	while (q.empty() == false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();

}