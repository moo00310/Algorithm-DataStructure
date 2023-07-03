#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//대소관계에 의해 정렬이 되서 나옴

template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
class PriorityQueue
{
public:
	void push(const T& data)
	{
		//힙 구조부터 맞춰줌
		_heap.push_back(data);

		//도장깨기
		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			//부모 노드의 데이터와 비교해서 더작으면 끝
			int next = (now - 1) / 2;

			if (_predicate(_heap[now],_heap[next]))
				break;

			//데이터 교체
			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}
	
	void pop()
	{
		_heap[0] = _heap.back(); //맨 뒤에 내용을 앞으로 복사
		_heap.pop_back(); //맨 뒤에내용 제거

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			//리프에 도당한 경우
			if (left >= (int)_heap.size())
			{
				break;
			}

			int next = now;

			//왼쪽과 비교
			if (_predicate(_heap[next], _heap[left]))
			{
				next = left;
			}

			//둘중 승자를 오른쪽과 비교
			if (right < (int)_heap.size() && _predicate(_heap[next], _heap[right]))
			{
				next = right;
			}

			//왼쪽/오른쪽 둘다 현재값보다 작으면 종료
			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;

		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}

private:
	Container _heap = {};
	Predicate _predicate = {};
};

int main()
{
	//작은 순서대로 나오게 하는 방법
	//priority_queue<int, vector<int>, greater<int>> pq;
	PriorityQueue<int, vector<int>, greater<int>> pq;

	pq.push(100);
	pq.push(220);
	pq.push(333);
	pq.push(444);
	pq.push(555);

	while (pq.empty() == false)
	{
		int value = pq.top();
		pq.pop();

		cout << value << endl;
	}

}