#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

//��Ұ��迡 ���� ������ �Ǽ� ����

template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
class PriorityQueue
{
public:
	void push(const T& data)
	{
		//�� �������� ������
		_heap.push_back(data);

		//�������
		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			//�θ� ����� �����Ϳ� ���ؼ� �������� ��
			int next = (now - 1) / 2;

			if (_predicate(_heap[now],_heap[next]))
				break;

			//������ ��ü
			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}
	
	void pop()
	{
		_heap[0] = _heap.back(); //�� �ڿ� ������ ������ ����
		_heap.pop_back(); //�� �ڿ����� ����

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			//������ ������ ���
			if (left >= (int)_heap.size())
			{
				break;
			}

			int next = now;

			//���ʰ� ��
			if (_predicate(_heap[next], _heap[left]))
			{
				next = left;
			}

			//���� ���ڸ� �����ʰ� ��
			if (right < (int)_heap.size() && _predicate(_heap[next], _heap[right]))
			{
				next = right;
			}

			//����/������ �Ѵ� ���簪���� ������ ����
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
	//���� ������� ������ �ϴ� ���
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