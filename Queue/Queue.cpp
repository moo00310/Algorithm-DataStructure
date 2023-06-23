#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <deque>

using namespace std;

// Queue (FIFO 선입선출)
// 
// front << [1][2][3][4] << rear(back)

template<typename T>
class ListQueue   // 리스트 방식으로 구현
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		//vector 사용 시
		//_container.erase(_container.begin()); //빠르게 동작한다고 보장 x, (vector는 수정하면 전체를 복사 해야하기 때문에) -> O(N)

		//list 사용 시
		_container.pop_front(); //list는 지원해줌 -> O(1)
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

	//deque<T> _container; -> 표준 Queue에서는 deque를 기본으로 사용하고 있다.
};


// [front / back][][][][][][][][]

// [front][][][][][][back][][][][]

// [][front][][][][][][back][][][]

// back이 범위를 넘어가면 순환한다.
// [][][back][][][][][front][][][]

template<typename T>
class ArrayQueue   // 순환 방식으로 구현
{
public:
	ArrayQueue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		//_size 증설
		if (_size == _container.size()) 
		{
			int newSize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newSize);

			//데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value; //값 넣기
		_back = (_back + 1) % _container.size(); //나머지 연산으로 범위제한
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

	int _front = 0; //시작지점의 인덱스
	int _back = 0; //끝지점의 인덱스
	int _size = 0; //사용할 queue의 크기
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